#include <iostream>

using namespace std;

int factorial(int n) {
	int i, o = 1;
	for (i = n; i > -1; i--) {
		if (i == 0) {
			o = o * 1;
		}
		else {
			o = o * i;
		}
	}
	return o;
}

int main(int argc, const char *argv[]) {
	int i,o;
	cout << "What is the factorial you would like to compute: ";
	cin >> i;
	o = factorial(i);
	cout << "The factorial, " << i << "!, is " << o << endl;
	return 0;
}

