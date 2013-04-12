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

double sampleVariance(vector<double> sampleData, double mean) {
	double sigmaTerm = 0;
	
	for(vector<double>::iterator it = sampleData.begin(); it != sampleData.end(); it++) {
		sigmaTerm += exponent(*it - mean, 2);
	}

	return sigmaTerm / (sampleData.capacity() - 1);
}

double sampleStandardDev(double sampleVariance) {
	return squareRoot(sampleVariance);
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

	cout << "From the listed values, the mean is " << mean(ins) << " and the sample variance is " << sampleVariance(ins, mean(ins)) << " and the sample standard deviation is " << sampleStandardDev(sampleVariance(ins, mean(ins))) <<  endl;
	return 0;
}

