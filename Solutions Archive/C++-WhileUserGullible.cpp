#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
	int i, o;
	i = 1;
	o = 0;
	do {
		o += 1;
		cout << "Enter any number aside from " << o << ": ";
		cin >> i;
	} while( i != o);
	return 0;
}


