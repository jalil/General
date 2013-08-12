def encryptCaesarCipher(plaintext, indexShift):
	ciphertext, alphabet = '', 'abcdefghjklmnopqrstuvwxyz'
	for char in range(len(plaintext)): ciphertext += alphabet[(alphabet.index(plaintext[char]) + indexShift) % 26]
	return ciphertext


def decryptCaesarCipher(ciphertext, indexShift):
	plaintext, alphabet = '', 'abcdefghijklmnopqrstuvwxyz'
	for char in range(len(ciphertext)): plaintext += alphabet[(alphabet.index(ciphertext[char]) - indexShift) % len(alphabet)]

	return plaintext


print encryptCaesarCipher('braden', 8)
print decryptCaesarCipher('kzjmnv', 8)

print decryptCaesarCipher(encryptCaesarCipher('braden', 8), 8)
	

