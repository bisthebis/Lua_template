PROJECT(lua_project)
 
set(CMAKE_CXX_STANDARD 14)

#what files are needed?
SET(MYLUA_SRCS
    main.cpp
    LuaState.cpp
    test.lua
)
# Add executable called myLua
ADD_EXECUTABLE( lua_project ${MYLUA_SRCS})
 
# indicate how to link
TARGET_LINK_LIBRARIES(lua_project lua)
