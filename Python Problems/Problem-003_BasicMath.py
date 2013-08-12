def basicMaths(num1, num2):
	addition = num1 + num2
	subtraction = num1 - num2
	multiplication = num1 * num2
	integerDivision = num1 / num2
	moduloDivision = num1 % num2

	print 'Given the numbers %i and %i, we have performed some computations:' %(num1, num2)
	print '  Addition: %i + %i = %i' %(num1, num2, addition)
	print '  Subtraction: %i - %i = %i' %(num1, num2, subtraction)
	print '  Multiplication: %i * %i = %i' %(num1, num2, multiplication)
	print '  Integer Division: %i / %i = %i' %(num1, num2, integerDivision)
	print '  Modulo Division: %i %% %i = %i' %(num1, num2, moduloDivision)

def main():
	basicMaths(13,8)
if __name__ == '__main__':
	main()
