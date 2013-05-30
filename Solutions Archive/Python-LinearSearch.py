def linearSearch(l, v):
	for i in range(len(l)):
		if l[i] == v:
			return i
	return -1

def main():
	l = []
	n = int(raw_input("How many elements would you like to add?\n  -->  "))
	for i in range(n):
		l.append(raw_input("Element %i:" %i))
	
	n = raw_input("What would you like to search for?\n  -->  ")
	idx = linearSearch(l, n)
	if idx == -1:
		print "The element " + n + " was not found in the list"
	else:
		print "The element " + n + " was found at index " + str(idx)

main()	
