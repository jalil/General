#include <iostream>
#include <string>

std::string subStringSearch(std::string searchString, std::string wildString) {
	//wild strings are of the form "a*b" 
	//search string is the largest string to find the occurrence of sstr
	int i, j;
	std::string returnString = "";
	for (i = 0; i < searchString.length(); ++i) {
		if (searchString[i] == wildString[0]) {
			for (j = i; j < searchString.length(); ++j) {
				returnString += searchString[j];
				if (searchString[j] == wildString[2]) {
					break;
				}
			}
			if (returnString[returnString.length() - 1] == wildString[2]) {
				return returnString;
			}
		}
	}
	return "";
}

int main(int argc, const char *argv[]) {
	std::string sstr, wcstr, ostr;

	std::cout << "What is the search string?\n  -->  ";
	std::cin >> sstr;
	std::cout << "What are the wildcard parameters? (ex. l*p)\n  -->  ";
	std::cin >> wcstr;

	ostr = subStringSearch(sstr, wcstr);
	
	if (ostr != "") {
		std::cout << "The wild card substring found was '" << ostr << "'" << std::endl;
	}
	else {
		std::cout << "No wild card substring with the parameters '" << wcstr << "' exists in '" << sstr << "'" << std::endl;
	}
	return 0;
}
 
				
