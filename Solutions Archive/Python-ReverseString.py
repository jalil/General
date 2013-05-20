def reverseStr(inStr):
	outStr = ""
	for i in range(len(inStr) - 1, -1, -1):
		outStr += inStr[i]
	return outStr

def main():
	s = raw_input("Give me a string to reverse: ")

	print "Your original string was '" + s + "' and the reversed string is '" + reverseStr(s) + "'"


main()
