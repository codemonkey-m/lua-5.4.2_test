local _M = require "script\\test1"

function FFF( ... )
	local a = 1
	a = a + a
end

tab = {
	a = 1,
	b = 2,
}

function lua_t(str)
	--test(str)
	--test('����')

	_M.err()

	print("lua��� " .. str)
	lua_print(str)

	return 12369
end
