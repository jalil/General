def summation(l):
	val = 0
	for num in l:
		val += num
	return val

def main():
	l = []
	n = int(raw_input("How many items would you like to add to the list?\n  -->  "))	
	for i in range(n):
		l.append(int(raw_input("Item %d: " %(i + 1))))
	print "The sum of the array is " + str(summation(l))

main()
