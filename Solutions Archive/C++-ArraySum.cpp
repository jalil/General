#include <iostream>
using namespace std;

int sum(const int arr[], const int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	bool isloop = true;
	char charInput;
	int lenArray, summation;
	cout << "Welcome to the integer array summation program!" << endl;
	while (isloop == true) {
		cout << "Please enter the number of elements you would like in your integer array: ";
		cin >> lenArray;
		cout << "You have chosen to have an array of  " << lenArray << " elements" << endl;
		cout << "Please enter the elements below: " << endl;
		int arr[lenArray];
		for (int i = 0; i < lenArray; i++) {
			cin >> arr[i];
		}
		summation = sum(arr, lenArray);
		cout << "The summation of your array of length " << lenArray << " is " << summation << endl;
		cout << "Would you like to continue? [y/n]" << endl;
		cin >> charInput;
		if (charInput != 'y') {
			cout << "Goodbye!" << endl;
			isloop = false;
		}
	}
	return 0;
}

