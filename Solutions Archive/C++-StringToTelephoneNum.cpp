#include <iostream>
#include <random>
#include <string>
#include <functional>

int isDigit(char c) {
	return (c >= '0' && c <= '9');
}

int letterMap(char c) {
	int outDigit, shiftedASCIIChar;

	//Shifts the ASCII value of the character depending on if it is uppercase or lowercase
	if (c >= 65 && c < 91) {
		 shiftedASCIIChar = c - 65;
	}
	else if (c >= 97 && c < 123) {
		shiftedASCIIChar = c - 97;
	}
	else {
		return -1;
	}

	
	outDigit = shiftedASCIIChar / 3;

	if (outDigit <= 4) {
		return outDigit + 2;
	}
	else {
		if (shiftedASCIIChar >= 15 && shiftedASCIIChar < 19) {
			return 7;
		}
		else if (shiftedASCIIChar >=19 && shiftedASCIIChar < 22) {
			return 8;
		}
		else {
			return 9;
		}
	} 
}

std::string generateTelephoneNumber(std::string s) {
	int i, wait;
	std::string strDigits = "";
 
	for (i = 0; i < s.length(); ++i) {
		if (isDigit(s[i]) || s[i] == '-') {
			strDigits += s[i];
		}
		else {
			strDigits += std::to_string(letterMap(s[i]));
		}
	}
	return strDigits;
}
		
int main(void) {
	int i,j;
	std::string s;
	std::cout << "What is the telephone number with Latin characters in it that you would like to convert?\n --> ";
	std::cin >> s;
	
	std::cout << "The telephone number is " << generateTelephoneNumber(s) << std::endl;

	return 0;
}

							
