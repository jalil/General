#include <iostream>
using namespace std;

int main() {
	int i;
	while (true) {
		cin >> i;
		if (i == 42 ||i >= 100 || i <= -100) {
			break;
		}
		else {
			cout << i << endl;
		}
	}
	return 0;
}

