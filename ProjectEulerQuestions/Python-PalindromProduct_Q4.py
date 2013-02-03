def palindromeProduct():
	intPalindromeProduct = 0
	lstPalindromes = []
	for x in range(100, 1000):
		for y in range(100, 1000):
			z = x * y
			z = str(z)
			if z == z[::-1]:
				lstPalindromes.append(int(z))
	return max(lstPalindromes)

print palindromeProduct()

