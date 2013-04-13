#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

int main(int argc, const char *argv[]) {
	const long unsigned int NUM_ROLLS = 1000000;
	unsigned int i, dieRoll;
	std::map<int, int> mRolled;
	
	srand(time(0)); // seed random number generator based on current time

	for (i = 0; i < NUM_ROLLS; i++) {
		dieRoll = (rand() % 6) + 1;
		if (mRolled.find(dieRoll) == mRolled.end()) {
			mRolled[dieRoll] = 1;
		}
		else {
			mRolled[dieRoll] += 1;
		}
		std::cout << "Iteration " << i << " --> Die roll of " << dieRoll << std::endl;
	}

	std::cout << "After rolling " << NUM_ROLLS << " times, we have that:" << std::endl;
	for (std::map<int, int>::iterator it = mRolled.begin(); it != mRolled.end(); it++) {
		std::cout << "The die roll of " << it->first << " occurred " << it->second << " times with a frequency of " << ((double) it->second) / NUM_ROLLS << std::endl;
	}
	
	return 0;
}	
