#include <iostream>
#include <vector>

using namespace std;

int linearSearch(int iIn, vector<int> vIn) {
	//vIn -> vector input; iIn -> integer input
	for (vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++) {
		if (*it == iIn) {
			return (it - vIn.begin());
		}
	}
	return -1;
}

int main(int argc, const char *argv[]) {
	vector<int> inputs;
	int i, j, k, l;

	cout << "How many elements would you like to add to the vector?\n  -->  ";
	cin >> j;

	for (i = 0; i < j; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> k;
		inputs.push_back(k);
	}

	cout << "Give me a value to search for: ";
	cin >> k;

	l = linearSearch(k,inputs);
	
	if (l != -1) {
		cout << "The search value, " << k << " was found at index " << l << endl;
	}
	else {
		cout << "The search value, " << k << ", does not exist in the vector." << endl;
	}
	return 0;
}
 
