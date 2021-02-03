_M = {
	err = function()
		local a = 5
		a = a + a
		lua_print("test1.lua")
	end,

	val = 1,
}

return _M