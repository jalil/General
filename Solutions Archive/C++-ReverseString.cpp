#include <iostream>
#include <string>

using namespace std;

string reverseStr(string in) {
	string out = "";
	int i, len = in.length();
	for (i = len - 1; i > -1; i--) {
		out += in[i];
	}
	return out;
}

int main(int argc, const char *argv[]) {
	string s, rs;
	cout << "What type would you like to reverse?\n  -->  ";
	cin >> s;
	
	rs = reverseStr(s);

	cout << "Your input string '" << s << "' has become '" << rs << "'!" << endl;
	return 0;
}

