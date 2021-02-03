local _M = require "script\\test1"

function const_test()
	--这个const仅针对const_tab表,而对表内的元素无效
	local const_tab<const> = {
		a = 1,
		b = 2,
		--c<const> = 3, --这样不行
	}
	--const_tab.c<const> = 3 --这样也不行

	--const_tab = {}   --这个会被禁止修改
	const_tab.a = 6
	const_tab.b = 99
	const_tab.c = 777

	print(const_tab.b)
end


function lua_t(str)
	_M.err()

	print("lua输出 " .. str)
	lua_print(str)

	const_test()

	--nil? undef?
	local u
	print(u, x)

	return 12369
end
