#include <iostream>

using namespace std;

double dAbs(double in) {
	if (in >= 0) {
		return in;
	}
	else {
		return -in;
	}
}

double experimentalError(double observed, double expected) {
	return ((dAbs(observed - expected) / expected) * 100);
}

int main(int argc, const char *argv[]) {
	double obs, exp;

	cout << "What is your observed value: ";
	cin >> obs;

	cout << "What is your expected value: ";
	cin >> exp;

	cout << "The percent error coming from an expected value of " << exp << " and an observed value of " << obs << " is " << experimentalError(obs, exp) << "% error" << endl;
	return 0;
}
	 
