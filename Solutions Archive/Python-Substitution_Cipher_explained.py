def encrypt(plainText, cipher = ' zyxwvutsrqponmlkjihgfedcba'):
	'''
	Input: A regular string (called a plaintext) and a string containing the cipher.
	 -If no cipher is provided, a reversed alphabet is given as the default input
	Output: An encoded string (called a ciphertext)
	Purpose: To change plaintext string into a ciphertext string 
	'''

	#Our alphabet variable contains the accepted characters for our plaintext
	alphabet = 'abcdefghijklmnopqrstuvwxyz ' 	
	cipherText = ''

	#In order to encrypt all of the characters in a typical plaintext
	#we force all characters in the string to lower case
	plainText = plainText.lower()

	#We iterate through each character position in the plaintext string
	for idx in range(0, len(plainText)):
	
		#Our actual encryption method occurs here.
		#We first return the character at a given index in the plaintext string
		#then proceed to find the index of that character in our alphabet string
		#and finally lookup the character at the alphabet index in the cipher string.
		cipherText += cipher[alphabet.index(plainText[idx])]
	
	#Finally, we exit the function and return our encrypted text (i.e. the ciphertext)
	return cipherText

def decrypt(cipherText, cipher = ' zyxwvutsrqponmlkjihgfedcba'):
	'''
	Input: An encrypted string (called a ciphertext) and a string containing the cipher
	 -if no cipher is provided, a reversed alphabet is given as the default input
	Output: A regular string (called a plaintext)
	Purpose: To perform the inverse of the encrypt process
	'''
	
	#Again, our alphabet variable contains the accepted characters for our plaintext
	alphabet = 'abcdefghijklmnopqrstuvwxyz '
	plainText = ''
	
	#We iterate through each character position in the ciphertext string
	for idx in range(0, len(cipherText)):
		
		#In order to decrypt an encrypted string we first
		#return the character at a given index in the ciphertext string
		#then proceed to find the index of the character in the cipher string
		#and finally lookup the character in the alphabet string corresponding 
		#to the index of the character in the cipher string.
		plainText += alphabet[cipher.index(cipherText[idx])]
	
	#Finally, we exit the function and return our decrypted text (i.e. the plaintext)
	return plainText

def main():

	#The input/output dictionary contains all of our user interaction.
	#This is considered to be a cleaner method of user interaction than
	#having all user interaction events occur with a string literal after
	#a print statement. This way, our string literals are organized for 
	#easy lookup and reuse. 
	dictIO = {1: "Welcome to the substitution cipher algorithm.\n",\
	2: "Please type your message to encrypt:\n", 3:"Your encrypted message is ", \
	4: "Please type your message to decrypt:\n", 5:"Your decrypted message is ", \
	6: "Would you like to encrypt or decrypt a string? [en/de]\n", 7:"Would you like to enter your own cipher? [y/n]",\
	8:"You have chosen not to enter your own cipher", 9:"Warning: By incorrectly supplying a cipher you may break the program.\n Please type your cipher:\n", \
	10: "Would you like to continue? [y/n]\n", 11: "Goodbye!"}

	#The isLoop variable is a boolean and will be the determining factor
	#for our user interaction loop.
	isLoop = True
	print dictIO[1]

	#This set of control flow statements allows the user to enter in a 
	#custom cipher string. 
	if raw_input(dictIO[7]) == 'y':
		ioCipher = raw_input(dictIO[9])
	else:

		#If the user decides not to enter a new cipher string, then
		#we will use the default reverse alphabet cipher.
		print(dictIO[8])
	
	#Our encryption and decryption events are contained within this
	#event loop.
	while isLoop == True:
		if raw_input(dictIO[6]) == 'en':
			
			#Our call for a plaintext
			plainText = encrypt(raw_input(dictIO[2]))
			
			#Returning the ciphertext to the user
			print(dictIO[3] + plainText)
		else:
			
			#Our call for a ciphertext
			cipherText = decrypt(raw_input(dictIO[4]))
			
			#Returning the stringtext to the user
			print(dictIO[5] + cipherText)
		
		#This control flow statement allows the user to exit the loop
		if raw_input(dictIO[10]) != 'y':
			isLoop = False
	print(dictIO[11])

#Calling the main function here starts execution of the program when the 
#user opens the file.
main()
