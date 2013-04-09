#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;


int main( int argc, const char *argv[]) {
	bool cont = true;
	int i, wordCount = 0;
	string word, line, fname;
	map <string, int> freqs;

	cout << "Please give me a file name: ";
	cin >> fname;
	
	ifstream myfile(fname.c_str(), ios::in);

	while(getline(myfile, line)) {
		cont = true;
		do {
			i = line.find(" ");
			if (i != string::npos) {
				word = line.substr(0, i);
				line = line.substr(i + 1, line.length() - 1);	
			}
			else {
				cont = false;
				word = line;
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
		cout << "'" <<  it->first << "'" << " => " << it->second << " freq: " << ((it->second / (double)wordCount) * 100) << "%" << endl;
	}

	cout << "Goodbye!" << endl;
	return 0;
}

