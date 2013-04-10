#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
	bool out;
	switch(c) {
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
		case 'y':
		case 'Y':
			out = true;
			break;
		default:
			out = false;
			break;
	}
	return out;
}

string removeVowels(string s){ 
	int i;
	string out = "";
	for (i = 0; i < s.length(); i++) {
		if (!isVowel(s[i])) {
			out += s[i];
		}
	}
	return out;
}

int main(int argc, const char *argv[]) {
	string s1, s2;
	cout << "Give me a string: ";
	cin >> s1;

	s2 = removeVowels(s1);
	
	cout << "The string " << s1 << " without vowels is " << s2 << endl;
	return 0;
}
	
