def recursivePalindromeCheck(s):
	if len(s) <= 2:
		if len(s) == 2:
			return s[0] == s[1]
		else:
			return True
	else:
		return recursivePalindromeCheck(s[1:-1])

def slicePalindromeCheck(s):
	return s[::-1] == s


print recursivePalindromeCheck('racecar')
print slicePalindromeCheck('racecar')
