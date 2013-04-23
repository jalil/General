#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


void cocktailSort(std::vector<int>& v) {
	int sorted;
	while (sorted != 0) {
		sorted = 0;
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++ ) {
			if (it + 1 != v.end()) {
				if (*it > *(it + 1)) {
					std::iter_swap(it, it + 1);
					sorted += 1;
				}
			}
		}
		for (std::vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++) {
			if (rit + 1 != v.rend()) {
				if (*rit < *(rit + 1)) {
					std::iter_swap(rit, rit + 1);
					sorted += 1;
				}
			}
		}
	}
}


int binSearch(std::vector<int> v, int val) {
	int lowBound =  0,  highBound = v.size() - 1;
	int mid;
	
	while (lowBound != highBound - 1) {
		mid = (highBound + lowBound) / 2;
		if (v[mid] == val) {
			return mid;
		}
		else {
			if (v[mid] > val) {
				highBound = mid;
			}
			else {
				lowBound = mid;
			}
		}
	}
	return -1;
}

std::string vecToStr(std::vector<int> v) { 
	std::string s  = "<";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		s += std::to_string(*it) + ", ";
	}
	return s.substr(0, s.length() - 2) + ">";
}


int main(int argc, const char *argv[]) {
	int i, j, k;
	std::vector<int> v;

	std::cout << "How many values do you want in the vector?\n  -->  ";
	std::cin >> j;
	
	for (i = 0; i < j; ++i) {
		std::cout << "Element " << i + 1 << ": ";
		std::cin >> k;
		v.push_back(k);
	}
	cocktailSort(v);

	std::cout << "Your sorted vector is: " << vecToStr(v) << std::endl;


	std::cout << "Give me a value to search for: ";
	std::cin >> j;

	k = binSearch(v, j);
	if (k != -1) {
		std::cout << "The element with value " << j << " was found at index " << k << std::endl;
	}
	else {
		std::cout << "No element with value " << j << " was found in the vector." << std::endl;
	}
	return 0;
}
	
