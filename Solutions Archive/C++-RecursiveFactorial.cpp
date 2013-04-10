#include <iostream>

using namespace std;

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int main(int argc, const char *argv[]) {
	int i,o;
	cout << "What factorial would you like to compute: ";
	cin >> i;
	
	o = factorial(i);

	cout << "The factorial, " << i << "!, is " << o << endl;
	return 0;
}

