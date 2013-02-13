#-------------------------------------------------------------------------------
# Name:        Playfair Cipher
# Purpose:     To encrypt and decrypt individual strings using the playfair cipher
#
# Author:      Braden Lenz
#
# Created:     2/12/2013
# Licence:     GNU GPL (Version 3)
#-------------------------------------------------------------------------------

def main():
    dictIO = {1: "Welcome to the playfair cipher.\n", 2: "Would you like to encrypt or decrypt a string? [e/d]\n", 3: "You have chosen to encrypt a string.\n", 4: "Please type a string: ", \
              5: "You have chosen to decrypt a string.\n", 6: "Your encrypted string is: ", 7: "Your decrypted string is: ", 8: "Would you like to continue? [y/n]\n", 9: "Goodbye!", \
              10: "Would you like to insert your own key matrix? [y/n]", 11: "The default key matrix will be used.\n", 12: "Insert your key matrix in character groups of five delimted by commas.\n", \
              13: "Note that the i character == the j character to create a 5x5 matrix.\n", 14: "Insert the group of five characters: ", 15: "The provided key matrix was entered incorrectly.\n", \
              16: "The key matrix was accepted.\n", 17: [['p','l','a','y','f'],['i','r','e','x','m'],['b','c','d','g','h'],['k','n','o','q','s'],['t','u','v','w','z']], 18: "The previously added key will be used.\n", \
	      19: "Would you like to turn on post operation processing? [y/n]\n"}
    #dictIO serves as a collection of all user constant user interaction strings. This serves to organize all constant strings for quick reference and universal changes
    
    print(dictIO[1])
    isLoop = True									#isLoop serves as the while loop condition
    while isLoop == True:								#User interaction ensures this will not become an infinite loop
        lstKeyMatrix = None								#lstKeyMatrix will serve as the cipher key matrix, but must first be initialized to None
        if raw_input(dictIO[2]) == ('e' or 'E'):
            print(dictIO[3])
            plaintext = raw_input(dictIO[4])
            if raw_input(dictIO[10]) == ('y' or 'Y'):
                lstKeyMatrix = usrDefinedKeyValidation(usrDefinedKey(dictIO))		#If the user elects to insert their own key matrix, the string of characters is formatted by usrDefinedKey and then vetted
                if lstKeyMatrix == None:						#usrDefinedKeyValidation() returns None if there is an error with the input sequence
                    print(dictIO[15])
                    print(dictIO[11])
                    ciphertext = encrypt(plaintext, dictIO[17])				#Assuming that the user defined key is in error, the default key matrix is used
                else:
                    print(dictIO[16])
                    ciphertext = encrypt(plaintext, lstKeyMatrix)			#Assuming that the user defined key contains no error it is made an argument to the encrypt function
            else:
                print(dictIO[16])
                ciphertext = encrypt(plaintext,dictIO[17])				#The user has elected to use the default key
            print(dictIO[6] + str(ciphertext) + '\n')
	    if raw_input(dictIO[8]) != ('y' or "Y"):					#User is asked whether they wish to continue: break if yes, continue if else
                print(dictIO[9])
                isLoop = False
        else:		
            print(dictIO[5])
            ciphertext = raw_input(dictIO[4])
            if lstKeyMatrix != None:							#Assumes that the decryption cycle has directly followed a successful encryption with a user-defined key matrix
                print(dictIO[18])
                newPlaintext = decrypt(ciphertext, lstKeyMatrix)
            else:
                print(dictIO[11])
                newPlaintext = decrypt(ciphertext, dictIO[17])				#Decrypts with default key matrix
	    if raw_input(dictIO[19]) == ('y' or "Y"):					#Option to turn on postop processing
		    newPlaintext = postOpProcessing(newPlaintext)
	    
	    print(dictIO[7] + newPlaintext + '\n')
            if raw_input(dictIO[8]) != ('y' or 'Y'):
                print(dictIO[9])
                isLoop = False
                
def encrypt(plaintext, lstKeyMatrix ):
    plaintext = plaintext.lower()							#Control for case of characters
    plaintext = plaintext.replace(' ', '')						#Removes whitespace in string
    lstPairs = pairCharacters(plaintext)						#Splits the plaintext into digrams 
    lstCipherPairs = []				
    for pair in lstPairs:
        lstLocation = enumerateKeyMatrix(pair, lstKeyMatrix)				#lstLocation holds a pair of lists which hold the key matrix coordinates for the first and second character in the pair respectively 
        if lstLocation[0][0] == lstLocation[1][0]:					#If the two characters exist on the same row
            if lstLocation[0][1] == 4:							#Control for wrapping 
                lstLocation[0][1] = 0
                lstLocation[1][1] += 1
            elif lstLocation[1][1] == 4:
                lstLocation[1][1] = 0
                lstLocation[0][1] += 1
            else:
                lstLocation[0][1] += 1							#Add one value to each of the column coordinates
                lstLocation[1][1] += 1
        elif lstLocation[0][1] == lstLocation[1][1]:					#If the two characters exist on the same column
            if lstLocation[0][0] == 4:							#Control for wrapping
                lstLocation[0][0] = 0
                lstLocation[1][0] += 1
            elif lstLocation[1][0] == 4:
                lstLocation[1][0] = 0
                lstLocation[0][0] += 1
            else:
                lstLocation[0][0] += 1							#Add one value to each of the row coordinates
                lstLocation[1][0] += 1
        else:
            x1,x2 = lstLocation[0][0],lstLocation[1][0]					#initialize row coordinates from the first and second characters
            lstLocation[0][0] = x2							#Swap row coordinates between character 1 and 2
            lstLocation[1][0] = x1
        lstCipherPairs.append([lstKeyMatrix[lstLocation[0][0]][lstLocation[0][1]], lstKeyMatrix[lstLocation[1][0]][lstLocation[1][1]]])  
											#Lookup the characters in the key matrix corresponding to the new coordinates and append them to lstCipherPairs  
    ciphertext = ''
    for element in lstCipherPairs:							#Concatentate all characters 
        ciphertext += str(element[0][0]) + str(element[1][0])
    return ciphertext									#return the completed cipher text

def decrypt(ciphertext, lstKeyMatrix):
    plaintext = ''									#Assuming all string processing has already occurred in the encryption cycle we only need to initialize an empty string to hold the plain text
    for idx in range(0,len(ciphertext), 2):						#Loop through all of the characters in the ciphertext in pairs of two
        lstLocation = enumerateKeyMatrix([ciphertext[idx],ciphertext[idx+1]], lstKeyMatrix) #Lookup key matrix coordinates corresponding to the characters in the cipher text pair
        if lstLocation[0][0] == lstLocation[1][0]:					#If the two characters exist on the same row
            if lstLocation[0][1] == 0:							#Control for inverse wrapping
                lstLocation[0][1] = 4
                lstLocation[1][1] -= 1
            elif lstLocation[1][1] == 0:
                lstLocation[1][1] = 4
                lstLocation[0][1] -= 1
            else:
                lstLocation[0][1] -= 1							#Decrease row position by one for each character
                lstLocation[1][1] -= 1
        elif lstLocation[0][1] == lstLocation[1][1]:					#If the two characters exist on the same column
            if lstLocation[0][0] == 0:							#Control for inverse wrapping
                lstLocation[0][0] = 4
                lstLocation[1][0] -= 1
            elif lstLocation[1][0] == 0:
                lstLocation[1][0] = 4
                lstLocation[0][0] -= 1
            else:
                lstLocation[0][0] -= 1							#Decrease column position by one
                lstLocation[1][0] -= 1
        else:
            x1,x2 = lstLocation[0][0], lstLocation[1][0]				#Inverse row-coordinate swap
            lstLocation[0][0] = x2
            lstLocation[1][0] = x1
        plaintext += lstKeyMatrix[lstLocation[0][0]][lstLocation[0][1]] + lstKeyMatrix[lstLocation[1][0]][lstLocation[1][1]]
											#Lookup key matrix characters corresponding to the characters in the plain text pair
    return plaintext									#Return the completed plaintext

def pairCharacters(plaintext):								#pairCharacters() is used for the encyption cycle string processing
    if len(plaintext) % 2 != 0:								#Since we are dealing with digrams, we must operate with even numbers of characters
        plaintext += 'z'								#by convention an uncommon monograph is appended to an odd numbered length string, in this case 'z'
    lstPairs = []
    for idx in range(0,len(plaintext), 2):						#Additionally, since we are dealing with a 5x5 matrix, we must have 25 characters. We have arbitrated i == j to serve this purpose
        if plaintext[idx] == 'j' and plaintext[idx + 1] == 'j':
            plaintext[idx], plaintext[idx] = 'i', 'i'
        elif plaintext[idx + 1] == 'j':
            plaintext[idx + 1] = 'i'
        elif plaintext[idx] == 'j':
            plaintext[idx] = 'i'
            
        if plaintext[idx] != plaintext[idx + 1]:					#Additionally, in order to further decrease the probabilty of frequency analysis we have arbitrated that if a character pair is the same thn
            lstPairs.append([plaintext[idx], plaintext[idx + 1]])			#the second character is replaced with an uncommon monograph, in this case 'x'
        else:
            lstPairs.append([plaintext[idx], 'x'])
    return lstPairs									#Return the list of processed pairs
                
           
def enumerateKeyMatrix(lstPair, lstKeyMatrix):						#enumerateKeymatrix() is used to find the coordinates of the characters in the matrix and return them for encryption/decryption 
    dictPair = {lstPair[0]: None, lstPair[1]: None}
    lstOutput = []
    for i in range(len(lstKeyMatrix)):
        for j in range(len(lstKeyMatrix[i])):
            if lstKeyMatrix[i][j] in dictPair:
                dictPair[lstKeyMatrix[i][j]] = [i,j]
    return [dictPair[lstPair[0]], dictPair[lstPair[1]]]
                   
             

def usrDefinedKey(dictIO):								#usrDefinedKey() takes 5 user defined strings of characters (comma delimited) and turns them into a matrix
    print(dictIO[12])
    print(dictIO[13])
    lstKeyMatrix = []
    for idx in range(0,5):
        strRow = raw_input(dictIO[14])
        lstElement = strRow.split(',')
        lstKeyMatrix.append(lstElement)
    return lstKeyMatrix

def usrDefinedKeyValidation(lstKeyMatrix):						#usrDefinedKeyValidation() receives the output of the usrDefinedKey function and validates it such that the input key does not break anything
    strAcceptedChars = 'abcdefghijklmnopqrstuvwxyz'					#strAcceptedChars lists all of the acceptable characters we will allow in our matrix
    strFoundChars = ''			
    for row in lstKeyMatrix:								#We will reject the user defined matrix if it does not contain the correct number of elements
        if len(row) != 5:
            return None
        for element in row:								#Else we put the characters in a lower case and put them into our strfound variable
            strFoundChars += element.lower()
    if len(strAcceptedChars) != len(strFoundChars):					#If the length of the accepted characters does not equal the received characters we may also reject the user defined matrix
        return None
    for idx in range(len(strFoundChars)):						#We will iterate through all of the characters found to search for a duplicate character, which would break the encryption algorithm
        if strFoundChars[idx] in strAcceptedChars:
            n = strAcceptedChars.index(strFoundChars[idx])
            if n == 0:
                strAcceptedChars = strAcceptedChars[1:]
            elif n == len(strFoundChars) - 1:
                strAcceptedChars = strAcceptedChars[:-1]
            else:
                strAcceptedChars = strAcceptedChars[:n] + strAcceptedChars[n +1]
        else:
            return None
            
    return lstKeyMatrix									#If all is valid, we return the user defined key matrix

def postOpProcessing(ciphertext):							#postOpProcessing() is an optional function which will find and remove x's from duplicate character pairs and remove appended z's.
	for idx in range(0, len(ciphertext), 2):					#Note: this may cause problems, as in 'excalibur'.
		if ciphertext[idx + 1] == 'x':
			ciphertext[idx + 1] = ciphertext[idx]
	if ciphertext[-1] == 'z':
		ciphertext = ciphertext[:-1]
	return ciphertext

main()
