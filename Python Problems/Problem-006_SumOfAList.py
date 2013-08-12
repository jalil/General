def sumAcrossList(lst):
	accumulator = 0.0
	for number in lst:
		accumulator = number + accumulator

	return accumulator

def main():
	myList = [1,2,3,4,5]
	listString = str(myList)
	listSum1 = sum(myList)
	listSum2 = sumAcrossList(myList)

	print 'The expression sumAcrossList(%s) = %i. Does sum(%s) == sumAcrossList(%s)? %s' %(listString, listSum2, myList, myList, listSum1 == listSum2)

if __name__ == '__main__':
	main()
