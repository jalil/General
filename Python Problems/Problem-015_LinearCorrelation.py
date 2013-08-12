import math, functools

def arithmeticMean(lst):
	return sum(lst)/len(lst)

def diffOfSquares(x,y):
	return float(x-y) ** 2

def linearCorrelation(xLst,yLst):
	m1, m2 = arithmeticMean(xLst), arithmeticMean(yLst)
	numerator = sum(map(lambda (x0,y0): (x0 - m1) * (y0 - m2), zip(xLst, yLst))) 
	denominator =  reduce(lambda s1, s2: s1 * s2, [sum(map(functools.partial(diffOfSquares, y=arithmeticMean(lst)), lst)) for lst in [xLst, yLst]])
	return numerator / math.sqrt(denominator)

def main():
	myFirstList, mySecondList = [1,2,3,4,5], [5,4,3,2,1]
	expectedCorrelation = -1.0
	print 'The outcome of linearCorrelation(%s, %s) is %.1f and the expected result if %.1f which means that our function is %s' %(myFirstList, mySecondList, linearCorrelation(myFirstList, mySecondList), expectedCorrelation,'correct' if expectedCorrelation == linearCorrelation(myFirstList, mySecondList) else 'incorrect')	

if __name__ == '__main__':
	main()

