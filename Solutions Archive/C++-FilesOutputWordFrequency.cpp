#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;

string checkString(string s);

int main( int argc, const char *argv[]) {
	bool cont = true;
	int i, wordCount = 0;
	string word, line, fin, fout;
	map <string, int> freqs;

	cout << "Please give me a file name for the text file we will read from name: ";
	cin >> fin;
	cout << "Please give me a file name for the text file which will contain our output: ";
	cin >> fout;

	ifstream infile(fin.c_str(), ios::in);
	ofstream outfile(fout.c_str());

	if (!infile.is_open()) { 
		cout << "An error has occurred in attempting to open your file." << endl;
		return 1;
	}

	while(getline(infile, line)) {
		cont = true;
		do {
			i = line.find(" ");
			if (i != string::npos) {
				word = checkString(line.substr(0, i));
				line = line.substr(i + 1, line.length() - 1);	
			}
			else {
				cont = false;
				word = checkString(line);
			}
		
			if (freqs.find(word) == freqs.end()) {
				freqs[word] = 1;
			}
			else {
				freqs[word] += 1;
			}
			wordCount += 1;
		} while (line.find(" ") != string::npos || cont == true);
	}	
	map<string, int>::iterator it;
	for ( it=freqs.begin(); it!=freqs.end(); it++) {
		outfile << "'" << it->first << "'," << it->second << "," << ((it->second / (double)wordCount) * 100) << "%" << endl;
	}

	cout << "It worked, I think.." << endl;

	infile.close();
	outfile.close();

	return 0;
}

string checkString(string s) {
	int i;
	string out = "";
	for (i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) {
			out += s[i];
		}
	}
	return out;
}
