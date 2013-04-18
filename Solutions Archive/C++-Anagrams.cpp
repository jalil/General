#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


void bubbleSort(string& in) {
	int sorted;
	while (sorted != 0) {
		sorted = 0;
		for (string::iterator it = in.begin(); it != in.end(); it++) {
			if (it + 1 != in.end()) {
				if (*it > *(it + 1)) {
					iter_swap(it, it + 1);
					sorted += 1;
				}
			}
		}
	}
	//return in;
}

bool anagrams(string s1, string s2) {
	int i;
	if (s1.length() != s2.length()) { 
		return false;
	}
	else {
		bubbleSort(s1);
		cout << s1 << endl;
		bubbleSort(s2);
		cout << s2 << endl;
		return s1 == s2;
//		cout << "first " << bubbleSort(s1) << " second " << bubbleSort(s2) << endl;
//		return (bubbleSort(s1) == bubbleSort(s2));
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


