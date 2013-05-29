#include <iostream>
#include <string>
#include <vector>

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
		bool operator== (Fraction);
		bool operator> (Fraction);
		bool operator< (Fraction);
		Fraction operator+ (Fraction);
		Fraction operator- (Fraction);
		Fraction operator* (Fraction);
		Fraction operator/ (Fraction);
		
		//util methods
		std::string print();
		int GCD(int a, int b);
		void reduce();
		void negateQuot();
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
	negateQuot();
}

bool Fraction::operator==(Fraction b) {
	return (numerator == b.getNumerator()) && (denominator == b.getDenominator());
}

bool Fraction::operator>(Fraction b) {
	float f1, f2;
	if (denominator != 0) {
		f1 = numerator / (float) denominator;
	}
	else {
		f1 = 0.0;
	}

	if (b.getDenominator() != 0) {	
		f2 = b.getNumerator() / (float) b.getDenominator();
	}
	else {
		f2 = 0.0;
	}
	return (f1 > f2);
}

bool Fraction::operator<(Fraction b) {
	float f1, f2;
	if (denominator != 0) {
		f1 = numerator / (float) denominator;
	}
	else {
		f1 = 0.0;
	}
	if (b.getDenominator() != 0) {
		f2 = b.getNumerator() / (float) b.getDenominator();
	}
	else {
		f2 = 0.0;
	}
	return (f1 < f2);
}

Fraction Fraction::operator* (Fraction b) {
	return Fraction ((numerator * b.getNumerator()), (denominator * b.getDenominator()));
}

Fraction Fraction::operator/ (Fraction b) {
	return Fraction ((numerator * b.getDenominator()), (denominator * b.getNumerator()));
}

Fraction Fraction::operator+ (Fraction b) {
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
	if ( numerator == 0 || b.getNumerator() == 0) {	
		if (numerator != 0) {
			return Fraction(numerator, denominator);
		}
		else {
			return Fraction(b.getNumerator(), b.getDenominator());
		}
	}
	else {
		return Fraction((numerator * b.getDenominator()) - (denominator * b.getNumerator()), (denominator * b.getDenominator()));
	}
}	

std::string Fraction::print() {
	return std::to_string(numerator) + "/" + std::to_string(denominator);
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

void Fraction::negateQuot() {
	if ((numerator < 0 && denominator < 0) || (numerator >= 0 && denominator < 0)){
		numerator = -numerator;
		denominator = -denominator;
	}
}


std::string printVectorFraction(std::vector<Fraction> vF) {
	std::string s = "<";
	for (std::vector<Fraction>::iterator it = vF.begin(); it != vF.end(); ++it) {
		s += (*it).print() + ", ";
	}
	return s.substr(0, s.length() - 2) + ">";
}	

void gnomeSort(std::vector<Fraction>& vF) {
	std::vector<Fraction>::iterator it = vF.begin();
	while (it + 1 != vF.end()) {
		if (*it > *(it + 1)) {
			std::iter_swap(it, it + 1);
			if (it != vF.begin()) {
				--it;
			}
		}
		else {
			++it;
		}
	}
}


int main(int argc, const char *argv[]) {
	int a, b, n, i;
	std::vector<Fraction> fractionVector;
	
	std::cout << "How many fractions would you like to create?\n  -->  ";
	std::cin >> n;
	
	for (i = 0; i < n; ++i) {
		std::cout << "Fraction " << i + 1 << ":" << std::endl;
		std::cout << "Give me a numerator: ";
		std::cin >> a;
		std::cout << "Give me a denominator: ";
		std::cin >> b;
		fractionVector.push_back(Fraction(a,b));
	}

	std::cout << "Your fraction vector is " << printVectorFraction(fractionVector) <<  std::endl;

	gnomeSort(fractionVector);
	
	std::cout << "Your sorted fraction vector is " << printVectorFraction(fractionVector) << std::endl;
	
	return 0;
}
	




