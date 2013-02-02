def checkAnagram(strAna1, strAna2):
	if len(strAna1) != len(strAna2):
		return False
	else:
		strAna1, strAna2 = strAna1.lower(), strAna2.lower()
		for idx in range(0, len(strAna1)):
			if strAna1[idx] not in strAna2:
				return False
		return True
def main():
	dictIO = {1: "Welcome to the anagram checking algorithm!\n", 2: "Would you like to continue? [y/n]\n", \
	3: "What is the first word?", 4: "What is the second word?", 5:" are anagrams", \
	 6:"These words are not anagrams", 7:"Goodbye!"}
	print(dictIO[1])
	isLoop = True
	while isLoop == True:
		strAna1 = raw_input(dictIO[3])
		strAna2 = raw_input(dictIO[4])
		if checkAnagram(strAna1, strAna2) == True:
			print(strAna1 + ' and ' + strAna2 + dictIO[5])
		else:
			print(dictIO[6])
		if raw_input(dictIO[2]) != 'y':
			print(dictIO[7])
			isLoop = False
main()
