#include <iostream>

int main(int argc, const char *argv[]) {
	int i, j, k = 0;
	enum ship {SCOUT = 10, FIGHTER = 50, BOMBER = 100, MOTHERSHIP = 500};
	
	for (i = 0; i < 5; i++) {
		std::cout << "What type of ship did you destroy?\n 1 -- > Scout ship\n 2 --> Fighter\n 3 --> Bomber\n 4 --> Mothership\n Give me the number of the ship you destroyed: ";
		std::cin >> j;
		switch(j) {
			case 1:
				k += SCOUT;
				break;
			case 2:
				k += FIGHTER;
				break;
			case 3:
				k += BOMBER;
				break;
			case 4:
				k += MOTHERSHIP;
				break;
		}
		std::cout << "You have destroyed " << i + 1 << " ships which means that you have " << k << " points so far!" << std::endl;
	}
	std::cout << "After destroying 5 ships your final score is " << k << std::endl;
	return 0;
}
	
