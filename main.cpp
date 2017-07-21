#include <stdio.h>
#include <stdint.h>
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
#include <string.h>
#include <stdlib.h>
#include "test.pb.h"

using namespace std;

int main(int argc,char *argv[])
{
	if(argc < 1)
	{
		printf("param must be teamID\n");
		return 0;
	}
	lua_State *L = luaL_newstate();
	if(L == NULL)
	{
		printf("create luastate error\n");
		return 0;
	}

	luaL_openlibs(L);
	const char *filename = "test.lua";
	if(luaL_loadfile(L,filename) != 0)
	{
		printf("lua load file %s error %s\n",filename,lua_tostring(L,-1));
		lua_close(L);
		return 0;
	}
	srand(time(NULL));
	int iPvpType     = rand()%2147483647;
    int64_t llTeamID = atoll(argv[1]);
    int iHardType    = rand()%2147483647;
	SSInt64Test stProto;
	stProto.set_pvptype(iPvpType);
	stProto.set_teamid(llTeamID);
	stProto.set_hardtype(iHardType);
	string sStr;
	stProto.SerializeToString(&sStr);
	lua_pushlstring(L,sStr.c_str(),stProto.ByteSize());
	// printf("%s\n",stProto.DebugString().c_str());
	if(lua_pcall(L,1,0,0) != 0)
	{
		printf("lua call error %s\n",lua_tostring(L,-1));
		lua_close(L);
		return 0;
	}

	lua_close(L);

	return 0;
}