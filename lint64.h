#ifndef LINT64_H
#define LINT64_H
int int64_decoder(lua_State *L);
int int64_encoder(lua_State *L);
int int64_size(lua_State *L);
int luaopen_int64(lua_State *L);
#endif