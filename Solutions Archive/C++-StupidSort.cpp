#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
int stupidSort(std::vector<T>& v) {
	int numSorts = 0;
	while (!isSorted(v)) {
		std::random_shuffle(v.begin(), v.end());
		numSorts++;
	}
	return numSorts;
}
		
template <typename T>
bool isSorted(std::vector<T> v) {
	for (typename std::vector<T>::iterator it = v.begin(); it != v.end() - 1; it++) {
		if (*it > *(it + 1)) {
			return false;
		}
	}
	return true;
}

template <typename T>
std::string printVector(std::vector<T> v) {
	std::string s = "<";
	for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		s += std::to_string(*it) + ", ";
	}
	return s.substr(0, s.length() - 2) + ">";
}

int main(int argc, const char *argv[]) {
	int i,j,k;
	std::vector<int> v;
	
	std::cout << "How many elements would you like to add to the vector?\n  -->  ";
	std::cin >> j;
	for (i = 0; i < j; i++) {
		std::cout << "Element " << i + 1 << ": ";
		std::cin >> k;
		v.push_back(k);
	}

	std::cout << "The unsorted vector is " << printVector(v) << std::endl;
	k = stupidSort(v);
	std::cout << "The sorted vector is " << printVector(v) << " and was found in " << k << " attempts" << std::endl;
	return 0;
}

