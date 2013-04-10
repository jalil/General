#include <iostream>
#include <sstream>
using namespace std;

string convertInt(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

int main(int argc, const char *argv[]) {
	int n;
	string s;

	cout << "Give me an integer: ";
	cin >> n;

	s = convertInt(n);
	cout << "Your integer " << n << " is now the string '" << s << "'" << endl;
	return 0;
}
