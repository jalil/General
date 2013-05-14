#include <iostream>
#include <random>
#include <string>
#include <functional>

int absVal(int n) {
	return (n >= 0) ? n : -n;
}

int humanMove() {
	int move;
	while (true) {
		std::cout << "You have three move choices:\n1 --> Rock\n2 --> Paper\n3 --> Scissors\nWhich would you like?\n  -->  ";
		std::cin >> move;
		if (move > 0 && move < 4) {
			return move;
		}
		else {
			std::cout << "Your input was invalid. Remember to input a value between 1 and 3." << std::endl;
		}
	}
}

int evalMoves(int m1, int m2) {
	//works because encoding scheme: 1 -> rock, 2 -> paper, 3 -> scissors 
	int deltaM = absVal(m2 - m1);
	if (deltaM == 2) {
		if (m1 > m2) {
			return 2;
		}
		else {
			return 1;
		}
	}
	else if (deltaM == 1) {
		if (m1 > m2) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else {
		return 0;
	}
}

std::string moveToStr(int n) {
	std::string s;
	switch(n) {
		case 1:
			s = "Rock";
			break;
		case 2:
			s = "Paper";
			break;
		case 3:
			s = "Scissors";
			break;
	}
	return s;
}

int playGame(int n) { 
	int r, p1,p2, mP1, mP2;

	//create the random number generator
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,3);
	auto robotGuess = std::bind(distribution, generator);

	p1 = p2 = 0;

	while (p1 < n && p2 < n) {	
		
		mP1 = humanMove();
		mP2 = robotGuess();
		r = evalMoves(mP1, mP2);
		std::cout << "The current score is:\nHuman --> " << p1 << ", Computer --> " << p2 << std::endl;
		std::cout << "You used '" << moveToStr(mP1) << "' and the computer chose '" << moveToStr(mP2) << "'" << std::endl;

		if (r == 1) {
			std::cout << "You won this round! Have a point!\n" << std::endl;
			++p1;
		}
		else if (r == 2) {
			std::cout << "You lost this round. Computer gets a point.\n" << std::endl;
			++p2;
		}
		else {
			std::cout << "The game was a draw! No one gets a point.\n" << std::endl;
		}	
	}
	return p1 > p2 ? p1 : p2;
}

int main(int argc, const char *argv[]) {
	int p, n;
	std::cout << "How many points are required for a win?\n  -->  ";
	std::cin >> n;

	p = playGame(n);
	if (p == 1) {
		std::cout << "The human wins!" << std::endl;
	}
	else {
		std::cout << "Robots win again. Soon they will replace us..." << std::endl;
	}
	return 0;
}
