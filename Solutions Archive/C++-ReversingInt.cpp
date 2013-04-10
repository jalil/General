#include <iostream>
#include <sstream>
using namespace std;

string reverseStr(string s) {
	string out = "";
	int i, len = s.length();

	for (i = len - 1; i > -1; i--) {
		out += s[i];
	}
	return out;
}

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

	s = reverseStr(convertInt(n));
	cout << "Your integer " << n << " becomes " << s << " when reversed." << endl;
	return 0;
}
