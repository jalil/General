def checkDuplicates(strInput):
	strOutput = ""
	for character in strInput:
		if strOutput.count(character) == 0:
			strOutput += character
	return strOutput

def generateCipherAlphabet(strPass):
	strAlphabet = "abcdefghijklmnopqrstuvwxyz "
	return checkDuplicates(strPass + strAlphabet)

def encrypt(strPlaintext, strCipherAlphabet):
	strLatinAlphabet = "abcdefghijklmnopqrstuvwxyz "
	strCiphertext = ""
	strPlaintext = strPlaintext.lower()
	for idx in range(0, len(strPlaintext)):
		strCiphertext += strCipherAlphabet[(strLatinAlphabet.index(strPlaintext[idx]) + 3) % 26]
	return strCiphertext

def decrypt(strCiphertext, strCipherAlphabet):
	strLatinAlphabet = "abcdefghijklmnopqrstuvwxyz "
	strPlaintext = ""
	for idx in range(0, len(strCiphertext)):
		strPlaintext += strLatinAlphabet[((strCipherAlphabet.index(strCiphertext[idx]) - 3) % 26)]
	return strPlaintext

def main():
	dictIO = {1: "Welcome to the general substitution cipher program!\n", 2: "What is your password? ", \
		3: "Would you like to encrypt or decrypt? [e/d]\n", 4: "What is the plaintext? ", \
		5: "What is the ciphertext? ", 6: "Would you like to immediately proceed with decryption? [y/n]\n", \
		7: "Goodbye!\n", 8: "The plaintext ", 9: "The ciphertext ", 10: " yields the string ", \
		11: "Would you like to continue? [y/n]\n" }
	charOp = ''
	strInput = ""
	strPassword = ""
	boolIsLoop = True
	print(dictIO[1])
	while boolIsLoop == True:
		strPassword = raw_input(dictIO[2])
		strPassword = generateCipherAlphabet(strPassword)
		charOp = raw_input(dictIO[3])
		if charOp == 'e':
			strInput = raw_input(dictIO[4])
			strOutput = encrypt(strInput, strPassword)
			print(dictIO[8] + strInput + dictIO[10] + strOutput)
			if raw_input(dictIO[6]) == 'y':
				strInput = strOutput
				print(dictIO[9] + strInput + dictIO[10] + decrypt(strOutput, strPassword))
		elif charOp == 'd':
			strInput = raw_input(dictIO[5])
			print(dictIO[9] + strInput + dictIO[10] + decrypt(strInput, strPassword))
		if raw_input(dictIO[11]) != 'y':
			print(dictIO[7]) 
			boolIsLoop = False
main()
