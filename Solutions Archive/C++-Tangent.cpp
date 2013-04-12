#include <iostream>

using namespace std;

long unsigned int factorial(long unsigned int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

double exp(double base, int ex) {
	int i;
	double out = 1;

	for (i = 0; i < ex; i++) {
		out = out * base;
	}
	return out;
}

double cosine(double x) {
	int i;
	double placeVal, out = 0;
	
	for (i = 0; i < 10; i++) {
		placeVal = (exp(x, 2 * i) / factorial(2 * i));
		if (i % 2 != 0) {
			placeVal = -placeVal;
		}
		out += placeVal;
	}
	return out;
}


double sine(double x) {
	int i;
	double placeVal, out = 0;

	for (i = 0; i < 10; i++) {
		placeVal = (exp(x, 2 * i + 1) / factorial(2 * i + 1));
		if (i % 2 != 0) {
			placeVal = -placeVal;
		}
		out += placeVal;
	}
	return out;
}

double tangent(double x) {
	return sine(x) / cosine(x);
}


int main(int argc, const char *argv[]) {
	double x;

	cout << "What is the value of x where x is in radians: ";
	cin >> x;	
	cout << "The value of tangent(" << x << ") is " << tangent(x) << endl;

	return 0;
}

