/* Goal of this program is to find the second highest integer in an integer array*/
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
	int h,i,j,k;

	cout << "How many elements would you like to put in your array: ";
	cin >> k;

	//initialize integer array
	int a[k];
	for (i = 0; i < k; i++) {
		cout << "Index " << i <<":";
		cin >> j;
		a[i] = j;
	}

	//Find the second highest value by persisting the highest value and second highest value
	// i -> iterator, j -> second highest, h -> highest val, a -> int array, k -> upper bound
	h = -9999;
	j = -10000;
	

	for (i = 0; i < k; i++) {
		if (a[i] >= h) {
			if (a[i] == h) {
				j = h;
			}
			else {
				j = h;
				h = a[i];
			}
		}
		else if (a[i] > j) {
			j = a[i];
		}
	}

	cout << "The highest value of the array is " << h << " and the second highest is " << j << endl;
	return 0;
}

