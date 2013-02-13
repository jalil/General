def staircount(n): #n is of type int and the numbers of stairs in the staircase
	if n == 1:
		return 1
	elif n == 2:
		return 2
	else:
		return staircount(n - 2) + staircount(n - 1)

