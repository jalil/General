def mults3or5(u):
	s = 0
	return sum([s + i for i in range(u) if i % 3 == 0 or i % 5 == 0])


print mults3or5(1000)
