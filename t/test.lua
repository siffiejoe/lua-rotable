#!/usr/bin/env lua

local mod1 = require( "mod1" )
local obj1 = require( "mod1.idx" )
local mod2 = require( "mod2" )
local obj2 = require( "mod2.idx" )

mod1.func1()
mod1.func2()
mod1.func3()
mod1.func4()

mod2.gunc1()
mod2.gunc2()
mod2.gunc3()
mod2.gunc4()

obj1.func1()
obj1.func2()
obj2.gunc3()
obj2.gunc4()

print( mod1, #mod1 )
if not _VERSION:match( "5%.1$" ) then
  for k,v in pairs( mod1 ) do
    print( k, v )
  end
end
print( mod2, #mod2 )
if not _VERSION:match( "5%.1$" ) then
  for k, v in pairs( mod2 ) do
    print( k, v )
  end
  local f, t, s = pairs( mod2 )
  print( pcall( f, io.stdout ) )
end

