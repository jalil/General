#include <iostream>
#include <string>

using namespace std;

bool checkPalindrome(string s1);

int main(int argc, const char *argv[]) {
	string i;
	cout << "Give me a string: ";
	cin >> i;

	if (checkPalindrome(i) == true) {
		cout << i << " is a palindrome!" << endl;
	}
	else {
		cout << i << " is not a palindrome" << endl;
	}
	return 0;
}

bool checkPalindrome(string s1) {
	int i, k = s1.length();
	
	for (i = 0 ; i < k; i++) {
		if (s1[i] != s1[k - i - 1]) {
			return false;
		}
	}
	return true;
}

