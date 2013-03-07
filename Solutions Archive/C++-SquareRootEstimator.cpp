#include <iostream>
using namespace std;

double squareRoot( double num) { 
	double low = 1.0;
	double high = num;
	for (int i = 0; i < 30; i++) {
		double currEst = (high + low) / 2;
		if (currEst * currEst > num) {
			high = currEst;
		}
		else if (currEst * currEst == num) {
			return currEst;
		}
		else {
			low = currEst;
		}
		if (i == 29) {
			return currEst;
		}
	}
	return -1;
}

int main() {
	char continueLoop;
	bool isloop = true;
	double num, sqroot;
	cout << "Welcome to the square root algorithm!" << endl;
	while (isloop == true) {
		cout << "What is the value that you would like to take the square root of?" << endl;
		cin >> num;
		sqroot = squareRoot(num);
		cout << "The square root of " << num << " is " << sqroot << endl;
		cout << "Would you like to continue? [y/n]" << endl;
		cin >> continueLoop;
		if (continueLoop != 'y') {
			cout << "Goodbye!" << endl;
			isloop = false;
		}
	}
	return 0;
}

