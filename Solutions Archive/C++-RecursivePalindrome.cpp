#include <iostream>
#include <string>

using namespace std;

bool recursivePalindrome(string s1);

int main(int argc, const char *argv[]) {
	string i;
	cout << "Give me a string to check: ";
	cin >> i;

	if (recursivePalindrome(i) == true) {
		cout << "It's a palindrome!" << endl;
	}
	else {
		cout << "It isn't a palindrome!" << endl;
	}
	
	return 0;
}

bool recursivePalindrome(string s1) {
	int k = s1.length();
	
	if (k == 1 || k == 0) {
		return true;
	}
	else {
		if (s1[0] == s1[k - 1]) {
			return recursivePalindrome(s1.substr(1,k-2));
		}
		else {
			return false;
		}
	}
}
	
