local _M = require "script\\test1"

function const_test()
	--���const�����const_tab��,���Ա��ڵ�Ԫ����Ч
	local const_tab<const> = {
		a = 1,
		b = 2,
		--c<const> = 3, --��������
	}
	--const_tab.c<const> = 3 --����Ҳ����

	--const_tab = {}   --����ᱻ��ֹ�޸�
	const_tab.a = 6
	const_tab.b = 99
	const_tab.c = 777

	print(const_tab.b)
end


function lua_t(str)
	_M.err()

	print("lua��� " .. str)
	lua_print(str)

	const_test()

	--nil? undef?
	local u
	print(u, x)

	return 12369
end
