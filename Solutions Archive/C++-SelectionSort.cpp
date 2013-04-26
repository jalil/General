#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
void selectionSort(std::vector<T>& v) {
	//sorts --> number of swaps, i --> integral offset from first pointer location
	unsigned int i = 0;
	//it --> main iterator, mint --> minimum value location
	typename std::vector<T>::iterator it, mint;
	while (i != v.size() - 1) {
		//initialize mint --> first element of unsorted sub-vector
		mint = v.begin() + i;
		for (it = i + v.begin(); it != v.end(); ++it) {
			if (it != v.end()) {			
				if (*mint > *it) {
					mint = it;
				}
			}
		}
		std::iter_swap(v.begin() + i, mint);
		i = i + 1;
	}
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
	std::vector<int> vIn;

	std::cout << "How many numbers in your vector?\n  -->  ";
	std::cin >> j;

	for (i = 0; i < j; i++) {
		std::cout << "Element " << i + 1 << ": ";
		std::cin >> k;
		vIn.push_back(k);
	}
	
	std::cout << "The unordered vector is: " << printVector(vIn) << std::endl;

	selectionSort(vIn);

	std::cout << "The ordered vector is: " << printVector(vIn) << std::endl;	

	return 0;
}
 
