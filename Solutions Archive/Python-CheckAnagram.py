def checkAnagrams(s1, s2):
	if len(s1) != len(s2):
		return False
	else:
		stringPairs = [[s1, {}], [s2, {}]]
		for inStr in stringPairs:
			for i in range(len(inStr[0])):
				if inStr[0][i] not in inStr[1].keys():
					inStr[1][inStr[0][i]] = 1
				else:
					inStr[1][inStr[0][i]] += 1
		return stringPairs[0][1] == stringPairs[1][1]

def main():
	s1 = raw_input("Give me the first string: ")
	s2 = raw_input("Give me the second string: ")

	if checkAnagrams(s1, s2):
		print "'" + s1 + "' and '" + s2 + "' are anagrams"
	else:
		print "'" + s1 + "' and '" + s2 + "' are not anagrams"

main()
