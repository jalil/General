#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
	int i, tlen = 0;
	string fname, line;
	map <char, int> freqs;

	cout << "Please give me the name of the text file: ";
	cin >> fname;	

	std::ifstream infile(fname.c_str(), ios::in);
	
	while (std::getline(infile, line)) { 
		tlen += line.length();
		for (i = 0; i < line.length(); i++) {
			if (freqs.find(line[i]) == freqs.end()) {
				freqs[line[i]] = 1;
			}
			else {
				freqs[line[i]] += 1;
			}
		}
	}


	map<char, int>::iterator it;
	for ( it=freqs.begin(); it!=freqs.end(); it++) {
		cout << "'" <<  it->first << "'" << " => " << it->second << " freq: " << ((it->second / (double)tlen) * 100) << "%" << endl;
	}

	cout << "Goodbye!" << endl;
	infile.close();
	return 0;
}

