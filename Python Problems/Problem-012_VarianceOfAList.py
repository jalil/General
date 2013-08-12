import functools

def arithmeticMean(lst):
	return sum(lst)/len(lst)

def differenceOfSquares(x1, x2):
	return float(x1 - x2) ** 2

def sampleVariance(lst):
	return sum(map(functools.partial(differenceOfSquares, x2=arithmeticMean(lst)), lst)) / (len(lst) - 1)

def popVariance(lst):
	return sum(map(functools.partial(differenceOfSquares, x2=arithmeticMean(lst)), lst)) / len(lst)

def main():
	myList = [1,2,3,4,5]
	expectedSample, expectedPop = 2.5, 2 
	print "The outcome of sampleVariance(%s) is %.2f and the outcome of popVariance(%s) is %.2f." %(myList, sampleVariance(myList), myList, popVariance(myList))
	print 'The expected outcomes were %.2f and %.2f respectively, thus we conclude that our function is %s' %(expectedSample, expectedPop, 'correct' if sampleVariance(myList) == expectedSample and popVariance(myList) == expectedPop else 'incorrect')	

if __name__ == '__main__':
	main()
