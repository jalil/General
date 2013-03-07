def encrypt(strPlaintext, intN):

	#Variable declaration section
	strAlphabet = "abcdefghijklmnopqrstuvwxyz"
	strCiphertext = ""
	intCharIndex = 0
	
	#Encrypt procedural execution start
	strPlaintext = strPlaintext.lower()		#Set all characters to lower

	for character in strPlaintext:
		if character == ' ':
			strCiphertext += ' '
		else:
			intCharIndex = strAlphabet.index(character)
			strCiphertext += strAlphabet[(intCharIndex + intN) % 26]
	return strCiphertext

def decrypt(strCiphertext, intN):
	#Variable declaration section
	strAlphabet = "abcdefghijklmnopqrstuvwxyz"
	strPlaintext = ""
	intCharIndex = 0

	#Decrypt procedural execution start
	strCiphertext = strCiphertext.lower()
	
	for character in strCiphertext:
		if character == ' ':
			strPlaintext += ' '
		else:
			intCharIndex = strAlphabet.index(character)
			strPlaintext += strAlphabet[(intCharIndex - intN) % 26]
	return strPlaintext
	

def main():
	#Variable declarations section
	dictIO= {1: "Welcome to the Caesar Cipher Program!\n", 2: "Would you like to encrypt or decrypt a string? [e/d]\n", \
		 3: "Your encrypted string is: ", 4: "Your decrypted string is: ", 5: "Would you like to decrypt this string? [y/n]\n", \
		 6: "Would you like to continue? [y/n]\n", 7: "Goodbye!\n", 8: "What character index shift would you like to use? [1..26]\n", \
		 9: "That was not a valid option.\n", 10: "What is your string that you would like to manipulate?\n"}
	charOp = ''
	intShift = 0
	strPlaintext = ""
	strCiphertext = ""
	boolIsLoop = True
	
	#Main procedural execution start 
	print(dictIO[1])
	while boolIsLoop == True:
		charOp = raw_input(dictIO[2])
		if charOp == 'e':
			strPlaintext = raw_input(dictIO[10])
			intShift = int(raw_input(dictIO[8]))
			strCiphertext = encrypt(strPlaintext, intShift)
			print(dictIO[3] + strCiphertext)
			charOp = raw_input(dictIO[5])
			if charOp == 'y':
				strPlaintext = decrypt(strCiphertext, intShift)
				print(dictIO[4] + strPlaintext) 
		elif charOp == 'd':
			strCiphertext = raw_input(dictIO[10])
			intShift = int(raw_input(dictIO[8]))
			strPlaintext = decrypt(strCiphertext, intShift)
			print(dictIO[4] + strPlaintext)
		else:
			print(dictIO[9])
	
		if raw_input(dictIO[6]) != 'y':
			print(dictIO[7])
			boolIsLoop = False

				
main()			
