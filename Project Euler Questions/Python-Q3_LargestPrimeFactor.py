import urllib

def largestPrimeFactor(n):
	f = urllib.urlopen("http://primes.utm.edu/lists/small/10000.txt")
	lstLines = f.readlines()
	largestPrime = 0
	
	for rowIdx in range(4, len(lstLines) - 1):
		lstLine = lstLines[rowIdx].split()
		for prime in lstLine:
			if n % int(prime) == 0:
				largestPrime = prime
	f.close()
	return largestPrime

print largestPrimeFactor(600851475143)	
