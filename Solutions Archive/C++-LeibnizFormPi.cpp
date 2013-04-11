#include <iostream>

using namespace std;

long double leibniz(unsigned long int upperBound) {
	int i;
	long double pi = 0;
	long double denom = 1;
	long double sequenceVal = 0;

	for (i = 0; i < upperBound; i++) {
		//compute place in sequence
		sequenceVal = (1/denom);
		if (i % 2 == 1) {
			sequenceVal = -sequenceVal;
		}
	
		//add to the pi value
		pi += sequenceVal;
		denom += 2;
	}
	//since pi/4 == sequence -> mult by 4
	return pi * 4;
}

int main(int argc, const char *argv[]) {
	unsigned long int i;
	long double pi;
	
	cout << "What is the number of places into the sequence that you would like to compute: ";
	cin >> i;

	pi = leibniz(i);

	cout << "The value of a pi after going to " << i << " places is " << pi << endl;
	return 0;
}

