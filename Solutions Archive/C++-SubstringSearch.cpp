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
	std::string in = "fuckaduck";
	std::string out = subStringSearch(in, "f*k");
	std::cout << out << std::endl;
	return 0;
}
 
				
