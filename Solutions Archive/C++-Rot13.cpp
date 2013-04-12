#include <iostream>
#include <string>

using namespace std;

string cipher(string in) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string out = "";

	int i;

	for (i = 0; i < in.length(); i++) {
		//we assume that the character exists
		out += alphabet[(alphabet.find(in[i]) + 13) % 26];
	}
	return out;
}

int main(int argc, const char *argv[]) {
	string a = "braden";
	cout << cipher(a) << endl;
	cout << cipher(cipher(a)) << endl;
	return 0;
}

