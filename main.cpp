#include <iostream>
#include "LuaState.h"



int main()
{

    LuaState Lua;

	static const luaL_Reg lualibs[] = {
		{ "base", luaopen_base},
		{ NULL, NULL}
	};

	const luaL_Reg *libs = lualibs;
	for (; libs->func != NULL; libs++)
	{
        libs->func(Lua());
        lua_settop(Lua(), 0);
	}

    luaL_dofile(Lua(), "test.lua");

    lua_getglobal(Lua(), "width");
    auto width = lua_tonumber(Lua(), -1);
    lua_getglobal(Lua(), "height");
    auto height = lua_tonumber(Lua(), -1);
    std::cout << width << 'x' << height << std::endl;

	return 0;
}
