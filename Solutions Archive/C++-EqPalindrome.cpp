#include <iostream>
#include <string>

using namespace std;

string reverseString(string s1);
bool checkPalindrome(string s1, string s2);

int main( int argc,  const char *argv[]) {
	string i,j;
		
	cout << "Welcome to the check palindrome program!\nGive me a string: ";
	cin >> i;
	j = reverseString(i);
	if (checkPalindrome(i,j) == true) {
		cout << "This is a  palindrome!" << endl;
	}
	else {
		cout << "This is not palindrome!" << endl;
	}

	return 0;
}

string reverseString(string s1) {
	string s2 = "";
	int i, j = s1.length();

	for (i = 0; i < j; i++) {
		s2 = s2 + s1[j - i - 1];
	}
	return s2;
}

bool checkPalindrome(string s1, string s2) {
	if ( s1 == s2) {
		return true;
	}
	else {
		return false;
	}
}


