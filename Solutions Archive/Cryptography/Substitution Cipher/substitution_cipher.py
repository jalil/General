def encrypt(plainText, cipher = ' zyxwvutsrqponmlkjihgfedcba'):
	alphabet = 'abcdefghijklmnopqrstuvwxyz '
	cipherText = ''
	plainText = plainText.lower()
	for idx in range(0, len(plainText)):
		cipherText += cipher[alphabet.index(plainText[idx])]
	return cipherText
def decrypt(cipherText, cipher = ' zyxwvutsrqponmlkjihgfedcba'):
	alphabet = 'abcdefghijklmnopqrstuvwxyz '
	plainText = ''
	for idx in range(0, len(cipherText)):
		plainText += alphabet[cipher.index(cipherText[idx])]
	return plainText

def main():
	dictIO = {1: "Welcome to the substitution cipher algorithm.\n",\
	2: "Please type your message to encrypt:\n", 3:"Your encrypted message is ", \
	4: "Please type your message to decrypt:\n", 5:"Your decrypted message is ", \
	6: "Would you like to encrypt or decrypt a string? [en/de]\n", 7:"Would you like to enter your own cipher? [y/n]",\
	8:"You have chosen not to enter your own cipher", 9:"Warning: By incorrectly supplying a cipher you may break the program.\n Please type your cipher:\n", \
	10: "Would you like to continue? [y/n]\n", 11: "Goodbye!"}
	isLoop = True
	print dictIO[1]
	if raw_input(dictIO[7]) == 'y':
		ioCipher = raw_input(dictIO[9])
	else:
		print(dictIO[8])
	while isLoop == True:
		if raw_input(dictIO[6]) == 'en':
			plainText = encrypt(raw_input(dictIO[2]))
			print(dictIO[3] + plainText)
		else:
			cipherText = decrypt(raw_input(dictIO[4]))
			print(dictIO[5] + cipherText)
		if raw_input(dictIO[10]) != 'y':
			isLoop = False
	print(dictIO[11])
main()
