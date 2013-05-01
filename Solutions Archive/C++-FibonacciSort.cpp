#include <iostream>
#include <vector>

std::vector<int> fibNums(int u) {
	int i = 0;
	std::vector<int> v {1, 1};
	
	while ((v(i) + v(i + 1)) <= u) {
		v.push_back(v(i) + v(i + 1));
		i++;
	}
	
	return v;
}

int fibSearch(std::vector<int> v) {
	
