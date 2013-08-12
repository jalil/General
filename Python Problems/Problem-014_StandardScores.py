import functools, math

def arithmeticMean(lst):
	return sum(lst)/len(lst)

def differenceOfSquares(x1, x2):
	return float(x1 - x2) ** 2

def popVariance(lst):
	return sum(map(functools.partial(differenceOfSquares, x2=arithmeticMean(lst)), lst)) / len(lst)

def popStdDev(lst):
	return math.sqrt(popVariance(lst))

def zScore(x, lst):
	return (x - arithmeticMean(lst)) / popStdDev(lst)

def main():
	myList = [1,2,3,4,5]
	value = 3.5
	expectedZScore = 0.3536  
	print "The outcome of zScore(%.2f, %s) is %.4f and the expected outcome was %.4f." %(value, myList, zScore(value, myList), expectedZScore)
	print 'Since our expected and actual %s, we conclude that our function is %s' %('matched', 'correct') if round(zScore(value,myList), 4) == expectedZScore else ('did not match','incorrect')	
	
if __name__ == '__main__':
	main()
