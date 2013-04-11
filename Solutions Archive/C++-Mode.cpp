#include <iostream>
#include <map>

using namespace std;

double mode(map<double , int > &mMode) {
	double dMax = 0;
	int iMax = 0;
	for (map<double, int>::iterator it = mMode.begin(); it != mMode.end(); it++) {
		if (it->second > iMax) {
			dMax = it->first;
			iMax = it->second;
		}
	}
	return dMax;
}
	

int main(int argc, const char *argv[]) {
	int i, j;
	double k;

	std::map<double, int> mVals;

	cout << "How many elements would you like to add: ";
	cin >> j;

	for (i = 0; i < j; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> k;
		if (mVals.find(k) == mVals.end()) {
			mVals[k] = 1;
		}
		else {
			mVals[k] += 1;
		}
	}
	
	cout << "The mode of the input elements is " << mode(mVals) << endl;
	return 0;
}


	
