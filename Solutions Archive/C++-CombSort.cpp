#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T> 
std::string printVector(std::vector<T> v) {
	std::string s = "<";
	for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		s += std::to_string(*it) + ", ";
	}
	return s.substr(0, s.length() - 2) + ">";
}

template <typename T>
void combSort(std::vector<T>& v) {
	unsigned int gap = v.size(), sorts;
	while (gap > 1 || sorts != 0) {
		gap /= 1.3;
		sorts = 0;
		for (typename std::vector<T>::iterator it = v.begin(); it < v.end() - gap; it++) {
			if (*it > *(it + gap)) {
				std::iter_swap(it, it + gap);
				sorts++;
			}
		}
	}
}

int main(int argc, const char *argv[]) {
	int i,j,k;
	std::vector<int> v;
	std::cout << "How many elements would you like to add to your vector?\n  -->  ";
	std::cin >> j;

	for (i = 0; i < j; i++) {
		std::cout << "Element " << i + 1 << ": ";
		std::cin >> k;
		v.push_back(k);
	}
	
	std::cout << "The unsorted vector is " << printVector(v) << std::endl;
	combSort(v);
	std::cout << "The comb sorted vector is " << printVector(v) << std::endl;
	return 0;
}

		
		
		
		
