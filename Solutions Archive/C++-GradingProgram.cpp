#include <iostream>

using namespace std;

int main() { 
	int score;
	cout << "Welcome to the grading program!\nPlease insert your score below:\n->";
	cin >> score;

	if (score >= 100) {
		cout << "You got a perfect score! A+" << endl;
	}
	else if (score < 100 && score >= 90) { 
		cout << "You got an A!" << endl;
	}
	else if (score < 90 && score >= 80) {
		cout << "You got a B!" << endl;
	}
	else if (score < 80 && score >= 70) {
		cout << "You got a C. It's okay." << endl;
	}
	else if (score < 70 && score >= 60) {
		cout << "You got a D. I'm sorry." << endl;
	}
	else if (score < 60) {
		cout << "You got an F. Next time you should study." << endl;
	}
	else {
		cout << "I'm not quite sure what you got." << endl;
	}
	return 0;
}

		
