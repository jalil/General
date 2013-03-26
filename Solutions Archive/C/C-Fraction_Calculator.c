//---------------------------------------------------------------------------
//
// Name: Fraction Calculator
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
	int num1, num2, denom1, denom2, num3, denom3, isLoop = 1;
	char op, input[3], charContinue;
	printf("Welcome to the fraction calculator program!\n");
	while (isLoop == 1) {
		printf("Please insert the first numerator:\n");
		scanf("%s", input);
		num1 = atoi(input);
		fflush(NULL);
		printf("Please insert the first denominator:\n");
		scanf("%s", input);
		denom1 = atoi(input);
		fflush(NULL);
		printf("This gives us a fraction of %i/%i.\n", num1,denom1);

                printf("Please insert the second numerator:\n");
                scanf("%s", input);
		num2 = atoi(input);
                fflush(NULL);
                printf("Please insert the second denominator:\n");
                scanf("%s", input);
		denom2 = atoi(input);
                fflush(NULL);
		printf("This gives us a second fraction of %i/%i.\n", num2,denom2);
		printf("Please insert the operand for the computation: [+ or - or * or /]\n");
		scanf("%s", &op);
		switch(op) {
			case '+':
				printf("You have chosen addition.\n");
				if (denom1 != denom2) {
					denom3 = denom1 * denom2;
					num1 = num1 * denom2;
					num2 = num2 * denom1;
					num3 = num1 + num2;
					denom1 = denom3;
					denom2 = denom3;
				}
				else {
					denom3 = denom1;
					num3 = num1 + num2;
				}
				break;
			case '-':
				printf("You have chosen substraction.\n");
				if (denom1 != denom2) {
					denom3 = denom1 * denom2;
					num1 = num1 * denom2;
					num2 = num2 * denom1;
					num3 = num1 - num2;
					denom1 = denom3;
					denom2 = denom3;
				}
				else {
					denom3 = denom1;
					num3 = num1 - num2;
				}
				break;
			case '*':
				printf("You have chosen multiplication.\n");
				num3 = num1 * num2;
				denom3 = denom1 * denom2;		
				break;
			case '/':
				printf("You have chosen division.\n");
				num3 = num1 * denom2;
				denom3 = denom1 * num2;
				break;
		}
		printf("Thus, we have %i/%i %c %i/%i = %i/%i.\n",num1,denom1,op,num2,denom2,num3,denom3);
		printf("Would you like a simplified answer? [y/n]\n");
		scanf("%s", &charContinue);
		if (charContinue == 'y') {	
			int gcd;  
			gcd = GCD(num3,denom3);
			if (gcd != 0) {
				if (num3 == (num3 / gcd)) {
					printf("Your fraction could not be simplified any further.\n");
				}
				else {
					num3 = num3 / gcd;
					denom3 = denom3 / gcd;
					printf("Your simplified fraction is %i/%i.\n", num3, denom3);
				}
			}
			else {
				printf("Your simplified fraction is 0.\n");	
			}
		}
		printf("Would you like to continue? [y/n]\n");
		scanf("%s", &charContinue);
		if (charContinue != 'y') {
			printf("Goodbye!\n");
			isLoop = 0;
		}
	}
	return 0;
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

