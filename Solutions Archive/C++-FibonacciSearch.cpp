#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void gnomeSort(std::vector<T>& v) {
	typename std::vector<T>::iterator it = v.begin();
	while (it + 1 != v.end()) {
		if (*it > *(it + 1)) {
			std::iter_swap(it , it + 1);
			if (it != v.begin()) {
				--it;
			}
		}
		else {
			++it;
		}
	}
} 

std::vector<int> fibNums(int n) {
	int i = 0;
	std::vector<int> fibs;
	fibs.push_back(0);
	fibs.push_back(1);

	while (fibs.back() < n) {
		fibs.push_back(fibs[i] + fibs[i + 1]);
		++i;
	}
	return fibs;
}
	
int fibSearch(std::vector<int> v, int val) {
	std::vector<int> fibs = fibNums(v.back());
	
	int i = 0;
	
	for (i = 0; )	


	for (std::vector<int>::iterator it = fibs.begin(); it != fibs.end(); ++it) {
		if (val < *it) {
			for (std::vector<int>::iterator it2 = it - 1; it2 != fibs.end(); ++it2) {
				if (*it2 == val) {
					std::cout << *it2 << std::endl;
					return (it2 - fibs.begin());
				}
			}
		}
	}			
	return -1;
}



int main(int argc, const char *argv[]) {
	int i,j,k;
	std::vector<int> v;

	std::cout << "How many elements would you like to add to the vector?\n  -->  ";
	std::cin >> j;

	for (i = 0; i < j; ++i) {
		std::cout << "Element " << i + 1 << ": ";
		std::cin >> k;
		v.push_back(k);
	}
	
	std::cout << "What value would you like to search for?\n  -->  ";
	std::cin >> k;

	gnomeSort(v);
	j = fibSearch(v, k);
	
	if (j == -1) {
		std::cout << "The value " << k << " was not found in the vector" << std::endl;
	}
	else {
		std::cout << "The value " << k << " was found at index " << j << std::endl;
	}

	return 0;
}


