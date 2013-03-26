//---------------------------------------------------------------------------
//
// Name: Absolute Value
//
// Author: Braden Lenz
//
// Created: 2/13/2013
//
// Licence: GNU GPL (v3)
//
//---------------------------------------------------------------------------

#include <stdio.h>

int main(void) {
	int n, absN;
	char input[9], charContinue;
	printf("Welcome to the absolute value program!\n");
	int isLoop = 1;
	while (isLoop == 1) {
		printf("Please insert the number you would like to put into an absolute value:\n");
		scanf("%s", input);
		n = atoi(input);
		fflush(NULL);
		absN = absVal(n);
		printf("The absolute value of %i is %i.\n", n,absN);
		printf("Would you like to continue? [y/n]\n");
		scanf("%s", &charContinue);
		if (charContinue != 'y') {
			printf("Goodbye!\n");
			isLoop = 0;
		}
	}
	return 0;
}


int absVal(int n) {
	if (n >= 0) {
		return n;
	}
	else {
		return -n;
	}
}

