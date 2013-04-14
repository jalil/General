#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

string intToStr(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}


string repeatChar(char c, int n) {
	int i;
	string out = "";
	for (i = 0; i < n; i++) {
		out += c;
	}
	return out;
}

map<int,int> makeDistribution(vector<int> vDist) {
	int i, min, max;
	map<int, int> mDist;

	for (vector<int>::iterator it = vDist.begin(); it != vDist.end(); it++) {
		//add values from vector to map
		if (mDist.find(*it) == mDist.end()) {
			mDist[*it] = 1;
		}
		else {
			mDist[*it] += 1;
		}
		//persist max and min of range of the data set
		if (it == vDist.begin()) {
			min = *it;
		}
		else if (it == vDist.end() - 1) {
			max = *it;
		}
	}
	for (i = min; i < max + 1; i++) {
		if (mDist.find(i) == mDist.end()) {
			mDist[i] = 0;
		}
	}
	
	return mDist;
}

void printDist( map<int, int> mDist) {
	string lineout;
	for (map<int, int>::iterator it = mDist.begin(); it != mDist.end(); it++) {
		lineout = intToStr(it->first) + "|" + repeatChar('*', it->second);
		cout << lineout << endl;
	}
}

int main(int argc, const char *argv[]) {
	int i, j, k;
	vector<int> datapoints;

	cout << "How many data points would you like to add to the data set:\n  -->  ";
	cin >> j;

	for (i = 0; i < j; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> k;
		datapoints.push_back(k);
	}

	cout << "The distribution of points is :" << endl;
	printDist(makeDistribution(datapoints));
	
	return 0;
}


