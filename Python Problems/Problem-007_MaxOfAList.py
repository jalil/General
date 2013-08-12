def maxOfList(lst):
	maxSoFar = -9999999999
	for value in lst:
		if value > maxSoFar:
			maxSoFar = value
	return maxSoFar

def main():
	myList = [1,2,3,4,5]
	listString = str(myList)
	maxOfList1 = max(myList)
	maxOfList2 = maxOfList(myList)

	print 'The expression maxOfList(%s) = %i.\nDoes max(%s) == maxOfList(%s)?\n  --> %s' %(listString, maxOfList2,listString, listString, maxOfList1 == maxOfList2)

if __name__ == '__main__':
	main() 
