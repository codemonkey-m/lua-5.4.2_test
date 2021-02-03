// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

using namespace std;

static void dump(lua_State* L)
{
	int i = 0, type = 0, size = lua_gettop(L);
	printf("当前堆栈有%d个元素: \n", size);
	for (i = 1; i <= size; i++) {
		type = lua_type(L, i);
		printf("\t元素%d类型为: %s\t", i, lua_typename(L, type));
		switch (type) {
		case LUA_TSTRING:
			printf("'%s'", lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN:
			printf(lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TNUMBER:
			printf("%g", lua_tonumber(L, i));
			break;
		case LUA_TFUNCTION:
			lua_Debug ar;
			memset(&ar, 0, sizeof(ar));
			lua_getstack(L, 0, &ar);
			if (ar.i_ci)
				lua_getinfo(L, "Snl", &ar);
			printf("%s\t%s", ar.short_src, (ar.name ? ar.name : "<nil>"));
			break;
		default:
			break;
		}
		printf("\n");
	}
	printf("\n");
	return;
}

static int bail(lua_State* L)
{
	printf("加载文件错误:\n\t%s\n", lua_tostring(L, -1));
	return 0;
}

int call_err(lua_State* L)
{
	lua_Debug ar;
	int idx = 0;
	printf("执行[%s]错误: %s\n", "lua_t", lua_tostring(L, -1));
	while (lua_getstack(L, idx, &ar)) {
		if (ar.i_ci)
			lua_getinfo(L, "Snl", &ar);
		printf("\t [%s]: %s func:%s\n", ar.what, ar.namewhat, (ar.name ? ar.name : "<nil>"));
		idx++;
	}

	return 1;
}

int print_from_lua(lua_State* L) {
	cout << "来自lua的输出 " << lua_tostring(L, -1) << endl;
	return 0;
}

int main()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

	lua_pushcfunction(L, print_from_lua);
	lua_setglobal(L, "lua_print");

	lua_pushcfunction(L, call_err);

	if (luaL_dofile(L, "script\\test0.lua"))
		bail(L);

	dump(L);

	lua_getglobal(L, "lua_t");
	lua_pushstring(L, "汉字");
	lua_pcall(L, 1, 1, -3);

	cout << "来自lua的返回 " << lua_tonumber(L, -1) << endl;

	lua_close(L);

	system("pause");
	return 0;
}