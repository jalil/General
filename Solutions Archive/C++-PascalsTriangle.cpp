#include <iostream>
#include <string>
#include <vector>

std::vector<int> getPascalRow(int);
int binomCoef(int, int);

std::string makePadding(int max, int min) {
	int i, j;
	std::string s = "";

	//j = max - (2 * min);
	j = max - min;
	for (i = 0; i < j; i++) {
		s += " ";
	}
	return s;
}		
	
std::string printPascal(int r) {
	int i;
	std::string s = "";
	std::vector<int> v;
	for (i = 0; i <= r; i++) {
		v = getPascalRow(i);
		s += makePadding(r, i);
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			s += std::to_string(*it) + " ";
		}
		s =  s.substr(0, s.length() - 1) + '\n';
	}
	return s;
}

std::vector<int> getPascalRow(int n) {
	int k;
	std::vector<int> v;
	for (k = 0; k <= n; k++) {
		v.push_back(binomCoef(n, k));
	}
	return v;		
}

int binomCoef(int n, int k) {
	if (n == 0 || n == 1 || k == 0 || n == k) {
		return 1;
	}
	else {
		return binomCoef(n - 1, k - 1) + binomCoef(n - 1, k);
	}
}

int main(int argc, const char *argv[]) {
	int i;
	std::string s;
	
	std::cout << "To what row would you like to find Pascal's triangle?\n  -->  ";
	std::cin >> i;
	
	std::cout <<  printPascal(i) << std::endl;
	 
	return 0;
}

