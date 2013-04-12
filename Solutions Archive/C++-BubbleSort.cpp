#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bubbleSort(vector<int> vec) {
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
	return vec;
}

int main(int argc, const char *argv[]) {
	int i, j;
	vector<int> avec;
	for (i = 0; i < 5; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> j;
		avec.push_back(j);
	}
	avec = bubbleSort(avec);
	cout << "\nThe sorted list is as follows: " << endl;
	for (vector<int>::iterator it = avec.begin(); it != avec.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
  
	
