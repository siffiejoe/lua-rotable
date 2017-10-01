#include <stdio.h>
#include <lua.h>
#include "rotable.h"


static int func1( lua_State* L ) {
  (void)L;
  printf( "gunc1()\n" );
  return 0;
}

static int func2( lua_State* L ) {
  (void)L;
  printf( "gunc2()\n" );
  return 0;
}

static int func3( lua_State* L ) {
  (void)L;
  printf( "gunc3()\n" );
  return 0;
}

static int func4( lua_State* L ) {
  (void)L;
  printf( "gunc4()\n" );
  return 0;
}

static rotable_Reg const funcs[] = {
  { "gunc3", func3 },
  { "gunc2", func2 },
  { "gunc1", func1 },
  { "gunc4", func4 },
  { 0, 0 },
};


int luaopen_mod2( lua_State* L ) {
  rotable_newlib( L, funcs );
  return 1;
}


