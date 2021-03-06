#include <iostream>

using namespace std;

unsigned long int factorial(unsigned long int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

unsigned long int binomialCoefficient(unsigned long int n, unsigned long int k) {
	return ((factorial(n)) / (factorial(k) * factorial(n - k)));
}

int main(int argc, const char *argv[]) {
	unsigned long int n, k, o;
	cout << "Please give me the n value: ";
	cin >> n;

	cout << "Please give me the k value: ";
	cin >> k;

	o = binomialCoefficient(n,k);
	cout << "The binomial coefficient of " << n << " choose " << k << " is " << o << endl;
	return 0;
}

