//----------------------------------------------------------------------------
//
// Name: Greatest Common Divisor
//
// Author: Braden Lenz
//
// Created: 2/13/2013
//
// Licence: GNU GPL (v3)
//
//----------------------------------------------------------------------------
#include <stdio.h>


int main(void)
{
	int a,b,c;
	char input[3];
	char char_input;
	int isLoop = 1;
	printf("Welcome to the GCD program!\n");
	while (isLoop == 1)
	{

		printf("Please insert the first number (max of 3 characters):\n");
		scanf("%s", input);
		a = atoi(input);
		fflush(NULL);

		printf("Please insert the second number (max of 3 characters):\n");
		scanf("%s", input);
		b = atoi(input);
		fflush(NULL);	

		c = GCD(a,b);
		printf("The GCD of %i and %i is %i.\n", a,b,c);
	
		printf("Would you like to continue? [y/n]:\n");
		scanf("%s", &char_input);
		fflush(NULL);
		
		if (char_input != 'y') 
		{
			isLoop = 0;
			printf("Goodbye!\n");

		}	
	}
	
	return 0;
}

		
	
int GCD(int a, int b)
{
	int c = 0;
	int a1, b1;
	if (a > b) 
	{
		a1 = a;
		b1 = b;
	}
	else 
	{
		a1 = b;
		b1 = a;
 	}		
	if (b == 0) 
	{
		return a;
	}
	else if (a != 0 && b != 0)
	{
		c = a % b;
		return GCD(b, c);
	}
}	 
