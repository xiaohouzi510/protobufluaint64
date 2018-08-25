extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include "lint64.h"
static int64_t _int64(lua_State *L, int index) {
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
    case LUA_TUSERDATA: {
        int64_t * p = (int64_t*)lua_touserdata(L,index);
        n = *p;
        break;
    }
    default:
        return luaL_error(L, "argument %d error type %s", index, lua_typename(L,type));
    }
    return n;
}

static inline void _pushint64(lua_State *L, int64_t n) {
    int64_t *p = (int64_t *)lua_newuserdata(L,sizeof(int64_t));
    *p = n;
}

static int int64_add(lua_State *L) {
    int64_t a = _int64(L,1);
    int64_t b = _int64(L,2);
    _pushint64(L, a+b);
    
    return 1;
}

static int int64_sub(lua_State *L) {
    int64_t a = _int64(L,1);
    int64_t b = _int64(L,2);
    _pushint64(L, a-b);
    
    return 1;
}

static int int64_mul(lua_State *L) {
    int64_t a = _int64(L,1);
    int64_t b = _int64(L,2);
    _pushint64(L, a * b);
    
    return 1;
}

static int int64_div(lua_State *L) {
    int64_t a = _int64(L,1);
    int64_t b = _int64(L,2);
    if (b == 0) {
        return luaL_error(L, "div by zero");
    }
    _pushint64(L, a / b);
    
    return 1;
}

static int int64_mod(lua_State *L) {
    int64_t a = _int64(L,1);
    int64_t b = _int64(L,2);
    if (b == 0) {
        return luaL_error(L, "mod by zero");
    }
    _pushint64(L, a % b);
    
    return 1;
}

static int64_t _pow64(int64_t a, int64_t b) {
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

static int int64_pow(lua_State *L) {
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

static int int64_unm(lua_State *L) {
    int64_t a = _int64(L,1);
    _pushint64(L, -a);
    return 1;
}

static int int64_new(lua_State *L) {
    int top = lua_gettop(L);
    int64_t n;
    switch(top) {
        case 0 : 
            _pushint64(L,0);
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

static int int64_eq(lua_State *L) {
    int64_t a = _int64(L,1);
    int64_t b = _int64(L,2);
    lua_pushboolean(L,a == b);
    return 1;
}

static int int64_lt(lua_State *L) {
    int64_t a = _int64(L,1);
    int64_t b = _int64(L,2);
    lua_pushboolean(L,a < b);
    return 1;
}

static int int64_le(lua_State *L) {
    int64_t a = _int64(L,1);
    int64_t b = _int64(L,2);
    lua_pushboolean(L,a <= b);
    return 1;
}

static int int64_len(lua_State *L) {
    int64_t a = _int64(L,1);
    lua_pushnumber(L,(lua_Number)a);
    return 1;
}

static int tostring(lua_State *L) {
    int64_t v = _int64(L,1);
    char szTemp[64] = {0};
    sprintf(szTemp,"%ld",v);
    lua_pushstring(L,szTemp);
    return 1;
}

static void make_mt(lua_State *L) {
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
}

size_t size_varint(const char* buffer, size_t len);
uint64_t unpack_varint(const char* buffer, size_t len);
void pack_varint(luaL_Buffer *b, uint64_t value);

int int64_decoder(lua_State *L)
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

int int64_encoder(lua_State *L)
{
    int64_t value = *(int64_t*)luaL_checkudata(L,2,"__int64");

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
    return 10;
}

int int64_size(lua_State *L)
{
    int64_t l_value = *(int64_t*)luaL_checkudata(L,1,"__int64");
    int size = int64_size_help((int64_t)l_value);
    lua_pushinteger(L,size);
    return 1;
}

static const struct luaL_reg int64_reg [] = {
    {"new", int64_new},
    {"tostring", tostring},
    {NULL, NULL},
};

int luaopen_int64(lua_State *L) {
    if (sizeof(intptr_t)!=sizeof(int64_t)) {
        return luaL_error(L, "Only support 64bit architecture");
    }
    make_mt(L);
    lua_newtable(L);
    luaL_register(L,"int64",int64_reg);
    return 1;
}
}