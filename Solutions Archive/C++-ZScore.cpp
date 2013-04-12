#include <iostream>
#include <vector>

using namespace std;

double squareRoot(double num) {
	int i;
	double low = 1.0;
	double currEst, high = num;
	for (i = 0; i < 30; i++) {
		currEst = (high + low) / 2;
		if (currEst * currEst > num) {
			high = currEst;
		}
		else if (currEst * currEst == num) {
			return currEst;
		}
		else {
			low = currEst;
		}
	}
	return currEst;
}

double exponent(double base, int exp) {
	int i;
	double out = 1;

	for (i = 0; i < exp; i++) {
		out = out * base;
	}
	return out;
}

double mean(vector<double> vec) {
	double accumulator = 0;

	for (vector<double>::iterator it = vec.begin(); it != vec.end(); it++) {
		accumulator += *it;
	}
	return accumulator / vec.capacity();
}

double popVariance(vector<double> popData, double mean) {
	double sigmaTerm = 0;
	
	for(vector<double>::iterator it = popData.begin(); it != popData.end(); it++) {
		sigmaTerm += exponent(*it - mean, 2);
	}

	return sigmaTerm / popData.capacity();
}

double popStandardDev(double popVariance) {
	return squareRoot(popVariance);
}

double zScore(double x, double mu, double stdDev) {
	return ((x - mu) / stdDev);
}

int main(int argc, const char *argv[]) {
	int i, j;
	double k;
	vector<double> ins;
	
	cout << "How many elements would you like to add to the data set?\n -->  ";
	cin >> j;


	for (i = 0; i < j; i++) {
		cout << "Element " << i + 1<< ": ";
		cin >> k;
		ins.push_back(k);
	}

	cout << "From the listed values, the mean is " << mean(ins) << " and the population variance is " << popVariance(ins, mean(ins)) << " and the population standard deviation is " << popStandardDev(popVariance(ins, mean(ins))) <<  endl;
	cout << "Give me a value to test: ";
	cin >> k;
	cout << "The z-score computed at " << k << " is " << zScore(k, mean(ins), popStandardDev(popVariance(ins, mean(ins)))) << endl;

	return 0;
}

