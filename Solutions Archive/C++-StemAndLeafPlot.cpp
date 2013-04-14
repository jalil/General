#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string intToStr(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

void  bubbleSort(vector<int>& vec) {
	int sorted ;
	while (sorted != 0) {
		sorted = 0;
		for (vector<int>::iterator i = vec.begin(); i != vec.end(); i++) {
			if (i + 1 != vec.end()) {
				if (*i > *(i + 1)) {
					iter_swap(i, i + 1);
					sorted += 1;
				}			 
			}	
		}
	}
}

map<int, vector<int> > computeSLDist(vector<int> vDist) {
	const int BASE = 10;
	int k, v;
	vector<int> tempVec;
	map<int, vector<int> > mDist;

	//add values to map
	for (vector<int>::iterator it = vDist.begin(); it != vDist.end(); it++) {
		if ( *it < BASE && *it >= 0 ) {
			k = 0;
			v = *it;
		}
		else {
			k = *it / BASE;
			v = *it % (k * BASE);
		}
		
		if (mDist.find(k) == mDist.end()) {
			tempVec.push_back(v);
			mDist[k] = tempVec;
		}
		else {
			mDist[k].push_back(v);
		}
		tempVec.clear();
	}

	//order the values
	for (map<int, vector<int> >::iterator it = mDist.begin(); it != mDist.end(); it++) {
		bubbleSort(it->second);
	}
	return mDist;
}	

void printSALeaf(map<int, vector<int> > mDist) {
	string lineout;
	for(map<int, vector<int> >::iterator it = mDist.begin(); it != mDist.end(); it++) {
		lineout = intToStr(it->first) + " | ";
		for (vector<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {	
			lineout += intToStr(*it2) + ", ";
		}
		cout << lineout.substr(0,lineout.length() - 2) << endl;
	}
}

int main(int argc, const char *argv[]) {
	int i, j, k;
	vector<int> avec;
	map<int, vector<int> > amap;
	
	cout << "Number of elements you would like to add to the distribution: ";
	cin >> k;

	for (i = 0; i < k; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> j;
		avec.push_back(j);
	}
	amap = computeSLDist(avec);
	cout << "\nThe stem and leaf plot is as follows: " << endl;
	/*for (map< int, vector<int> >::iterator it = amap.begin(); it != amap.end(); it++) {
		for(vector<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			cout << it->first << " => " << *it2 << endl;
		}
	}*/
	printSALeaf(amap);
	return 0;
}
  
	
