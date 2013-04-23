#include <iostream>
#include <string>

class Fraction {
	private:
		int numerator, denominator;
	public:
		//accessor methods
		void setNumerator(int n);
		int getNumerator();
		void setDenominator(int d);
		int getDenominator();

		//constructors
		Fraction();
		Fraction(int, int);
		
		//operator overloading
		Fraction operator+ (Fraction);
		Fraction operator- (Fraction);
		Fraction operator* (Fraction);
		Fraction operator/ (Fraction);
		
		//util methods
		std::string print();
		int GCD(int a, int b);
		void reduce();
};
//Method declarations
void Fraction::setNumerator(int n) { numerator = n; }

void Fraction::setDenominator(int d) { denominator = d;}	

int Fraction::getNumerator() { return numerator;}

int Fraction::getDenominator() { return denominator;}

Fraction::Fraction() {
	numerator = 1;
	denominator = 1;
}

Fraction::Fraction(int a, int b) {
	numerator = a;
	denominator = b;
	reduce();
}

Fraction Fraction::operator* (Fraction b) {
	return Fraction ((numerator * b.getNumerator()), (denominator * b.getDenominator()));
}

Fraction Fraction::operator/ (Fraction b) {
	return Fraction ((numerator * b.getDenominator()), (denominator * b.getNumerator()));
}

Fraction Fraction::operator+ (Fraction b) {
	int numc, denc;

	if (numerator == 0 || b.getNumerator() == 0) {
		if (numerator != 0) {
			return Fraction(numerator, denominator);
		}
		else {
			return Fraction(b.getNumerator(), b.getDenominator());
		}
	}
	else {
		return Fraction((numerator * b.getDenominator()) + (denominator * b.getNumerator()), denominator * b.getDenominator());
	}
}

Fraction Fraction::operator- (Fraction b) {
	int numc, denc;

	if (numerator == 0 || b.getNumerator() = 0) {	
		if (numerator != 0) {
			return Fraction(numerator, denominator);
		}
		else {
			return Fraction(b.getNumerator(), b.getDenominator());
		}
	}
	else {
		Fraction((numerator * b.getDenominator()) - (denominator * b.getNumerator()), (denominator * b.getDenominator());
	}
}	

std::string Fraction::print() {
	return std::to_string(numerator) + " / " + std::to_string(denominator);
}

int Fraction::GCD(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	
	int a1, b1, c = 0;

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

void Fraction::reduce() {
	int gcd;
		
	if (numerator == 0 || denominator == 0) {
		numerator = 0;
		denominator = 0;
	}
	else {
		gcd = GCD(numerator, denominator);
		setNumerator(numerator / gcd);
		setDenominator(denominator / gcd);
	}
}


int main(int argc, const char *argv[]) {
	int a, b;

	std::cout << "Give me a numerator: ";
	std::cin >> a;
	std::cout << "Give me a denominator: ";
	std::cin >> b;

	Fraction a1(a,b);
	std::cout << "The first fraction is " << a1.print() << std::endl;

	std::cout << "Give me a second numerator: ";
	std::cin >> a;
	std::cout << "Give me a second denominator: ";
	std::cin >> b;

	Fraction a2(a,b);
	std::cout << "The second fraction is " << a2.print() << std::endl;

	//Computation
	std::cout << "The following operations are completed: " << std::endl;	

	Fraction a3 = a1 + a2;
	std::cout << "ADDITION: " << a1.print() << " plus " << a2.print() << " is " << a3.print() << std::endl;
	a3 = a1 - a2;
	std::cout << "SUBTRACTION: " << a1.print() << " minus " << a2.print() << " is " << a3.print() << std::endl;
	a3 = a1 * a2;
	std::cout << "MULTIPLICATION: " << a1.print() << " multiplied by " << a2.print() << " is " << a3.print() << std::endl;

	a3 = a1 / a2;
	std::cout << "DIVISION: " << a1.print() << " divided by " << a2.print() << " is " << a3.print() << std::endl;

	return 0;
}



