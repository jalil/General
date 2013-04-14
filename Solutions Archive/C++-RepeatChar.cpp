#include <iostream>
#include <string>

using namespace std;

string repeatChar(char c, int n) {
	int i;
	string out = "";
	for (i = 0; i < n; i++) {
		out += c;
	}
	return out;
}

int main(int argc, const char *argv[]) {
	int in;
	char c;
	
	cout << "What is the character you would like to repeat?\n  -->  ";
	cin >> c;
	
	cout << "How times would you like the character to occur in the string?\n  -->  ";
	cin >> in;

	cout << "The character '" << c << "' repeated " << in << " times yielded the string '" << repeatChar(c, in) << "'" << endl;
	return 0;
}


