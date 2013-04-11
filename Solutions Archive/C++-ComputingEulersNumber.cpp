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

long double computeEuler(int upperBound) {
	int i;
	double denom, placeVal;
	long double e = 0.0;
	
	for (i = 0; i < upperBound; i++) {
		denom = factorial(i);
		placeVal = (1/denom);
		cout << placeVal;
		e += placeVal;
	}

	return e;
}

int main(int argc, const char *argv[]) {
	int in;
	long double out;

	cout << "What would you like the upper bound of our estimate of Euler's number to be: ";
	cin >> in;

	out = computeEuler(in);	
	cout << "Euler's number to with an upper bound of " << in << " is " << out << endl;
	return 0;
}
	
