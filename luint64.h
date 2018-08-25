#ifndef LUINT64_H
#define LUINT64_H
int uint64_decoder(lua_State *L);
int uint64_encoder(lua_State *L);
int uint64_size(lua_State *L);
int luaopen_uint64(lua_State *L);
#endif