def median(lst):
	return lst[len(lst) / 2] if len(lst) % 2 != 0 else (lst[len(lst) / 2] + lst[(len(lst) / 2) - 1]) / 2.0 

def main():
	myFirstList, mySecondList = [1,2,3,4,5], [1,2,3,4]
	expected1, expected2 = 3, 2.5
	print 'The outcome of median(%s) is %.2f and the outcome of median(%s) is %.2f.' %(myFirstList, median(myFirstList), mySecondList, median(mySecondList))
	print 'The expected outcomes were %.2f and %.2f respectively.' %(expected1, expected2)
	print 'As a result, I declare that our function is %s!' %('correct' if expected1 == median(myFirstList) and expected2 == median(mySecondList) else 'incorrect')	


if __name__ == '__main__':
	main()
