#include <iostream>

using namespace std;


int max(int vals[], int len) {
	int i, max = 0;
	
	for (i = 0; i < len; i++) {
		if (max < vals[i]) {
			max = vals[i];
		}
	}
	return max;
}

int min(int vals[], int len) {
	int i, min = 10000000;
	
	for (i = 0; i < len; i++) {
		if (min > vals[i]) {
			min = vals[i];
		}
	}
	return min;
}

int main(int argc, const char *argv[]) {
	const int ARRAY_MAX = 5;

	int maxval, minval, i, values[ARRAY_MAX];
	for (i = 0; i < ARRAY_MAX; i++) {
		cout << "Give me an integer value: ";
		cin >> values[i];
	}
	
	maxval = max(values, ARRAY_MAX);
	minval = min(values, ARRAY_MAX);
	cout << "The maximum of the input values is " << maxval << " and the minimum of the input values is " << minval <<"." << endl;
	return 0;
}

	
