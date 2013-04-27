#include <iostream>
#include <string>

double exponent(double base, unsigned int exponent) {
	int i;
	double out = 1.0;
	for (i = 0; i < exponent; i++) {
		out *= base;
	}
	return out;
}
	

double sqroot(double in) {
	int i;
	double currEst, low = 1.0, high = in;
	if (in < 1.0) {
		return -1.0;
	}
	else {
		for (i = 0; i < 30; i++) {
			currEst = (high + low) / 2;
			if (currEst * currEst > in) {
				high = currEst;
			}
			else if (currEst * currEst == in) {
				return currEst;
			}
			else {
				low = currEst;
			}
		}
		return currEst;
	}
}

double pythagDist(double a, double b) {
	return sqroot(exponent(a, 2) + exponent(b, 2));
}

int main(int argc, const char *argv[]) {
	double x1,y1,x2,y2;
	std::cout << "What is the x-coordinate of the first point?\n  -->  ";
	std::cin >> x1;
	std::cout << "What is the y-coordinate of the first point?\n  -->  ";
	std::cin >> y1;
	std::cout << "What is the x-coordinate of the second point?\n  -->  ";
	std::cin >> x2;
	std::cout << "What is the y-coordinate of the second point?\n  -->  ";
	std::cin >> y2;

	std::cout << "The length of the line connecting the point (" << x1 << ", " << y1 << ") and the point (" << x2 << ", " << y2 << ") is " << pythagDist(x2 - x1, y2 - y1) << std::endl;
	return 0;
}
		
