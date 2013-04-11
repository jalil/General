#include <iostream>
#include <vector>

using namespace std;

double mean(vector<double> vec) {
	double accumulator = 0;

	for (vector<double>::iterator it = vec.begin(); it != vec.end(); it++) {
		accumulator += *it;
	}
	return accumulator / vec.capacity();
}

int main(int argc, const char *argv[]) {
	int i, j;
	double k;
	vector<double> ins;
	
	cout << "How many elements would you like to add: ";
	cin >> j;


	for (i = 0; i < j; i++) {
		cout << "Element " << i + 1<< ": ";
		cin >> k;
		ins.push_back(k);
	}

	cout << "From the listed values, the mean is " << mean(ins) << endl;
	return 0;
}

