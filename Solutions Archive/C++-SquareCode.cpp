#include <iostream>
#include <vector>
#include <string>

std::string stripWhitespace(std::string s) {
	int i;
	while (s.find(" ") != -1) {
		i = s.find(" ");

		if (i == 0) {
			s = s.substr(1, s.length());
		}
		else if (i == s.length() - 1) {
			s = s.substr(0, s.length() - 1);
		}
		else {
			s = s.substr(0, i) + s.substr(i + 1, s.length());
		}
	}
	return s;
}

int findDimensions(std::string s) {
	int len = s.length(), currEst = 1;
	while (!(currEst * currEst >= len - (len * 0.1) && currEst * currEst <= len + (len * 0.1))) {
		currEst += 1;
	}
	return currEst;
}

std::vector<std::string> makeSquare(std::string s) {
	int i = 0, j , rowLen = findDimensions(s);
	std::vector<std::string> v;
	while (i != s.length()) {
		std::string stringElement = "";
		for (j = 0; j < rowLen && i != s.length(); ++j) {
			stringElement += s[i];
			++i;
		}
		v.push_back(stringElement);
	}
	return v;
}

int main(int argc, const char *argv[]) {
	std::string s1, s2;
	
	std::cout << "Give me a string to encode: ";
	std::getline(std::cin, s1);
	s2 = stripWhitespace(s1);
	std::cout << s2 << std::endl;
	std::cout << findDimensions(s2) << std::endl;
	std::vector<std::string> v = makeSquare(s2);

	for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << std::endl;
	}
	

	return 0;
}

