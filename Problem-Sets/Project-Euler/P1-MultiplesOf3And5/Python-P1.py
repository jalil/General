def mults3or5(u):
	s = 0
	return sum([s + i for i in range(u) if i % 3 == 0 or i % 5 == 0])

def main():
	i = int(raw_input("What is the upper bound of the summation of the multiples of 3 or 5?\n  -->  "))
	print "With an upper bound of %i, the sum is %i" %(i, mults3or5(i))
main()

