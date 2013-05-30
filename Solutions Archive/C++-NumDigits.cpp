#include <iostream>


int integerExponentiation(int base, int exp) {
	int i, out = 1;
	for (i = 0; i < exp; ++i) {
		out *= base;
	}
	return out;
}

template <typename T>
int numDigits(T num) {
	int n = (int) num, i = 0;
	while (num != 0) {
		num /= 10;
		++i;
	}
	return i;
}

int indexInt(int n, int idx) {
	if (idx > numDigits(n) || idx < 0) {
		return -1;
	}
	else {
		int exp = integerExponentiation(10, idx);
		std::cout << exp << " and " << n / exp << " and " << (n / exp) * exp << std::endl;
		return n % (n / exp);
		//return n % ((n / exp) * exp);
	}
}

int main(int argc, const char *argv[]) {
	int n, i;
	std::cout << "Give me an integer: ";
	std::cin >> n;
	std::cout << "Give me an index to look up: ";
	std::cin >> i;

	std::cout << "With the integer '" << n << "' and at the index '" << i << "' you have the digit '" << indexInt(n, i) << "'" << std::endl;
	return 0;
}
