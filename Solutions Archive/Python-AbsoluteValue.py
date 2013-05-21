def absVal(n):
	return n if n >= 0 else -n

def main():
	n = int(raw_input("Please give me an integer: "))
	print "The absolute value of %d is %d" %(n, absVal(n))

main()
