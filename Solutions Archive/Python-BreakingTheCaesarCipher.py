def analyzeCaesar(strCiphertext):
	
	#Variable declarations
	strAlphabet = "abcdefghijklmnopqrstuvwxyz"
	lstPossibilities = []

	#Procedural execution start
	strCiphertext = strCiphertext.lower()
	for idx in range(26):
		strPossibility = ""
		for character in strCiphertext:
			if character == ' ':
				strPossibility += ' '
			else:
				intCharIdx = strAlphabet.index(character)
				strPossibility += strAlphabet[(intCharIdx - idx) % 26]
		lstPossibilities.append(strPossibility)
	return lstPossibilities


def main():

	#Variable declarations
	dictIO = {1: "Welcome to the Caesar Cipher Analysis Program!\n", 2: "What is the ciphertext you would like to crack?\n", \
		  3: "The possibilities are:\n", 4: "Integer shift:		Output:", 5: "Would you like to continue? [y/n]\n", \
		  6: "Goodbye!\n"}

	lstPossible = []
	strCiphertext = ""
	charOP = ''
	boolIsLoop = True
	
	#Procedural execution start
	print(dictIO[1])
	while boolIsLoop == True:
		strCiphertext = raw_input(dictIO[2])
		lstPossible = analyzeCaesar(strCiphertext)
		print(dictIO[3] + dictIO[4])
		for idx in range(len(lstPossible)):
			print("     %i		%s\n" %(idx, lstPossible[idx]))
		charOp = raw_input(dictIO[5])
		if charOp != 'y':
			print(dictIO[6])
			boolIsLoop = False

main()

