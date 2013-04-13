#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

string scrambleWord(string s) {
	srand(time(0)); //initialize seed to sys time
	unsigned int ridx; 

	string outstring = "";
	
	while (s.empty() != true) {
		ridx = rand() % s.size();
		outstring += s[ridx];
		s.erase(ridx, 1);
	}
	return outstring;
}

string scrambleSentence(vector<string> vIn) {
	srand(time(0));
	unsigned int ridx;

	string sOut = "";

	while(!vIn.empty()) {	
		ridx = rand() % vIn.size();
		sOut += scrambleWord(*(vIn.begin() + ridx)) + " " ;
		vIn.erase(vIn.begin() + ridx);
	}
	return sOut.substr(0, sOut.length() - 1);	
}



vector<string> vectorizeString(string sSentence) {
	int i;
	vector<string> vOut;

	do {
		i = sSentence.find(" ");
		if (i != string::npos) {
			vOut.push_back(sSentence.substr(0, i));
			sSentence = sSentence.substr(i + 1, sSentence.length() - 1);
		}
		else {
			vOut.push_back(sSentence);
			sSentence.clear();
		}
	} while(!sSentence.empty());
	return vOut;
}


int main(int argc, const char *argv[]) {
	string sSentence, sScrambled;
	vector<string> vSent;
	cout << "Give me a sentence to scramble: ";
	getline(cin, sSentence);
	 
	vSent = vectorizeString(sSentence);
	sScrambled = scrambleSentence(vSent);
	cout << "Your original sentence was:\n  --> '" << sSentence << "'\nYour scrambled sentence is:\n  --> '" << sScrambled << "'" << endl;
	return 0;
}
		
