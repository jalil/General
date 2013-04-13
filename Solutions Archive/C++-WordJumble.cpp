#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string jumbleword(string s) {
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

int main(int argc, const char *argv[]) {
	string s;
	cout << "Give me a string to jumble: ";
	cin >> s;
	cout << "The string '" << s << "' became '" << jumbleword(s) << "'!" << endl;
	return 0;
}
		
