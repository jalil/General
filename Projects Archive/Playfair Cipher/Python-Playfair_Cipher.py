#-------------------------------------------------------------------------------
# Name:        Playfair Cipher
# Purpose:     To encrypt and decrypt strings
#
# Author:      Braden Lenz
#
# Created:     12/02/2013
# Licence:     GNU GPL (Version 3)
#-------------------------------------------------------------------------------

def main():
    dictIO = {1: "Welcome to the playfair cipher.\n", 2: "Would you like to encrypt or decrypt a string? [e/d]\n", 3: "You have chosen to encrypt a string.\n", 4: "Please type a string: ", \
              5: "You have chosen to decrypt a string.\n", 6: "Your encrypted string is: ", 7: "Your decrypted string is: ", 8: "Would you like to continue? [y/n]\n", 9: "Goodbye!", \
              10: "Would you like to insert your own key matrix? [y/n]", 11: "The default key matrix will be used.\n", 12: "Insert your key matrix in character groups of five delimted by commas.\n", \
              13: "Note that the i character == the j character to create a 5x5 matrix.\n", 14: "Insert the group of five characters: ", 15: "The provided key matrix was entered incorrectly.\n", \
              16: "The key matrix was accepted.\n", 17: [['p','l','a','y','f'],['i','r','e','x','m'],['b','c','d','g','h'],['k','n','o','q','s'],['t','u','v','w','z']], 18: "The previously added key will be used.\n"}
    print(dictIO[1])
    isLoop = True
    while isLoop == True:
        lstKeyMatrix = None
        if raw_input(dictIO[2]) == ('e' or 'E'):
            print(dictIO[3])
            plaintext = raw_input(dictIO[4])
            if raw_input(dictIO[10]) == ('y' or 'Y'):
                lstKeyMatrix = usrDefinedKeyValidation(usrDefinedKey(dictIO))
                if lstKeyMatrix == None:
                    print(dictIO[15])
                    print(dictIO[11])
                    ciphertext = encrypt(plaintext, dictIO[17])
                else:
                    print(dictIO[16])
                    ciphertext = encrypt(plaintext, lstKeyMatrix)
            else:
                print(dictIO[16])
                ciphertext = encrypt(plaintext,dictIO[17])
            print(dictIO[6] + str(ciphertext) + '\n')
            if raw_input(dictIO[8]) != ('y' or "Y"):
                print(dictIO[9])
                isLoop = False
        else:
            print(dictIO[5])
            ciphertext = raw_input(dictIO[4])
            if lstKeyMatrix != None:
                print(dictIO[18])
                newPlaintext = decrypt(ciphertext, lstKeyMatrix)
            else:
                print(dictIO[11])
                newPlaintext = decrypt(ciphertext, dictIO[17])
            print(dictIO[7] + newPlaintext + '\n')
            if raw_input(dictIO[8]) != ('y' or 'Y'):
                print(dictIO[9])
                isLoop = False
                
def encrypt(plaintext, lstKeyMatrix ):
    plaintext = plaintext.lower()
    plaintext = plaintext.replace(' ', '')
    lstPairs = pairCharacters(plaintext)
    lstCipherPairs = []
    for pair in lstPairs:
        lstLocation = enumerateKeyMatrix(pair, lstKeyMatrix)
        if lstLocation[0][0] == lstLocation[1][0]:
            if lstLocation[0][1] == 4:
                lstLocation[0][1] = 0
                lstLocation[1][1] += 1
            elif lstLocation[1][1] == 4:
                lstLocation[1][1] = 0
                lstLocation[0][1] += 1
            else:
                lstLocation[0][1] += 1
                lstLocation[1][1] += 1
        elif lstLocation[0][1] == lstLocation[1][1]:
            if lstLocation[0][0] == 4:
                lstLocation[0][0] = 0
                lstLocation[1][0] += 1
            elif lstLocation[1][0] == 4:
                lstLocation[1][0] = 0
                lstLocation[0][0] += 1
            else:
                lstLocation[0][0] += 1
                lstLocation[1][0] += 1
        else:
            x1,x2 = lstLocation[0][0],lstLocation[1][0]
            lstLocation[0][0] = x2
            lstLocation[1][0] = x1
        lstCipherPairs.append([lstKeyMatrix[lstLocation[0][0]][lstLocation[0][1]], lstKeyMatrix[lstLocation[1][0]][lstLocation[1][1]]])
    ciphertext = ''
    for element in lstCipherPairs:
        ciphertext += str(element[0][0]) + str(element[1][0])
    return ciphertext

def decrypt(ciphertext, lstKeyMatrix):
    plaintext = ''
    for idx in range(0,len(ciphertext), 2):
        lstLocation = enumerateKeyMatrix([ciphertext[idx],ciphertext[idx+1]], lstKeyMatrix)
        if lstLocation[0][0] == lstLocation[1][0]:
            if lstLocation[0][1] == 0:
                lstLocation[0][1] = 4
                lstLocation[1][1] -= 1
            elif lstLocation[1][1] == 0:
                lstLocation[1][1] = 4
                lstLocation[0][1] -= 1
            else:
                lstLocation[0][1] -= 1
                lstLocation[1][1] -= 1
        elif lstLocation[0][1] == lstLocation[1][1]:
            if lstLocation[0][0] == 0:
                lstLocation[0][0] = 4
                lstLocation[1][0] -= 1
            elif lstLocation[1][0] == 0:
                lstLocation[1][0] = 4
                lstLocation[0][0] -= 1
            else:
                lstLocation[0][0] -= 1
                lstLocation[1][0] -= 1
        else:
            x1,x2 = lstLocation[0][0], lstLocation[1][0]
            lstLocation[0][0] = x2
            lstLocation[1][0] = x1
        plaintext += lstKeyMatrix[lstLocation[0][0]][lstLocation[0][1]] + lstKeyMatrix[lstLocation[1][0]][lstLocation[1][1]]
    return plaintext

def pairCharacters(plaintext):
    if len(plaintext) % 2 != 0:
        plaintext += 'z'
    lstPairs = []
    for idx in range(0,len(plaintext), 2):
        if plaintext[idx] == 'j' and plaintext[idx + 1] == 'j':
            plaintext[idx], plaintext[idx] = 'i', 'i'
        elif plaintext[idx + 1] == 'j':
            plaintext[idx + 1] = 'i'
        elif plaintext[idx] == 'j':
            plaintext[idx] = 'i'
            
        if plaintext[idx] != plaintext[idx + 1]:
            lstPairs.append([plaintext[idx], plaintext[idx + 1]])
        else:
            lstPairs.append([plaintext[idx], 'x'])
    return lstPairs
                
           
def enumerateKeyMatrix(lstPair, lstKeyMatrix):
    dictPair = {lstPair[0]: None, lstPair[1]: None}
    lstOutput = []
    for i in range(len(lstKeyMatrix)):
        for j in range(len(lstKeyMatrix[i])):
            if lstKeyMatrix[i][j] in dictPair:
                dictPair[lstKeyMatrix[i][j]] = [i,j]
    return [dictPair[lstPair[0]], dictPair[lstPair[1]]]
                   
             

def usrDefinedKey(dictIO):
    print(dictIO[12])
    print(dictIO[13])
    lstKeyMatrix = []
    for idx in range(0,5):
        strRow = raw_input(dictIO[14])
        lstElement = strRow.split(',')
        lstKeyMatrix.append(lstElement)
    return lstKeyMatrix

def usrDefinedKeyValidation(lstKeyMatrix):
    strAcceptedChars = 'abcdefghijklmnopqrstuvwxyz'
    strFoundChars = ''
    for row in lstKeyMatrix:
        if len(row) != 5:
            return None
        for element in row:
            strFoundChars += element.lower()
    if len(strAcceptedChars) != len(strFoundChars):
        return None
    for idx in range(len(strFoundChars)):
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
            
    return lstKeyMatrix

main()