#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char *argv[]) {
	int i, k[100];
	cout << "The goal of the program is to iterate through a list of values between 1-100 where we will determined whether or not there are any missing numbers in the range.\nGive me a number you would like repeated: ";
	cin >> i;

	//We will generate our list of values by first repeating the user defined input val
	//at index zero
	k[0] = i;
	for (i = 1; i < 101; i++) {
		k[i] = i;
	}

	//we will now create our hash table and fill it with values
	map <int, int> counts;
	for (i = 0; i < 101; i++) {
		if (counts.find(k[i]) == counts.end()) {
			counts[k[i]] = 1;
		}
		else {
			counts[k[i]] += 1;
		}
	}
	
	// find the duplicate number
	int repeatedval = 0;
	i = 0;
	
	while (counts.find(k[i]) != counts.end()) {
		if ( counts[k[i]] > 1) {
			repeatedval = k[i];
			break;
		}
		else{
			i = i + 1;
		}
	}
	cout << "The repeated value was " << repeatedval << endl;
	return 0;
}
	
