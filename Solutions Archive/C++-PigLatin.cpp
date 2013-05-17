#include <iostream>
#include <string>
#define ASCII_DELTA 32

//char toLower;

bool isUpper(char c) {
	return (c >= 'A' && c <= 'Z');
}

std::string toLower(std::string s) {
	int i;
	for (i = 0; i < s.length(); ++i) {
		if (isUpper(s[i])) {
			s[i] += ASCII_DELTA;
		}
	}
	return s;
}			

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
	eng = toLower(eng);

	for (i = 0; i < eng.length(); ++i) {
		if (isVowel(eng[i])) {
			pLatin = eng.substr(i, eng.length()) + eng.substr(0, i) + "ay";
			break;
		}
	}
	return pLatin;
}

std::string translateSentence(std::string sEng) {
	int i;
	std::string sPig = "", word;
	
	do {
		int i = sEng.find(" ");
		if (i != -1) {
			word = sEng.substr(0, i);
			sEng = sEng.substr(i + 1, sEng.length());
		}
		else {
			word = sEng;
			sEng = "";
		}
		sPig += " " + toPigLatin(word);
	} while (sEng != "");
	
	return sPig.substr(1, sPig.length());
}

int main(int argc, const char *argv[]) {
	std::string e, p;
	std::cout << "What is the english sentence you would like translated?\n  -->  ";
	std::getline(std::cin, e);
	
	p = translateSentence(e);
	
	if (p == "") {
		std::cout << "Sorry, I can't directly translate the sentence '" << e << "'" << std::endl;
	}
	else {
		std::cout << "The English sentence '" << e << "' translates to '" << p << "' in pig latin" << std::endl;
	}
	
	return 0;
}

