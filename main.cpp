#include "lua.hpp"
#include <iostream>



int main()
{
	lua_State *L = luaL_newstate();

	static const luaL_Reg lualibs[] = {
		{ "base", luaopen_base},
		{ NULL, NULL}
	};

	const luaL_Reg *libs = lualibs;
	for (; libs->func != NULL; libs++)
	{
		libs->func(L);
		lua_settop(L, 0);
	}

	luaL_dofile(L, "test.lua");

	lua_getglobal(L, "var");
	auto var = lua_tonumber(L, -1);
	std::cout << var << std::endl;

	lua_close(L);
	return 0;
}
