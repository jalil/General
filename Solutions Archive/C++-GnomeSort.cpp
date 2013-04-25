#include <algorithm>
#include <iostream>
#include <vector>

std::string printVector(std::vector<int> v) {
	std::string s = "<";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		s += std::to_string(*it) + ", ";
	}
	return s.substr(0, s.length() - 2) + ">";
}

void gnomeSort(std::vector<int>& v) {
	std::vector<int>::iterator itv = v.begin();
	while (itv != v.end()) {
		if (*itv > *(itv + 1)) {
			std::iter_swap(itv, itv + 1);
			if (itv != v.begin()) {
				itv--;
			}
		}
		else {
			itv++;
		}
	}
}

int main(int argc, const char *argv[]) {
	int i,j,k;
	std::vector<int> v;
	std::cout << "How many elements would you like to add to the vector?\n  -->  ";
	std::cin >> j;

	for (i = 0;i < j; i++) {
		std::cout << "Element " << i + 1 << ": ";
		std::cin >> k;
		v.push_back(k);
	}
	
	std::cout << "The unsorted vector is:\n" << printVector(v) << std::endl;
	gnomeSort(v);
	std::cout << "The sorted vector is:\n" << printVector(v) << std::endl;
	return 0;
}
 	

