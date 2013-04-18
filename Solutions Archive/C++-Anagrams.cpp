#include <iostream>
#include <string>

using namespace std;

bool anagrams(string s1, string s2) {
	int i , is1 = 0, is2 = 0;
	if (s1.length() != s2.length()) { 
		return false;
	}
	else {
		for (i = 0; i < s1.length(); i++) {
			is1 += s1[i];
			is2 += s2[i];
		}
		return (is1 == is2);
	}
}

int main(int argc, const char *argv[]){
	string sa, sb;
	
	cout << "Give me a string: ";
	cin >> sa;
	cout << "Give me another string: ";
	cin >> sb;

	if (anagrams(sa, sb)) {
		cout << "The string " << sa << " and the string " << sb << " are anagrams." << endl;
	}
	else {
		cout << "The string " << sa << " and the string " << sb << " are not anagrams." << endl;
	}
	return 0;
}


