#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> makeChange(int c) {
	map<string, int> mChange;
	mChange["Quarters"] = 0;
	mChange["Dimes"] = 0;
	mChange["Nickels"] = 0;
	mChange["Pennies"] = 0;

	while (c != 0) {
		if (c - 25 >= 0) {
			c -= 25;
			mChange["Quarters"] += 1;
		}
		else if (c - 10 >= 0) {
			c -= 10;
			mChange["Dimes"] += 1;
		}
		else if (c - 5 >= 0) {
			c -= 5;
			mChange["Nickels"] += 1;
		}
		else {
			c -= 1;
			mChange["Pennies"] += 1;
		}
	}

	return mChange;
}

int main(int argc, const char *argv[]) {
	int i;
	map<string, int> changeMap;

	cout << "How many cents would you like to convert to coins?\n  -->  ";
	cin >> i;

	changeMap = makeChange(i);

	cout << i << " cents becomes: " << endl;

	for (map<string, int>::iterator it = changeMap.begin(); it != changeMap.end(); it++) {
		cout << it->second << " " << it->first << endl;
	}
	return 0;
}

	
