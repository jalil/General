def fizzBuzz(n):
	for element in [('Fizz buzz!',x) if x % 15 == 0 else (('Fizz!',x) if x % 5 == 0 else (('Buzz!',x) if x % 3 == 0 else None)) for x in range(n)]:
		if element: print '%s Our current number is %i' %(element[0], element[1])

def main():
	fizzBuzz(100)

if __name__ == '__main__':
	main() 
