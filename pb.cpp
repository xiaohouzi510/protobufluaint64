/*
 * =====================================================================================
 *
 *      Filename:  pb.c
 *
 *      Description: protoc-gen-lua
 *      Google's Protocol Buffers project, ported to lua.
 *      https://code.google.com/p/protoc-gen-lua/
 *
 *      Copyright (c) 2010 , 林卓毅 (Zhuoyi Lin) netsnail@gmail.com
 *      All rights reserved.
 *
 *      Use, modification and distribution are subject to the "New BSD License"
 *      as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.
 *
 *      Created:  2010年08月02日 18时04分21秒
 *
 *      Company:  NetEase
 *
 * =====================================================================================
 */
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#ifdef _ALLBSD_SOURCE
#include <machine/endian.h>
#else
#include <endian.h>
#endif

#if __BYTE_ORDER == __LITTLE_ENDIAN
#define IS_LITTLE_ENDIAN
#endif

#define IOSTRING_META "protobuf.IOString"

#define checkiostring(L) \
    (IOString*) luaL_checkudata(L, 1, IOSTRING_META)

#define IOSTRING_BUF_LEN 65535

    typedef struct{
        size_t size;
        char buf[IOSTRING_BUF_LEN];
    } IOString;

    static void pack_varint(luaL_Buffer *b, uint64_t value)
    {
        if (value >= 0x80)
        {
            luaL_addchar(b, value | 0x80);
            value >>= 7;
            if (value >= 0x80)
            {
                luaL_addchar(b, value | 0x80);
                value >>= 7;
                if (value >= 0x80)
                {
                    luaL_addchar(b, value | 0x80);
                    value >>= 7;
                    if (value >= 0x80)
                    {
                        luaL_addchar(b, value | 0x80);
                        value >>= 7;
                        if (value >= 0x80)
                        {
                            luaL_addchar(b, value | 0x80);
                            value >>= 7;
                            if (value >= 0x80)
                            {
                                luaL_addchar(b, value | 0x80);
                                value >>= 7;
                                if (value >= 0x80)
                                {
                                    luaL_addchar(b, value | 0x80);
                                    value >>= 7;
                                    if (value >= 0x80)
                                    {
                                        luaL_addchar(b, value | 0x80);
                                        value >>= 7;
                                        if (value >= 0x80)
                                        {
                                            luaL_addchar(b, value | 0x80);
                                            value >>= 7;
                                        } 
                                    } 
                                } 
                            } 
                        } 
                    } 
                } 
            } 
        }
        luaL_addchar(b, value);
    } 

    static int varint_encoder(lua_State *L)
    {
        lua_Number l_value = luaL_checknumber(L, 2);
        uint64_t value = (uint64_t)l_value;

        luaL_Buffer b;
        luaL_buffinit(L, &b);

        pack_varint(&b, value);

        lua_settop(L, 1);
        luaL_pushresult(&b);
        lua_call(L, 1, 0);
        return 0;
    }

    static int signed_varint_encoder(lua_State *L)
    {
        lua_Number l_value = luaL_checknumber(L, 2);
        int64_t value = (int64_t)l_value;

        luaL_Buffer b;
        luaL_buffinit(L, &b);

        if (value < 0)
        {
            pack_varint(&b, *(uint64_t*)&value);
        }else{
            pack_varint(&b, value);
        }

        lua_settop(L, 1);
        luaL_pushresult(&b);
        lua_call(L, 1, 0);
        return 0;
    }

    static int int64_encoder(lua_State *L)
    {
        uintptr_t l_value = (uintptr_t)luaL_checkudata(L,2,"__int64");
        int64_t value = (int64_t)l_value;

        luaL_Buffer b;
        luaL_buffinit(L, &b);

        if (value < 0)
        {
            pack_varint(&b, *(uint64_t*)&value);
        }else{
            pack_varint(&b, value);
        }

        lua_settop(L, 1);
        luaL_pushresult(&b);
        lua_call(L, 1, 0);
        return 0;
    }

    static int int64_size_help(int64_t value)
    {
        if(value < 0) return 10;
        if(value <= 0x7f) return 1;
        if(value <= 0x3fff) return 2;
        if(value <= 0x1fffff) return 3;
        if(value <= 0xfffffff) return 4;
        if(value <= 0x7ffffffff) return 5;
        if(value <= 0x3ffffffffff) return 6;
        if(value <= 0x1ffffffffffff) return 7;
        if(value <= 0xffffffffffffff) return 8;
        if(value <= 0x7fffffffffffffff) return 9;
        return 0;
    }

    static int int64_size(lua_State *L)
    {
        uintptr_t l_value = (uintptr_t)luaL_checkudata(L,2,"__int64");
        int size = int64_size_help((int64_t)l_value);
        lua_pushinteger(L,size);
        return 1;
    }

    static int pack_fixed32(lua_State *L, uint8_t* value){
#ifdef IS_LITTLE_ENDIAN
        lua_pushlstring(L, (char*)value, 4);
#else
        uint32_t v = htole32(*(uint32_t*)value);
        lua_pushlstring(L, (char*)&v, 4);
#endif
        return 0;
    }

    static int pack_fixed64(lua_State *L, uint8_t* value){
#ifdef IS_LITTLE_ENDIAN
        lua_pushlstring(L, (char*)value, 8);
#else
        uint64_t v = htole64(*(uint64_t*)value);
        lua_pushlstring(L, (char*)&v, 8);
#endif
        return 0;
    }

    static int struct_pack(lua_State *L)
    {
        uint8_t format = luaL_checkinteger(L, 2);
        lua_Number value = luaL_checknumber(L, 3);
        lua_settop(L, 1);

        switch(format){
            case 'i':
                {
                    int32_t v = (int32_t)value;
                    pack_fixed32(L, (uint8_t*)&v);
                    break;
                }
            case 'q':
                {
                    int64_t v = (int64_t)value;
                    pack_fixed64(L, (uint8_t*)&v);
                    break;
                }
            case 'f':
                {
                    float v = (float)value;
                    pack_fixed32(L, (uint8_t*)&v);
                    break;
                }
            case 'd':
                {
                    double v = (double)value;
                    pack_fixed64(L, (uint8_t*)&v);
                    break;
                }
            case 'I':
                {
                    uint32_t v = (uint32_t)value;
                    pack_fixed32(L, (uint8_t*)&v);
                    break;
                }
            case 'Q':
                {
                    uint64_t v = (uint64_t) value;
                    pack_fixed64(L, (uint8_t*)&v);
                    break;
                }
            default:
                luaL_error(L, "Unknown, format");
        }
        lua_call(L, 1, 0);
        return 0;
    }

    static size_t size_varint(const char* buffer, size_t len)
    {
        size_t pos = 0;
        while(buffer[pos] & 0x80){
            ++pos;
            if(pos > len){
                return -1;
            }
        }
        return pos+1;
    }

    static uint64_t unpack_varint(const char* buffer, size_t len)
    {
        uint64_t value = buffer[0] & 0x7f;
        size_t shift = 7;
        size_t pos=0;
        for(pos = 1; pos < len; ++pos)
        {
            value |= ((uint64_t)(buffer[pos] & 0x7f)) << shift;
            shift += 7;
        }
        return value;
    }

    static int varint_decoder(lua_State *L)
    {
        size_t len;
        const char* buffer = luaL_checklstring(L, 1, &len);
        size_t pos = luaL_checkinteger(L, 2);

        buffer += pos;
        len = size_varint(buffer, len);
        if(len == -1){
            luaL_error(L, "error data %s, len:%d", buffer, len);
        }else{
            lua_pushnumber(L, (lua_Number)unpack_varint(buffer, len));
            lua_pushinteger(L, len + pos);
        }
        return 2;
    }

    static int signed_varint_decoder(lua_State *L)
    {
        size_t len;
        const char* buffer = luaL_checklstring(L, 1, &len);
        size_t pos = luaL_checkinteger(L, 2);
        buffer += pos;
        len = size_varint(buffer, len);

        if(len == -1){
            luaL_error(L, "error data %s, len:%d", buffer, len);
        }else{
            lua_pushnumber(L, (lua_Number)(int64_t)unpack_varint(buffer, len));
            lua_pushinteger(L, len + pos);
        }
        return 2;
    }

    static int zig_zag_encode32(lua_State *L)
    {
        int32_t n = luaL_checkinteger(L, 1);
        uint32_t value = (n << 1) ^ (n >> 31);
        lua_pushinteger(L, value);
        return 1;
    }

    static int zig_zag_decode32(lua_State *L)
    {
        uint32_t n = (uint32_t)luaL_checkinteger(L, 1);
        int32_t value = (n >> 1) ^ - (int32_t)(n & 1);
        lua_pushinteger(L, value);
        return 1;
    }

    static int zig_zag_encode64(lua_State *L)
    {
        int64_t n = (int64_t)luaL_checknumber(L, 1);
        uint64_t value = (n << 1) ^ (n >> 63);
        lua_pushinteger(L, value);
        return 1;
    }

    static int zig_zag_decode64(lua_State *L)
    {
        uint64_t n = (uint64_t)luaL_checknumber(L, 1);
        int64_t value = (n >> 1) ^ - (int64_t)(n & 1);
        lua_pushinteger(L, value);
        return 1;
    }

    static int read_tag(lua_State *L)
    {
        size_t len;
        const char* buffer = luaL_checklstring(L, 1, &len);
        size_t pos = luaL_checkinteger(L, 2);

        buffer += pos;
        len = size_varint(buffer, len);
        if(len == -1){
            luaL_error(L, "error data %s, len:%d", buffer, len);
        }else{
            lua_pushlstring(L, buffer, len);
            lua_pushinteger(L, len + pos);
        }
        return 2;
    }

    static const uint8_t* unpack_fixed32(const uint8_t* buffer, uint8_t* cache)
    {
#ifdef IS_LITTLE_ENDIAN
        return buffer;
#else
        *(uint32_t*)cache = le32toh(*(uint32_t*)buffer);
        return cache;
#endif
    }

    static const uint8_t* unpack_fixed64(const uint8_t* buffer, uint8_t* cache)
    {
#ifdef IS_LITTLE_ENDIAN
        return buffer;
#else
        *(uint64_t*)cache = le64toh(*(uint64_t*)buffer);
        return cache;
#endif
    }

    static int struct_unpack(lua_State *L)
    {
        uint8_t format = luaL_checkinteger(L, 1);
        size_t len;
        const uint8_t* buffer = (uint8_t*)luaL_checklstring(L, 2, &len);
        size_t pos = luaL_checkinteger(L, 3);

        buffer += pos;
        uint8_t out[8];
        switch(format){
            case 'i':
                {
                    lua_pushinteger(L, *(int32_t*)unpack_fixed32(buffer, out));
                    break;
                }
            case 'q':
                {
                    lua_pushnumber(L, (lua_Number)*(int64_t*)unpack_fixed64(buffer, out));
                    break;
                }
            case 'f':
                {
                    lua_pushnumber(L, (lua_Number)*(float*)unpack_fixed32(buffer, out));
                    break;
                }
            case 'd':
                {
                    lua_pushnumber(L, (lua_Number)*(double*)unpack_fixed64(buffer, out));
                    break;
                }
            case 'I':
                {
                    lua_pushnumber(L, *(uint32_t*)unpack_fixed32(buffer, out));
                    break;
                }
            case 'Q':
                {
                    lua_pushnumber(L, (lua_Number)*(uint64_t*)unpack_fixed64(buffer, out));
                    break;
                }
            default:
                luaL_error(L, "Unknown, format");
        }
        return 1;
    }

    static int iostring_new(lua_State* L)
    {
        IOString* io = (IOString*)lua_newuserdata(L, sizeof(IOString));
        io->size = 0;

        luaL_getmetatable(L, IOSTRING_META);
        lua_setmetatable(L, -2); 
        return 1;
    }

    static int iostring_str(lua_State* L)
    {
        IOString *io = checkiostring(L);
        lua_pushlstring(L, io->buf, io->size);
        return 1;
    }

    static int iostring_len(lua_State* L)
    {
        IOString *io = checkiostring(L);
        lua_pushinteger(L, io->size);
        return 1;
    }

    static int iostring_write(lua_State* L)
    {
        IOString *io = checkiostring(L);
        size_t size;
        const char* str = luaL_checklstring(L, 2, &size);
        if(io->size + size > IOSTRING_BUF_LEN){
            luaL_error(L, "Out of range");
        }
        memcpy(io->buf + io->size, str, size);
        io->size += size;
        return 0;
    }

    static int iostring_sub(lua_State* L)
    {
        IOString *io = checkiostring(L);
        size_t begin = luaL_checkinteger(L, 2);
        size_t end = luaL_checkinteger(L, 3);

        if(begin > end || end > io->size)
        {
            luaL_error(L, "Out of range");
        }
        lua_pushlstring(L, io->buf + begin - 1, end - begin + 1);
        return 1;
    }

    static int iostring_clear(lua_State* L)
    {
        IOString *io = checkiostring(L);
        io->size = 0; 
        return 0;
    }

    static int64_t
    _int64(lua_State *L, int index) {
        int type = lua_type(L,index);
        int64_t n = 0;
        switch(type) {
        case LUA_TNUMBER: {
            lua_Number d = lua_tonumber(L,index);
            n = (int64_t)d;
            break;
        }
        case LUA_TSTRING: {
            size_t len = 0;
            const char* str = (const char *)lua_tolstring(L, index, &len);
            n = atoll(str);
            break;
        }
        case LUA_TLIGHTUSERDATA: {
            void * p = lua_touserdata(L,index);
            n = (intptr_t)p;
            break;
        }
        default:
            return luaL_error(L, "argument %d error type %s", index, lua_typename(L,type));
        }
        return n;
    }

    static inline void
    _pushint64(lua_State *L, int64_t n) {
        void * p = (void *)(intptr_t)n;
        lua_pushlightuserdata(L,p);
    }

    static int
    int64_add(lua_State *L) {
        int64_t a = _int64(L,1);
        int64_t b = _int64(L,2);
        _pushint64(L, a+b);
        
        return 1;
    }

    static int
    int64_sub(lua_State *L) {
        int64_t a = _int64(L,1);
        int64_t b = _int64(L,2);
        _pushint64(L, a-b);
        
        return 1;
    }

    static int
    int64_mul(lua_State *L) {
        int64_t a = _int64(L,1);
        int64_t b = _int64(L,2);
        _pushint64(L, a * b);
        
        return 1;
    }

    static int
    int64_div(lua_State *L) {
        int64_t a = _int64(L,1);
        int64_t b = _int64(L,2);
        if (b == 0) {
            return luaL_error(L, "div by zero");
        }
        _pushint64(L, a / b);
        
        return 1;
    }

    static int
    int64_mod(lua_State *L) {
        int64_t a = _int64(L,1);
        int64_t b = _int64(L,2);
        if (b == 0) {
            return luaL_error(L, "mod by zero");
        }
        _pushint64(L, a % b);
        
        return 1;
    }

    static int64_t
    _pow64(int64_t a, int64_t b) {
        if (b == 1) {
            return a;
        }
        int64_t a2 = a * a;
        if (b % 2 == 1) {
            return _pow64(a2, b/2) * a;
        } else {
            return _pow64(a2, b/2);
        }
    }

    static int
    int64_pow(lua_State *L) {
        int64_t a = _int64(L,1);
        int64_t b = _int64(L,2);
        int64_t p;
        if (b > 0) {
            p = _pow64(a,b);
        } else if (b == 0) {
            p = 1;
        } else {
            return luaL_error(L, "pow by nagtive number %d",(int)b);
        } 
        _pushint64(L, p);

        return 1;
    }

    static int
    int64_unm(lua_State *L) {
        int64_t a = _int64(L,1);
        _pushint64(L, -a);
        return 1;
    }

    static int
    int64_new(lua_State *L) {
        int top = lua_gettop(L);
        int64_t n;
        switch(top) {
            case 0 : 
                lua_pushlightuserdata(L,NULL);
                break;
            case 1 :
                n = _int64(L,1);
                _pushint64(L,n);
                break;
            default: {
                int base = luaL_checkinteger(L,2);
                if (base < 2) {
                    luaL_error(L, "base must be >= 2");
                }
                const char * str = luaL_checkstring(L, 1);
                n = strtoll(str, NULL, base);
                _pushint64(L,n);
                break;
            }
        }
        luaL_getmetatable(L,"__int64");
        lua_setmetatable(L,-2);
        return 1;
    }

    static int
    int64_eq(lua_State *L) {
        int64_t a = _int64(L,1);
        int64_t b = _int64(L,2);
        lua_pushboolean(L,a == b);
        return 1;
    }

    static int
    int64_lt(lua_State *L) {
        int64_t a = _int64(L,1);
        int64_t b = _int64(L,2);
        lua_pushboolean(L,a < b);
        return 1;
    }

    static int
    int64_le(lua_State *L) {
        int64_t a = _int64(L,1);
        int64_t b = _int64(L,2);
        lua_pushboolean(L,a <= b);
        return 1;
    }

    static int
    int64_len(lua_State *L) {
        int64_t a = _int64(L,1);
        lua_pushnumber(L,(lua_Number)a);
        return 1;
    }

    static int
    tostring(lua_State *L) {
        uintptr_t n = (uintptr_t)lua_touserdata(L,1);
        int64_t v = (int64_t)n;
        char szTemp[64] = {0};
        sprintf(szTemp,"%ld",v);
        lua_pushstring(L,szTemp);
        return 1;
    }

    static void
    make_mt(lua_State *L) {
        luaL_newmetatable(L,"__int64");
        luaL_Reg lib[] = {
            { "__add", int64_add },
            { "__sub", int64_sub },
            { "__mul", int64_mul },
            { "__div", int64_div },
            { "__mod", int64_mod },
            { "__unm", int64_unm },
            { "__pow", int64_pow },
            { "__eq", int64_eq },
            { "__lt", int64_lt },
            { "__le", int64_le },
            { "__len", int64_len },
            { "__tostring", tostring },
            { NULL, NULL },
        };
        luaL_register(L,NULL,lib);
        lua_pop(L,1);
    }
    static const struct luaL_reg int64_reg [] = {
            {"new", int64_new},
            {"tostring", tostring},
            {NULL, NULL},
        };
    int
    luaopen_int64(lua_State *L) {
        if (sizeof(intptr_t)!=sizeof(int64_t)) {
            return luaL_error(L, "Only support 64bit architecture");
        }
        make_mt(L);
        lua_newtable(L);
        luaL_register(L,"int64",int64_reg);
        lua_pop(L,1);
        return 1;
    }

    static int int64_decoder(lua_State *L)
    {
        size_t len;
        const char* buffer = luaL_checklstring(L, 1, &len);
        size_t pos = luaL_checkinteger(L, 2);
        buffer += pos;
        len = size_varint(buffer, len);

        if(len == -1){
            luaL_error(L, "error data %s, len:%d", buffer, len);
        }else{
            _pushint64(L,(int64_t)unpack_varint(buffer, len));
            luaL_getmetatable(L,"__int64");
            lua_setmetatable(L,-2);
            lua_pushinteger(L, len + pos);
        }
        return 2;
    }

    static const struct luaL_reg _pb [] = {
        {"varint_encoder", varint_encoder},
        {"signed_varint_encoder", signed_varint_encoder},
        {"int64_encoder",int64_encoder},
        {"int64_decoder",int64_decoder},
        {"int64_size",int64_size},
        {"read_tag", read_tag},
        {"struct_pack", struct_pack},
        {"struct_unpack", struct_unpack},
        {"varint_decoder", varint_decoder},
        {"signed_varint_decoder", signed_varint_decoder},
        {"zig_zag_decode32", zig_zag_decode32},
        {"zig_zag_encode32", zig_zag_encode32},
        {"zig_zag_decode64", zig_zag_decode64},
        {"zig_zag_encode64", zig_zag_encode64},
        {"new_iostring", iostring_new},
        {NULL, NULL}
    };

    static const struct luaL_reg _c_iostring_m [] = {
        {"__tostring", iostring_str},
        {"__len", iostring_len},
        {"write", iostring_write},
        {"sub", iostring_sub},
        {"clear", iostring_clear},
        {NULL, NULL}
    };

    int luaopen_pb (lua_State *L)
    {
        // luaopen_int64(L);
        luaL_newmetatable(L, IOSTRING_META);
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "__index");
        luaL_register(L, NULL, _c_iostring_m);

        luaL_register(L, "pb", _pb);
        return 1;
    }
}

