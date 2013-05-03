#include <stdio.h>
#include <stdlib.h>

int mults3or5(int u) {
	int i, s = 0;
	for (i = 0; i < u; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			s += i;
		}
	}
	return s;
}


int main(int argc, const char *argv[]) {	
	int u, k;

	printf("Give me an upper bound for the summation for the multiples of 3 or 5: ");
	scanf("%d", &u);

	k = mults3or5(u);
	printf("The summation from 0 to %d where the index variable is a multiple of 3 or 5 is %d\n", u, k);
	
	return 0;
}

