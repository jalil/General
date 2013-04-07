#include <iostream>
#include <string>

using namespace std;

string removeChar(string s, char c);

int main(int argc, const char *argv[]) {
	char c;
	string i, j; 
	cout << "Give me a string: ";
	cin >> i;
	cout << "Give me a character you would like to remove from the string: ";
	cin >> c;
	
	j = removeChar(i, c);

	cout << "Your string " << i << " with all of the " << c << " characters removed is " << j << endl;
	return 0;
}

string removeChar(string s, char c) {
	int i, l = s.length();
	string o = "";

	for ( i = 0; i < l; i++) {
		if (s[i] != c) {
			o = o + s[i];	
		}
	}
	return o;
}

	
