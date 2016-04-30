#include <iostream>
#include "LuaState.h"


int func(lua_State* L)
{
    double ratio = lua_tonumber(L, 1);
    if(ratio >=1 )
    {
        lua_pushinteger(L, 400*ratio);
        lua_pushinteger(L, 400);
    }
    else
    {
        lua_pushinteger(L, 400);
        lua_pushinteger(L, 400/ratio);
    }


    return 2;
}

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

    float ratio = 1;
    std::cin >> ratio;

    lua_register(Lua(), "func", &func);
    luaL_dofile(Lua(), "test.lua");
    lua_getglobal(Lua(), "hello");
    lua_pushnumber(Lua(), ratio);
    lua_pcall(Lua(), 1, 2, 0);

    auto width = lua_tointeger(Lua(), -1);
    auto height = lua_tointeger(Lua(), -2);
    std::cout << width << 'x' << height << std::endl;

	return 0;
}
