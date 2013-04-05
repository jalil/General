#include <iostream>
using namespace std;

int main() {
	int i;
	cout << "What is the meaning of life?" << endl;
	while (true) {
		cout << "Give me a number that represents the meaning of Life, the Universe, and Everything: " << endl;
		cin >> i;
		if ( i <= 0 || i > 100) {
			cout << "Give me a number that is between 1 and 100, you fool!" << endl;
		}
		else if (i == 42) {
			cout << "That is it! I always knew you would know." << endl;
			break;
		}
		else {
			cout << "You're in the right range with " << i << ", but that isn't it." << endl;
		}
	}
	return 0;
}

