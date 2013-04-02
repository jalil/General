def D(n):
	if n == 0:
		return 1
	elif n ==1:
		return 0
	else:
		return (n - 1) * (D(n - 1) + D(n - 2))
print D(900)

