#include <iostream>
#include <string>

typename <template T>
T numDigits(T num) {
	int d = 0;
	while(num) {
		num /= 10;
		++d;
	}
	return d;
}

int digitDelta(int high, int curr) {
	return numDigits(high) - numDigits(curr);  
}

std::string makePadding(int n) {
	int i = 0;
	std::string s  = "";
	for (i = 0; i < n + 1; ++i) {
		s += " ";
	}
	return s;
}

std::string printTable(int len) {
	int i,j;
	std::string mTable = "";
	for (i = 1; i < len + 1; ++i) {
		for (j = 1; j < len + 1; ++j) {
			mTable += makePadding(digitDelta((len * len), i * j)) + std::to_string(i * j);
		}
		mTable += '\n';
	}
	return mTable;
}

int main(int argc, const char *argv[]) {
	int n;
	std::cout << "To what number of rows and columns would you like to create a multiplication table?\n  -->  ";
	std::cin >> n;

	std::cout << printTable(n) << std::endl;
	return 0;
}

