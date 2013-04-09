#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
	int out[] = {0,0,0,1000}; //[pmax, maxval, pmin, minval]
	int k, in[10];
	for (k = 0; k < 10; k++) {
		cout << "Person " << k << " has had how many pancakes?\n->";
		cin >> in[k];
	}
	for (k = 0; k < 10; k++) {
		if (in[k] > out[1]) {
			out[0] = k;
			out[1] = in[k];
		}

		if (in[k] < out[3]) {
			out[2] = k;
			out[3] = in[k];
		}
	}

	cout << "The biggest glutton is person " << out[0] << " who ate " << out[1] << " pancakes." << endl;
	cout << "The skinniest person is person " << out[2] << " who only ate " << out[3] << " pancakes." << endl;
	return 0;
}
