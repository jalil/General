#include <iostream>

using namespace std;

int abs(int in) {
	 return (in >= 0 ? in : -in);
}

int main(int argc, const char *argv[]) {
	int i;

	cout << "Give me an integer: ";
	cin >> i;

	cout << "The expression abs(" << i << ") yields a value of " << abs(i) << endl;
	return 0;
}

