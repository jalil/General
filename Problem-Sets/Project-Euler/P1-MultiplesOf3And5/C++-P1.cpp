#include <iostream>

int mult3or5(int u) {
	int i,s = 0;
	for (i = 0; i < u; i++) {
		if ( i % 3 == 0 || i % 5 == 0) {
			s += i;
		}
	}
	return s;
}

int main(int argc, const char *argv[]) {
	int i,j;

	std::cout << "What is the upper bound of the summation of multiples of 3 and 5?\n  -->  ";
	std::cin >> i;

	j = mult3or5(i);

	std::cout << "The summation from 0 to " << i << " is " << j << std::endl;
	return 0;
}

