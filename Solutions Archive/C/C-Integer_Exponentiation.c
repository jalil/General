//---------------------------------------------------------------------------
//
// Name: Integer powers (i.e. x-squared)
//
// Author: Braden Lenz
//
// Created: 2/13/13
//
// Licence: GNU GPL (v3)
//
//---------------------------------------------------------------------------

#include <stdio.h>

int main(void) {
	int base, power, returnval, isLoop = 1;
	char input[3], charContinue;
	printf("Welcome to the integer powers program!\n");
	while (isLoop ==1) {
		printf("Please type in the base of the integer power (i.e. the 2 in 2^5):\n");
		scanf("%s", input);
		base = atoi(input);
		fflush(NULL);	

		printf("Please type in the power of the integer power (i.e. the 5 in 2^5):\n");
		scanf("%s", input);
		power = atoi(input);
		fflush(NULL);		

		returnval = exponentiate(base, power);
		printf("The result of %i^%i is %i.\n", base, power, returnval);
		
		printf("Would you like to continue? [y/n]\n");
		scanf("%s", &charContinue);
		fflush(NULL);
		if (charContinue != 'y') {
			printf("Goodbye!\n");
			isLoop = 0;
		}
	}
	return 0;
}

int exponentiate(int base, int power) {
	int returnVal, i = 0;
	if (power == 0) {
		return 1;
	}
	else if (power == 1) {
		return base;
	}
	else {
		returnVal = base;
		while ( i < power - 1) {
			returnVal = returnVal * base;
			i = i + 1;
		}
		return returnVal;
	}
}
