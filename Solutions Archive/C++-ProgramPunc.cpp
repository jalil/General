#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool checkPunc(char in) {
	bool out;
	switch(in) {
		case '(':
		case ')':
		case '{':
		case '}':
		case '[':
		case ']':
			out = true;
			break;
		default:
			out = false;
			break;
	}
	return out;
}		

bool isOpenPunc(char in) {
	bool out;
	switch(in) {
		case '(':
		case '[':
		case '{':
			out =  true;
			break;
		default:
			out = false;
			break;
	}
	return out;
}
		
char oppositeChar(char in) {
	char out;
	switch(in) {
		case '(':
			out = in + 1;
			break;
		case ')':
			out = in - 1;
			break;
		case '{':
			out = in + 2;
			break;
		case '}':
			out = in - 2;
			break;
		case '[':
			out = in + 2;
			break;
		case ']':
			out = in - 2;
			break;
	}
	return out;
}

void errMessage(char given, char expected, int idx) {
        cout << "You gave a '" << given << "' character at index " << idx << " instead of the expected character '" << expected << "'" << endl;
}

bool isPunctuationCorrect(string inString){ 
	int i;
	stack<char> sPunc;

	for (i = 0; i < inString.length(); i++) {
		if (checkPunc(inString[i])) {
			if (isOpenPunc(inString[i])) {
				sPunc.push(inString[i]);
			}
			else {
				if (oppositeChar(sPunc.top()) == inString[i]) {
					sPunc.pop();
				}
				else {
					errMessage(inString[i], sPunc.top(), i);
					return false;
				}
			} 
		}
	}
	if (sPunc.size() >= 1 ) {
		return false;
	}
	else {
		return true;
	}
} 
	
int main(int argc, const char *argv[]) {
	string in;
	cout << "Give me a string with '[',']','(',')', '{', and '}' characters to check: ";
	getline(cin, in);
	if (isPunctuationCorrect(in)) {
		cout << "The punctuation is correct!" << endl;
	}
	else {
		cout << "The punctuation failed!" << endl;
	}
	return 0;
}

