#include <iostream>

using namespace std;

int derangements(int n) {
	if (n == 0) {
		return 1;
	}
	else if ( n == 1 ) {
		return 0;
	}
	else {
		return (n - 1) * (derangements(n - 1) + derangements(n - 2));
	}
}

int main(int argc, const char *argv[]) {
	int n;
	cout << "What is the number of derangements you would like to compute?\n  -->  ";
	cin >> n;
	cout << "The number " << n << " has yielded " << derangements(n) << " derangements" << endl;
	return 0;
}

