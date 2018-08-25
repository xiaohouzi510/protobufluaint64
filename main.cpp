#include <stdio.h>
#include <stdint.h>
extern "C" 
{
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
	int iPvpType      = rand()%2147483647;
    int iHardType     = rand()%2147483647;
	SSInt64Test stProto;
	stProto.set_pvptype(iPvpType);
	stProto.set_hardtype(iHardType);
	//添加 teamids
	stProto.set_teamid(4611686018427387903);
	stProto.add_teamids(9223372036854775807);
	stProto.add_teamids(-9223372036854775807);

	stProto.set_roleid(4611686018427387903);
	stProto.add_roleids(18446744073709551614);
	stProto.add_roleids(9223372036854775807);

	TestData* pData = stProto.add_datas();
	pData->set_selfid(-2305843009213693951);
	pData->set_otherid(3074457345618258602);

	pData = stProto.add_datas();
	pData->set_selfid(1152921504606846975);
	pData->set_otherid(2305843009213693950);

	string sStr;
	stProto.SerializeToString(&sStr);
	lua_pushlstring(L,sStr.c_str(),stProto.ByteSize());
	printf("------------------------------\n");
	printf("%s\n",stProto.DebugString().c_str());
	if(lua_pcall(L,1,0,0) != 0)
	{
		printf("lua call error %s\n",lua_tostring(L,-1));
		lua_close(L);
		return 0;
	}

	lua_close(L);

	return 0;
}