#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

template <typename T>
void cocktailSort(std::vector<T>& v) {
	int sorted;
	while (sorted != 0) {
		sorted = 0;
		for (typename std::vector<T>::iterator it = v.begin(); it != v.end() - 1; it++) {
			if (*it > *(it + 1)) {
				std::iter_swap(it, it + 1);
				++sorted;
			}
		}

		for (typename std::vector<T>::reverse_iterator rit = v.rbegin(); rit != v.rend() - 1; rit++) {
			if (*rit < *(rit + 1)) {
				std::iter_swap(rit, rit + 1);
				++sorted;
			}
		}
	}
}
		


template <typename T>
void fisherYatesShuffle(std::vector<T>& v) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, v.size() - 1);
	auto nextRand  = std::bind(distribution, generator);
	
	for (typename std::vector<T>::iterator it = v.begin() + 1; it != v.end(); it++) {
		std::iter_swap(it, v.begin() + nextRand());
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
	std::vector<int> v;
 
	std::cout << "How many elements would you like to add to the vector?\n  -->  ";
	std::cin >> j;

	for (i = 0; i < j; i++) {
		std::cout << "Element " << i + 1 << ": ";
		std::cin >> k;
		v.push_back(k);
	}

	//sort list before giving it back to the user
	cocktailSort(v);

	std::cout << "The unshuffled sorted vector is " << printVector(v) << std::endl;

	//shuffle the elements
	fisherYatesShuffle(v);
	
	std::cout << "The Fisher-Yates shuffled vector is " << printVector(v) << std::endl;
	
	return 0;
}

