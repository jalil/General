def checkDuplicates(strInput):
     strOutput = ""
     for character in strInput:
        if character == 'j' and strOutput.count('i') == 0:
               strOutpus += character
        elif strOutput.count(character) == 0:
                 strOutput += character
     return strOutput

def generateCipherAlphabet(strPass):
     strPass = strPass.lower()
     strAlphabet = "abcdefghiklmnopqrstuvwxyz"
     return checkDuplicates(strPass + strAlphabet)


def generateKeyMatrix(strPass):
    strCipherAlphabet = generateCipherAlphabet(strPass)
    lstKeyMatrix = []
    lstRow = []
    for i in range(len(strCipherAlphabet)):
         lstRow.append(strCipherAlphabet[i])
         if len(lstRow) == 5:
               lstKeyMatrix.append(lstRow)
               lstRow = []
    return lstKeyMatrix

def generateDigraphs(strPlaintext):
     #Pre-process the plaintext
     strPlaintext = strPlaintext.lower()
     strPlaintext = strPlaintext.replace(' ', '')

     #Remove all 'j' characters from the input 
     for j in range(len(strPlaintext)):
          if strPlaintext[j] == 'j':
               strPlaintext[j] = 'i'            

     #check if the plaintext has an odd length
     if len(strPlaintext) % 2 != 0:
          strPlaintext += 'z'
     
     #generate the digraphs
     lstDigraphs = []
     for i in range(0,len(strPlaintext), 2):
          if strPlaintext[i] != strPlaintext[i + 1]:
               lstDigraphs.append([strPlaintext[i], strPlaintext[i + 1]])
          else:
               lstDigraphs.append([strPlaintext[i], 'x'])
     return lstDigraphs

def enumerateKeyMatrix(lstDigraph, lstKeyMatrix):
     lstOutput = [[],[]]
     for i in range(len(lstKeyMatrix)):
          for j in range(len(lstKeyMatrix[i])):
               if lstKeyMatrix[i][j] == lstDigraph[0]:
                    lstOutput[0] = [i,j]
               elif lstKeyMatrix[i][j] == lstDigraph[1]:
                    lstOutput[1] = [i,j]
     return lstOutput

def rectDigraphRule(lstCharCoords):
     lstOutputCoords = lstCharCoords

     #Basically, we swap the column coordinate of the
     #two points in lstCharCoords
     x1, x2 = lstCharCoords[0][0], lstCharCoords[1][0]
     lstOutputCoords[0][0] = x2
     lstOutputCoords[1][0] = x1
     return lstOutputCoords


def colDigraphRule(lstCharCoords, charEdDe):
     lstOutputCoords = lstCharCoords

     if charEdDe == 'e':
          #Control for wrapping
          if lstOutputCoords[0][0] == 4:
                lstOutputCoords[0][0] = 0
                lstOutputCoords[1][0] += 1
          elif lstOutputCoords[1][0] == 4:
                lstOutputCoords[1][0] = 0
                lstOutputCoords[0][0] += 1
          else:
                lstOutputCoords[0][0] += 1
                lstOutputCoords[1][0] += 1
     elif charEdDe == 'd':
          #control for wrapping
          if lstOutputCoords[0][0] == 0:
                lstOutputCoords[0][0] = 4
                lstOutputCoords[1][0] -= 1
          elif lstOutputCoords[1][0] == 0:
                lstOutputCoords[1][0] = 4
                lstOutputCoords[0][0] -= 1
          else:
                lstOutputCoords[0][0] -= 1
                lstOutputCoords[1][0] -= 1

     return lstOutputCoords

def rowDigraphRule(lstCharCoords, charEdDe):
    lstOutputCoords = lstCharCoords

    if charEdDe == 'e':
         #Control for wrapping
         if lstOutputCoords[0][1] == 4:
              lstOutputCoords[0][1] = 0
              lstOutputCoords[1][1] += 1
         elif lstOutputCoords[1][1] == 4:
              lstOutputCoords[1][1] = 0
              lstOutputCoords[0][1] += 1
         else:
              lstOutputCoords[0][1] += 1
              lstOutputCoords[1][1] += 1
    elif charEdDe == 'd':
         #control for wrapping
         if lstOutputCoords[0][1] == 0:
              lstOutputCoords[0][1] = 4
              lstOutputCoords[1][1] -= 1
         elif lstOutputCoords[1][1] == 0:
              lstOutputCoords[1][1] = 4
              lstOutputCoords[0][1] -= 1
         else:
              lstOutputCoords[0][1] -= 1
              lstOutputCoords[1][1] -= 1

    return lstOutputCoords

def encrypt(strPlaintext, lstKeyMatrix):

    lstDigraphs = generateDigraphs(strPlaintext)
    strCiphertext = ""

    for digraph in lstDigraphs:

         lstCharCoords = enumerateKeyMatrix(digraph, lstKeyMatrix)
         lstCipherCoords = [ [] , [] ]

         #If the row values are the same then we apply
         #digraph rule 2 as it is the only possibility
         if lstCharCoords[0][0] == lstCharCoords[1][0]:
              lstCipherCoords = colDigraphRule(lstCharCoords, 'e')

         #If the column values are the same then we apply
         #digraph rule 3 as it is the only possibility
         if lstCharCoords[0][1] == lstCharCoords[1][1]:
              lstCipherCoords = rowDigraphRule(lstCharCoords, 'e')

         #All other possible digraphs fall into the rectangle rule
         else:
              lstCipherCoords = rectDigraphRule(lstCharCoords)

         #Get the characters from the updated coordinates
         #and append them to the ciphertext
         strCiphertext += lstKeyMatrix[lstCipherCoords[0][0]][lstCipherCoords[0][1]] + lstKeyMatrix[lstCipherCoords[1][0]][lstCipherCoords[1][1]]

    return strCiphertext

def decrypt(strCiphertext, lstKeyMatrix):
     strPlaintext = ""
     lstDigraphs = generateDigraphs(strCiphertext)

     for digraph in lstDigraphs:
         lstCharCoords = enumerateKeyMatrix(digraph, lstKeyMatrix)
         lstPlainCoords = [ [] , [] ]

         #If the row values are the same then we apply
         #digraph rule 2 as it is the only possibility
         if lstCharCoords[0][0] == lstCharCoords[1][0]:
              lstPlainCoords = colDigraphRule(lstCharCoords, 'd')

         #If the column values are the same then we apply
         #digraph rule 3 as it is the only possibility
         if lstCharCoords[0][1] == lstCharCoords[1][1]:
              lstPlainCoords = rowDigraphRule(lstCharCoords, 'd')

         #All other possible digraphs fall into the rectangle rule
         else:
              lstPlainCoords = rectDigraphRule(lstCharCoords)

         #Get the characters from the updated coordinates
         #and append them to the plaintext
         strPlaintext += lstKeyMatrix[lstPlainCoords[0][0]][lstPlainCoords[0][1]] + lstKeyMatrix[lstPlainCoords[1][0]][lstPlainCoords[1][1]]

     return strPlaintext

def main():
    dictIO = { 1: "Welcome to the playfair cipher program!.\n", 
               2: "Would you like to encrypt or decrypt a string? [e/d]\n", 
               3: "Insert a string you would like to encrypt: ", 
               4: "Insert a string you would like to decrypt: ", 
               5: "Your encrypted string is: ", 
               6: "Your decrypted string is: ", 
               7: "Type in your password: ", 
               8: "Would you like to continue? [y/n]\n", 
               9: "Goodbye!" }
    isLoop = True
    print(dictIO[1])
    while isLoop == True:
         lstKeyMatrix = generateKeyMatrix(raw_input(dictIO[7]))
         if raw_input(dictIO[2]) == 'e':
              strPlaintext = raw_input(dictIO[3])
              strCiphertext = encrypt(strPlaintext, lstKeyMatrix)
              print(dictIO[5] + strCiphertext)
         else:
              strCiphertext = raw_input(dictIO[4])
              strPlaintext = decrypt(strCiphertext, lstKeyMatrix)
              print(dictIO[6] + strPlaintext)
         if raw_input(dictIO[8]) != 'y':
              print(dictIO[9])
              isLoop = False

main()

