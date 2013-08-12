def floatMaths(num1, num2):
	addition = num1 + num2
	subtraction = num1 - num2
	multiplication = num1 * num2
	floatDivision = num1 / num2
	exponentiation = num1 ** int(num2)

	print 'Given the numbers %.2f and %.2f, we have performed some computations:' %(num1, num2)
	print '  Addition: %.2f + %.2f = %.2f' %(num1, num2, addition)
	print '  Subtraction: %.2f - %.2f = %.2f' %(num1, num2, subtraction)
	print '  Multiplication: %.2f * %.2f = %.2f' %(num1, num2, multiplication)
	print '  Integer Division: %.2f / %.2f = %.2f' %(num1, num2, floatDivision)
	print '  Exponentiation: %.2f^%i = %.2f' %(num1, num2, exponentiation)

def main():
	floatMaths(13.0,8.5)
if __name__ == '__main__':
	main()
