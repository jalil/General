#include <iostream>
#include <string>

using namespace std;

string encrypt(string in, int shift) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string out = "";

	int i;

	for (i = 0; i < in.length(); i++) {
		//we assume that the character exists
		out += alphabet[(alphabet.find(in[i]) + shift) % 26];
	}
	return out;
}

string decrypt(string in, int shift) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string out = "";
	
	int i;
	
	for (i = 0; i < in.length(); ++i) {
		if (shift > alphabet.find(in[i])) {
			out += alphabet[26 - (shift - alphabet.find(in[i]))];
		}
		else {
			out += alphabet[(alphabet.find(in[i]) - shift) % 26];
		}
	}

	return out;
}

int main(int argc, const char *argv[]) {
	string a;
	int i;

	cout << "Give me a string to encrypt: ";
	cin >> a;

	cout << "Give me an integer shift amount: ";
	cin >> i;

	i = i % 26; //shift range is only 0-25	

	cout << "You gave me '" << a << "' which encrypts to " << encrypt(a, i) << "!\nThe expression decrypt(encrypt('" << a << "', " << i << ")) yields '" << decrypt(encrypt(a, i), i) << "'" << endl;

	return 0;
}

