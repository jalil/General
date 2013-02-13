#include <stdio.h>

int main(void) {
	int n, intfact;
	char strfact[3], charContinue;
	int isLoop = 1;
	printf("Welcome to the factorial calculation program!\n");
	while (isLoop == 1) {
		printf("Please type in the factorial number you would like to receive as output:\n");
		scanf("%s", strfact);
		fflush(NULL);
		
		n = atoi(strfact);
		intfact = factorial(n);
		printf("The %ith factorial is %i.\n", n, intfact);

		printf("Would you like to continue? [y/n]\n");
		scanf("%s", &charContinue);
		if (charContinue != 'y') {
			isLoop = 0;
			printf("Goodbye!\n");
		}
	}
	return 0;
}

int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}
