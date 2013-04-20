#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <class T> 
void cocktailSort(std::vector<T>& vIn) {
	int sorted;
	while (sorted != 0) {
		sorted = 0;
		for (typename std::vector<T>::iterator it = vIn.begin(); it != vIn.end(); ++it) {
			if (it + 1 != vIn.end()) {
				if (*it > *(it + 1)) {
					std::iter_swap(it, it + 1);
					sorted += 1;
				}
			}
		}
		
		for (typename std::vector<T>::reverse_iterator rit = vIn.rbegin(); rit != vIn.rend(); ++rit) {
			if (rit + 1 !=  vIn.rend()) {
				if (*rit < *(rit + 1)) {
					std::iter_swap(rit, rit + 1);
					sorted += 1;
				}
			}
		}
	}
}

int main(int argc, const char *argv[]) {
	int i,j,k;
	std::vector<int> myInts;
	std::cout << "How many elements do you want to add to the vector?\n  -->  ";
	std::cin >> j;
	for (i = 0; i < j; i++) {
		std::cout << "Element " << i + 1 << ": ";
		std::cin  >> k;
		myInts.push_back(k);
	}

	std::cout << "The ordered list is as follows:" << std::endl;
	cocktailSort(myInts);
	for (std::vector<int>::iterator it = myInts.begin(); it != myInts.end(); it++) {
		std::cout <<"Element " << it - myInts.begin() << ": " << *it << std::endl;
	}
	return 0;
}

