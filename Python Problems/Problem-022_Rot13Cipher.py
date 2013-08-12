def rot13(s1):
	s2, alphabet = '', 'abcdefghijklmnopqrstuvwxyz'
	for char in range(len(s1)): s2 += alphabet[(alphabet.index(s1[char]) + 13) % 26]
	return s2

print rot13('braden')

print rot13(rot13('braden'))
