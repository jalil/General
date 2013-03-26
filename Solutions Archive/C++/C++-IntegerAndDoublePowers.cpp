#include <iostream>
using namespace std;

int integerPowers(int base, int exponent) {
	int result = 1;
	for (int i = 0; i < exponent; i++) {
		result = result * base;
	}
	return result;
}

double floatPowers(double base, int exponent) {
	double result = 1.0;
	for (int i = 0; i < exponent; i++) {
		result = result * base;
	}
	return result;
}



int main() {
	bool isloop = true;
	char inputChar;
	int base, exponent, result;
	double dbase, dresult;
	cout << "Welcome to the raise to power algorithm!" << endl;
	while (isloop == true) {
		cout << "Would you like to raise an integer or a floating point value to a power? [i/f]" << endl;
		cin >> inputChar;
		if (inputChar == 'i') {
			cout << "What is the integer base of the exponentiation?" << endl;
			cin >> base;
			cout << "What is the exponent that the integer base is evaluated to?" << endl;
			result = integerPowers(base, exponent);
			cout << "The result of the base " << base << " raised to " << exponent << " is " << result << endl;
		}
		else {
			cout << "What is the floating point base of the exponentiation?" << endl;
			cin >> dbase;
			cout << dbase;
			cout << "What is the exponent that the floating point base is evaluated to?" << endl;
			cin >> exponent;
			dresult = floatPowers(dbase, exponent);
			cout << "The result of the base " << dbase << " raised to " << exponent << " is " << dresult << endl;
		}
		cout << "Would you like to continue? [y/n]" << endl;
		cin >> inputChar;
		if (inputChar != 'y') {
			cout << "Goodbye!" << endl;
			isloop = false;
		}
	}
	return 0;
}

	
				
