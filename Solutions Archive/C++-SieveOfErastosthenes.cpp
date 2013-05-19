#include <iostream>
#include <vector>

double squareRoot(int num) {
        double low = 1.0;
        double high = (double) num;
        if (num >= 1) {
		for (int i = 0; i < 30; i++) {
                	double currEst = (high + low) / 2;
               		if (currEst * currEst > num) {
                	        high = currEst;
               		}
                	else if (currEst * currEst == num) {
                        	return currEst;
                	}
                	else {
                        	low = currEst;
                	}
                	if (i == 29) {
                        	return currEst;
                	}
        	}
	}
        else {
		return -1;
	}
}

std::vector<int> sieveOfErastosthenes(int n) {
	int i,j;
	std::vector<int> primes;
	std::vector<bool> valsToCheck(n, true);

	for (i = 2; i < n; ++i) {
		for (j = 2; j < squareRoot(n); ++j) {
			valsToCheck[j * i] = false;
		}
	}
	
	for (i = 2; i < n; ++i) {
		if (valsToCheck[i]) {
			primes.push_back(i);
		}
	}

	return primes;	
}
	

int main(int argc, const char *argv[]) {
	int n;
	std::cout << "What is the upper bound of the range for which you would like to find prime numbers?\n  -->  ";
	std::cin >> n;

	std::vector<int> v = sieveOfErastosthenes(n);

	std::cout << "The primes we have found between 2 and " << n << " are as follows:" << std::endl;

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << std::endl;
	}
	
	return 0;
}


