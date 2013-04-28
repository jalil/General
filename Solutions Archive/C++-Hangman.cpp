#include <string>
#include <iostream>
#include <vector>

class Hangman {
	private:
		std::string word;
		std::string displayWord;
		std::string charsToGuess;
		unsigned int tries;
	public:
		//constructor - destructor
		Hangman(std::string);
		//~Hangman();	
		//utility methods
		void run();
		std::string generateDisplay(std::string);
		bool isOver();
		std::vector<int> letterMatches(char);
		void updateCharsToGuess(char);
		std::string printHangman();
		void updateDisplayWord(char);
};
//method declarations
Hangman::Hangman(std::string w) {
	int i;
	displayWord = "";
	for (i = 0; i < w.length(); i++) {
		displayWord += "-";
	}

	word = w; 
	charsToGuess = "abcdefghijklmnopqrstuvwxyz";
	tries = 0;
}

void Hangman::run() {
	char guess;
	while (!isOver()) {
		std::cout << printHangman() << std::endl;
		std::cout << "WORD TO GUESS:\n" << displayWord << "\n\nAVAILABLE LETTERS:\n" << charsToGuess << "\n\nWhat letter would you like to guess next?\n  -->  ";
		std::cin >> guess;
		updateDisplayWord(guess);
		updateCharsToGuess(guess);
		std::cout << "After your guess of '" << guess << "' the word you have to guess is '" << displayWord << "'. You have " << 6- tries << " tries left before you hang." << std::endl;
	}
	std::cout << printHangman() << std::endl;
}	

bool Hangman::isOver() {
	if (displayWord == word) {
		std::cout << "You guessed the word!" << std::endl;
		return true;
	}
	else if (tries == 6) {
		std::cout << "You ran out of tries!" << std::endl;
		return true;
	}
	else {
		return false;
	}
}

std::vector<int> Hangman::letterMatches(char c) {
	std::vector<int> v;
	int i;
	for (i = 0; i < word.length(); i++) {
		if (word[i] == c) {
			v.push_back(i);
		}
	}
	return v;
}

void Hangman::updateCharsToGuess(char c) {
	int i = charsToGuess.find(c);
	if (i != -1) {
		if (i == 0) {
			charsToGuess = charsToGuess.substr(1, charsToGuess.length());
		}
		else if (i == charsToGuess.length() - 1) {
			charsToGuess = charsToGuess.substr(0, charsToGuess.length() - 1);
		}
		else {
			charsToGuess = charsToGuess.substr(0, i) + charsToGuess.substr(i + 1, charsToGuess.length());
		}
	}
}

std::string Hangman::printHangman() {
	std::string s =  "    ______\n    |     |\n";
	if (tries > 0) {
		s += "    0     |\n";
	}
	else { 
		s +=  "          |\n";
	}

	if (tries > 3) {
		s += "   /|\\    |\n";
	}
	else if (tries > 2) {
		s +=  "   /|     |\n";
	}
	else if (tries > 1) {
		s +=  "    |     |\n";
	}
	else {
		s += "          |\n";
	}

	if (tries == 6) {
		s +=  "   / \\    |\n";
	}
	else if (tries > 4) {
		s += "   /      |\n";
	}
	else {
		s += "          |\n";
	}

	s +=  "-----------";
	
	return s;
}

void Hangman::updateDisplayWord(char c) {
	std::vector<int> matches = letterMatches(c);
	if (matches.size() != 0) {
		for (std::vector<int>::iterator it = matches.begin(); it != matches.end(); it++) {
			displayWord[*it] = c;
		}
	}
	else {
		tries++;
	}
}

int main(int argc, const char *argv[]) {
	std::string word;
	std::cout << "What is the word you want to guess?\n  -->  ";
	std::cin >> word;
	
	Hangman game(word);
	game.run();
	return 0;
}

