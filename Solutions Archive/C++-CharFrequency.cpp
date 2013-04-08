#include <iostream>
#include <map>
#include <string>

using namespace std;


int main( int argc, const char *argv[]) {
	int i;
	string line;
	map <char, int> freqs;

	cout << "Please give me a line of text: ";
	getline(cin, line);

	for (i = 0; i < line.length(); i++) {
		if (freqs.find(line[i]) == freqs.end()) {
			freqs[line[i]] = 1;
		}
		else {
			freqs[line[i]] += 1;
		}
	}

	map<char, int>::iterator it;
	for (map<char, int>::iterator it=freqs.begin(); it!=freqs.end(); it++) {
		cout << "'" <<  it->first << "'" << " => " << it->second << " freq: " << ((it->second / (double)line.length()) * 100) << "%" << endl;
	}

	cout << "Goodbye!" << endl;
	return 0;
}

