/* program that takes the number of stairs as input and returns the permutations of 1 stair step and 2 stair steps to reach the top*/
#include <iostream>

using namespace std;

int numPermStairs(int n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	else {
		return numPermStairs(n - 2) + numPermStairs(n - 1);
	}
}

int altNumPermStairs(int n) {
	int l1 = 1, l2 = 1, c, i;

	for (i = 0; i < n - 1; ++i) {
		c = l1 + l2;
		l2 = l1;
		l1 = c;
	}
	return c;
}

int main(int argc, const char *argv[]) {
	int i;
	cout << "How many stairs are in the staircase?\n  -->  ";
	cin >> i;

	cout << "With " << i << " stair(s) in the staircase, there are " << numPermStairs(i) << " permutations of one and two steps to reach the top" << endl;

	cout << altNumPermStairs(i) << endl;

	return 0;
}

 
