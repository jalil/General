#Question: How does the stack relate to the nesting level?
#Answer: The stack contains the number of left open brackets and as such the stack length is equal to the number of nesting levels open.

#Added one-way opposite bracket function
def opposite(char):
	if char == '(':
		return ')'
	elif char == '{':
		return '}'
	elif char == '[':
		return ']'
	elif char == '<':
		return '>'

#Added nesting update function
def nesting_level(lst_stack, int_curr_highest):
	if len(lst_stack) > int_curr_highest:
		return len(lst_stack)
	else:
		return int_curr_highest

#Added error reporting function 
def error_message(char_expected, idx, char_received, intErrno):
	if intErrno == 1:
		return "Expected %s at character index %i, but received %s instead." %(char_expected, idx, char_received)
	elif intErrno == 2:
		return "The stack is empty. The character %s was received, but no open %s character was given" %(char_received, char_expected)
	else:
		return "The stack is not empty at EOF. The character %s was initially received, but no close %s character was given" %(char_received, char_expected)
def is_nested(str_input):

	stack = []
	int_curr_highest = 0

	for idx in range(0, len(str_input)): #Added idx 
		if str_input[idx] == "{"or str_input[idx] == "<" or str_input[idx] == "(" or str_input[idx] == "[":
			stack.append(str_input[idx])
			int_curr_highest = nesting_level(stack, int_curr_highest)
		elif str_input[idx] == "}":
			if len(stack) != 0:
				x = stack.pop()
				if x != '{':
					return error_message(opposite(x),idx, str_input[idx], 1) 
			else:
				return error_message(opposite(str_input[idx]), idx, str_input[idx - 1], 2)
		elif str_input[idx] == ']':
			if len(stack) != 0:
				x = stack.pop()
				if x != '[':
					return error_message(opposite(x), idx, str_input[idx], 1)
			else:
				return error_message(opposite(str_input[idx]), idx, str_input[idx - 1], 2)
		elif str_input[idx] == ')':
			if len(stack) != 0:	
				x = stack.pop()
				if x != '(':
					return error_message(opposite(x), idx, str_input[idx], 1)
			else:
				return error_message(opposite(str_input[idx]), idx, str_input[idx - 1], 2)

		#Controlling for angle brackets
		elif str_input[idx] == '>':
			if len(stack) != 0:
				x = stack.pop()
				if x != '<':
					return error_message(opposite(x), idx, str_input[idx], 1)
			else:
				return error_message(opposite(str_input[idx]), idx, str_input[idx - 1], 2)
	if stack != [] and len(stack) > 0:
		return error_message(opposite(stack[0]), 0, stack[0], 3)
	
	print("The highest indenting level was %i" %(int_curr_highest))
	return True

print is_nested("{[()}")
print is_nested("{[]({})}")
print is_nested("[()")
print is_nested("()]")

