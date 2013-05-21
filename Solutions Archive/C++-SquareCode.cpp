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
	while (!(currEst * currEst >= len)) {
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

std::string createCipherText(std::vector<std::string> v) {
	int i;
	std::string s = "";
	for (i = 0; i < v[0].length(); ++i) {
		for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
			if (i >= (*it).length()) {
				s += ' ';
			}
			else {	  
				s += (*it)[i];
			}
		}
		s += ' ';
	}
	return s;
}

std::string encrypt(std::string s) {
	std::vector<std::string> sVector;
	sVector = makeSquare(stripWhitespace(s));
	return createCipherText(sVector);
}

int main(int argc, const char *argv[]) {
	std::string s;
	std::vector<std::string> sVector;
	

	std::cout << "DATA INITIALIZATION:\n Give me a sentence to encode: ";
	std::getline(std::cin, s);

	sVector = makeSquare(stripWhitespace(s));

	std::cout << "\nCODE SQUARE:" << std::endl;

	for (std::vector<std::string>::iterator it = sVector.begin(); it != sVector.end(); ++it) {
		std::cout << "Row " << sVector.end() - it << ": " << *it << std::endl;
	}
	
	std::cout << "\nCipher Text:" << std::endl;
	std::cout << "The sentence '" << s << "' has become '" << createCipherText(sVector) << "'" << std::endl;

	return 0;
}

