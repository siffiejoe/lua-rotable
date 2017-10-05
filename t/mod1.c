#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include "rotable.h"


static int func1( lua_State* L ) {
  (void)L;
  printf( "func1()\n" );
  return 0;
}

static int func2( lua_State* L ) {
  (void)L;
  printf( "func2()\n" );
  return 0;
}

static int func3( lua_State* L ) {
  (void)L;
  printf( "func3()\n" );
  return 0;
}

static int func4( lua_State* L ) {
  (void)L;
  printf( "func4()\n" );
  return 0;
}

static luaL_Reg const funcs[] = {
  { "func1", func1 },
  { "func2", func2 },
  { "func3", func3 },
  { "func4", func4 },
  { "func5", func4 },
  { "func6", func4 },
  { 0, 0 },
};


int luaopen_mod1( lua_State* L ) {
  rotable_newlib( L, funcs );
  return 1;
}


int luaopen_mod1_idx( lua_State* L ) {
  lua_newtable( L );
  lua_newtable( L );
  rotable_newidx( L, funcs );
  lua_setfield( L, -2, "__index" );
  lua_setmetatable( L, -2 );
  return 1;
}


