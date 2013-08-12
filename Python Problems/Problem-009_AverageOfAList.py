def arithmeticMean(lst):
	return sum(lst)/len(lst)


def main():
	myList = [1,2,3,4,5]
	expectedAverage = 3
	print "The outcome of arithmeticMean(%s) is %i. The expected outcome was %i.\n This means that our function is %s" %(myList, arithmeticMean(myList), expectedAverage, 'correct' if arithmeticMean(myList) == expectedAverage else 'incorrect')

if __name__ == '__main__':
	main()
