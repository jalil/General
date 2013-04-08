#include <iostream>
#include <string>

using namespace std;

string replaceChar(string s, char c);

int main(int argc, const char *argv[]) {
	string s1, s2;
	char c;
	cout << "Give me a string: ";
	cin >> s1;
	cout << "Give me a character: ";
	cin >> c;
	
	s2 = replaceChar(s1, c);
	
	cout << s1 << " becomes " << s2 << " after having the '" << c <<"' characters removed" << endl;
	
	return 0;
}

string replaceChar(string s, char c) {
	string replaced = "";
	while (s.find(c) != string::npos) {
		s = s.replace(s.find(c), 1, replaced);
	}
	return s;	
}

