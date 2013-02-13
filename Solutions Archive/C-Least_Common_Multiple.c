//---------------------------------------------------------------------------
//
// Name: Least Common Multiple
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
	int a,b,c,d,e;
	char input[3], continueChar;
	int isLoop =1;
	printf("Welcome to the least common multiple program!\n");
	while (isLoop == 1) {
		printf("Please type in the first number:\n");
		scanf("%s", input);
		a = atoi(input);
		fflush(NULL);

		printf("Please type in the second number:\n");
		scanf("%s", input);
		b = atoi(input);
		fflush(NULL);
		
		if (a == 0 || b == 0) {
			e = 0;
		}
		else {
			c = a * b;
			c = absVal(c);
			d = GCD(a,b);
			e = c / d;
		}	
		printf("The LCM of %i and %i is %i.\n", a,b,e);
		printf("Would you like to continue? [y/n]\n");
		scanf("%s", &continueChar);
		if (continueChar != 'y') {
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

int GCD(int a, int b) {
        if (a == 0 || b == 0) {
                return 0;
        }
        else {
                int c = 0;
                int a1, b1;

                if (a > b) {
                        a1 = a;
                        b1 = b;
                }

                else {
                        a1 = b;
                        b1 = a;
                }

                while (b1 != 0) {
                        c = a1 % b1;
                        a1 = b1;
                        b1 = c;
                }
                return a1;
        }
}
