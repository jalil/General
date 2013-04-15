#include <iostream>
#include <string>

using namespace std;

string reverseString(string sIn) {
	int i;
	string sOut = "";

	for (i = sIn.length() - 1; i > -1; i--) {
		sOut += sIn[i];
	}
	return sOut;
}		

string encrypt(string plaintext, string cipherAlphabet) {
	int i;
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ", ciphertext = "";
	for (i = 0; i < plaintext.length(); i++) {
		ciphertext += cipherAlphabet[alphabet.find(plaintext[i])];
	}
	return ciphertext;

}

string decrypt(string ciphertext, string cipherAlphabet) {
	int i;
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ", plaintext = "";
	for (i = 0; i < ciphertext.length(); i++) {
		plaintext += alphabet[cipherAlphabet.find(ciphertext[i])];
	}
	return plaintext;
}

int main(int argc, const char *argv[]) {
	string in;
	const string CIPHER = reverseString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");

	cout << "Give me a plaintext: ";
	getline(cin,in);

	cout << "The expression encrypt(\"" << in << "\") yields \"" << encrypt(in, CIPHER) << "\"" << endl;
	cout << "The expression decrypt(encrypt(\"" << in << "\")) yields \"" << decrypt(encrypt(in, CIPHER), CIPHER) << "\"" << endl;
	return 0;
}

