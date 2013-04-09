#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
	int i, o;
	o = 0;
	do {
		o += 1;
		cout << "Enter any number aside from " << o << ": ";
		cin >> i;
	} while( i != o);
	cout << "You weren't supposed to type in " << i << "!" << endl;
	return 0;
}


