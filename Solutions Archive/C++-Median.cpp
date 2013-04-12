#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> bubbleSort(vector<double> dVec) {
	int swaps;

	while (swaps != 0) {
		swaps = 0;
		for (vector<double>::iterator it = dVec.begin(); it != dVec.end(); it++) {
			if (it + 1 != dVec.end()) {
				if (*it > *(1 + it)) {
					iter_swap(it, it + 1);
					swaps += 1;
				}
			}
		}
		
	}
	return dVec;
}

double median(vector<double> dVec) {
	if (dVec.size() % 2 == 0) {
		return ((dVec[dVec.size() / 2] + dVec[(dVec.size() / 2) - 1]) / 2.0);
	}
	else {
		return dVec[dVec.size() / 2];
	}
}

int main(int argc, const char *argv[]) {
	int i, j;
	double k;
	vector<double> aVec;	

	cout << "What is the number of elements in your data set: ";
	cin >> j;

	for (i = 0; i < j; i++) {	
		cout << "Element " << i + 1 << ": ";
		cin >> k;
		aVec.push_back(k);
	}

	aVec = bubbleSort( aVec );
	
	cout << "\nThe sequence of the ordered vector is: " << endl;
	for (vector<double>::iterator i = aVec.begin(); i != aVec.end(); i++) {
		cout << *i << endl;
	}

	cout << "\nThe median of this data set is " << median(aVec) << endl;

	return 0;
}


