import functools, math

def arithmeticMean(lst):
	return sum(lst)/len(lst)

def differenceOfSquares(x1, x2):
	return float(x1 - x2) ** 2

def sampleVariance(lst):
	return sum(map(functools.partial(differenceOfSquares, x2=arithmeticMean(lst)), lst)) / (len(lst) - 1)

def popVariance(lst):
	return sum(map(functools.partial(differenceOfSquares, x2=arithmeticMean(lst)), lst)) / len(lst)

def sampleStdDev(lst):
	return math.sqrt(sampleVariance(lst))

def popStdDev(lst):
	return math.sqrt(popVariance(lst))

def main():
	myList = [1,2,3,4,5]
	expectedSample, expectedPop = 1.5811, 1.4142 
	print "The outcome of sampleStdDev(%s) is %.4f and the outcome of popStdDev(%s) is %.4f." %(myList, sampleStdDev(myList), myList, popStdDev(myList))
	print 'The expected outcomes were %.4f and %.4f respectively, thus we conclude that our function is %s' %(expectedSample, expectedPop, 'correct' if round(sampleStdDev(myList), 4) == expectedSample and round(popStdDev(myList), 4) == expectedPop else 'incorrect')	
	
if __name__ == '__main__':
	main()
