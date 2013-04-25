#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void oddEvenSort(std::vector<int>& v) {
	int sorted = -1;
	while (sorted != 0) {
		sorted = 0;
		//odd first
		for (std::vector<int>::iterator it = v.begin() + 1; it <= v.end() - 1; it += 2) {
			if (*it > *(it + 1)) {
				std::iter_swap(it, it + 1);
				sorted += 1;
			}
		}
		//even second
		for (std::vector<int>::iterator it = v.begin(); it <= v.end() - 1; it += 2) {
			if (*it > *(it + 1)) {
				std::iter_swap(it, it + 1);
				sorted += 1;
			}
		}
	}
}

std::string printVector(std::vector<int> v) {
	std::string s = "<";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		s += std::to_string(*it) + ", ";
	}
	return s.substr(0, s.length() - 2) + ">";
}

int main(int argc, const char *argv[]) {
	int i,j,k;
	std::vector<int> v;

	std::cout << "How many values would you like to add to the vector?\n  -->  ";
	std::cin >> j;

	for (i = 0; i < j; i++) {
		std::cout << "Element " << i + 1 << ": ";
		std::cin >> k;
		v.push_back(k);
	}
	std::cout << "The unsorted vector is: " << printVector(v) << std::endl;
	oddEvenSort(v);
	std::cout << "The sorted vector is " << printVector(v) << std::endl;
	return 0;
}

