D_memo = {}


def D(n):
	if n in D_memo:
		return D_memo[n]

	if n == 0:
		return 1
	elif n ==1:
		return 0
	else:
		val = (n - 1) * (D(n - 1) + D(n - 2))
		D_memo[n] = val
		return val


print D(999)
