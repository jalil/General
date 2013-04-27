#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
void stoogeSort(std::vector<T>& v, unsigned int l, unsigned int u) {
	unsigned int t;
	if (v[u] < v[l]) {
		std::iter_swap(v.begin() + l, v.begin() + u);
	}
	if ((u - l + 1) >= 3) {
		t = (u - l + 1) / 3;
		stoogeSort(v, l, u - t);
		stoogeSort(v, l + t, u);
		stoogeSort(v, l, u - t);
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
	
	std::cout << "Your unsorted vector is " << printVector(v) << std::endl;
	stoogeSort(v, 0, v.size() - 1);
	std::cout << "Your sorted vector is " << printVector(v) << std::endl;
	return 0;
}

