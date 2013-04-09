#include <iostream>
#include <random>

using namespace std;

int main(int argc, const char *argv[]) {
	int guess, numGuesses = 0;

	//generate random val
	default_random_engine generator;
	uniform_int_distribution <int> distribution(1,100);
	int val = distribution(generator);

	//enter guess loop
	do {
		cout << "Turn " << numGuesses << ". Give me a guess: ";
		cin >> guess;
		
		if (guess > val) {
			cout << "Your guess of " << guess << " was too high." << endl;
		}
		else if (guess < val) {
			cout << "Your guess of " << guess << " was too low." << endl;
		}
		numGuesses += 1;
		
	} while(guess != val);
	
	cout << "Congratulations! You correctly guessed the number " << val << " in only " << numGuesses << " tries!" << endl;
	return 0;
}

