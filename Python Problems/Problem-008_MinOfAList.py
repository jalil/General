def minOfList(lst):
	minSoFar = 9999999999
	for number in lst:
		if minSoFar > number: minSoFar = number
	return minSoFar


def main():
	myList = [1,2,3,4,5]
	min1, min2 = minOfList(myList), min(myList)

	print 'The expression minOfList(%s) = %i.\nDoes minOfList(%s) == min(%s)?\n  --> %s' %(myList, min1, myList, myList, min1 == min2)

if __name__ == '__main__':
	main()

