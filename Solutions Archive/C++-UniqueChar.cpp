#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> makeMap(string s) {
	int i;
	map<char, int> mString;

	for (i = 0; i < s.length(); i++) {
		if (mString.find(s[i]) == mString.end()) {
			mString[s[i]] = 1;
		}
		else {
			mString[s[i]] += 1;
		}
	}
	return mString;
}

bool isUnique(map<char, int> sMap) {
	for (map<char, int>::iterator it = sMap.begin(); it != sMap.end(); it++) {
		if (it->second >= 2) {
			return false;
		}
	}
	return true;
}

int main(int argc, const char *argv[]) {
	string s;

	cout << "Give me a string to check: ";
	cin >> s;
	
	cout << "Are all of the characters in the string, '" << s << "', unique?\n  --> " << (isUnique(makeMap(s)) == 1 ? "True" : "False") << endl;
	return 0;
}

