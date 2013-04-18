def anagram(instr):
	if len(instr) == 2:
		return [instr[1] + instr[0], instr]
	else:
		lst = []
		for i in range(len(instr)):
			if i == 0:
				lst.append(instr)
			elif i == len(instr) - 1:
				lst.append(instr[-1] + instr[:-1])
			else:
				lst.append(instr[i] + instr[:i] + instr[i + 1:])
		for element in lst:
			alst = anagram(element[1:])
			for item in alst:
				if element[0] + item not in lst:
					lst.append(element[0] + item)
	

	return lst
print anagram('ab')
print anagram('abc')
print anagram('abcd')
print len(anagram('braden'))
		
