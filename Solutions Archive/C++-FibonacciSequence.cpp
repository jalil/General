#include <iostream>
using namespace std;

int fib(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

int main() {
	char charInput;
	int n, result;
	bool isloop = true;
	cout << "Welcome to the Fibonacci  Sequence generator!" << endl;
	while (isloop == true) {
		cout << "What is the number of the fibonacci number you would like to compute?" << endl;
		cin >> n;
		result = fib(n);
		cout << "The " << n << "-th fibonacci number is " << result << endl;
		cout << "Would you like to continue? [y/n]" << endl;
		cin >> charInput;
		if (charInput != 'y') {
			cout << "Goodbye!" << endl;
			isloop = false;
		}
	}
	return 0;
}

