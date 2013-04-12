#include <iostream>
#include <string>

using namespace std;

string rot13(string in) {
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
	string a;

	cout << "Give me a string to encrypt: ";
	cin >> a;

	cout << "You gave me '" << a << "' which encrypts to " << rot13(a) << "!\nThe expression rot13(rot13('" << a << "')) yields '" << rot13(rot13(a)) << "'" << endl;

	return 0;
}

