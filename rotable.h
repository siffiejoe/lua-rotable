#ifndef ROTABLE_H_
#define ROTABLE_H_

#include <lua.h>

/* exactly the same as luaL_Reg, but since we are on small embedded
 * microcontrollers, we don't assume that you have `lauxlib.h`
 * available in your build! */
typedef struct rotable_Reg {
  char const* name;
  lua_CFunction func;
} rotable_Reg;

#ifndef ROTABLE_EXPORT
#  define ROTABLE_EXPORT extern
#endif

/* compatible with `luaL_newlib()`, and works with `luaL_Reg` *and*
 * `rotable_Reg` arrays (in case you don't use `lauxlib.h`) */
ROTABLE_EXPORT void rotable_newlib( lua_State* L, void const* reg );

#endif /* ROTABLE_H_ */

