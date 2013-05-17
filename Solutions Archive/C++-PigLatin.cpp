#include <iostream>
#include <string>


bool isVowel(char c) {
	bool out;
	switch(c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			out = true;
			break;
		default:
			out = false;
			break;
	}
	return out;
}

std::string toPigLatin(std::string eng) {
	int i;
	std::string pLatin = "";

	for (i = 0; i < eng.length(); ++i) {
		if (isVowel(eng[i])) {
			pLatin = eng.substr(i+1, eng.length()) + eng.substr(0, i) + "ay";
			break;
		}
	}
	return pLatin;
}

int main(int argc, const char *argv[]) {
	std::string e, p;
	std::cout << "What is the english string you would like translated?\n  -->  ";
	std::cin >> e;
	
	p = toPigLatin(e);
	
	if (p == "") {
		std::cout << "Sorry, I can't directly translate the word '" << e << "'" << std::endl;
	}
	else {
		std::cout << "The English word '" << e << "' translates to '" << p << "' in pig latin" << std::endl;
	}
	return 0;
}

