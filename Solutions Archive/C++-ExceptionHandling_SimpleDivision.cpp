#include <iostream>

int main(void) {
	int a,b,c;
	std::cout << "Give me the first integer: ";
	std::cin >> a;

	std::cout << "Give me the second integer: ";
	std::cin >> b;

	try { 
		if (b == 0) {
			throw 0;
		}
		else {
			std::cout << "The expression " << a << " / " << b << " = " << a / (float) b << std::endl;
		}
	}
	catch(int i) {
		if (i == 0) {
			std::cout << "You can't divide by zero!"  << std::endl;
		}
	}
	return 0;
}

