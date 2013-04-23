#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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
		
		//destructors
		~Fraction();

		//computation options
		Fraction multiply(Fraction b);
		Fraction divide(Fraction b);
		Fraction add(Fraction b);
		Fraction subtract(Fraction b);
		
		//util methods
		string print();
		string intToStr(int n);
		int GCD(int a, int b);
		void reduce();
};
//Method declarations
void Fraction::setNumerator(int n) { numerator = n;}

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

Fraction::~Fraction() {}

Fraction Fraction::multiply(Fraction b) {
	Fraction c((numerator * b.getNumerator()), (denominator * b.getDenominator()));
	return c;
}

Fraction Fraction::divide(Fraction b) {
	Fraction c((numerator * b.getDenominator()), (denominator * b.getNumerator()));
	return c;
}

Fraction Fraction::add(Fraction b) {
	int numc, denc;

	numc = (numerator * b.getDenominator()) + (denominator * b.getNumerator());
	denc = denominator * b.getDenominator();

	return Fraction(numc, denc);
}

Fraction Fraction::subtract(Fraction b) {
	int numc, denc;
	
	numc = (numerator * b.getDenominator()) - (denominator * b.getNumerator());
	denc = denominator * b.getDenominator();

	return Fraction(numc, denc);
}	

string Fraction::print() {
	return intToStr(numerator) + " / " + intToStr(denominator);
}

string Fraction::intToStr(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
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
	int gcd = GCD(numerator, denominator);
	setNumerator(numerator / gcd);
	setDenominator(denominator / gcd);
}


int main(int argc, const char *argv[]) {
	int a, b;

	cout << "Give me a numerator: ";
	cin >> a;
	cout << "Give me a denominator: ";
	cin >> b;

	Fraction a1(a,b);
	cout << "The first fraction is " << a1.print() << endl;

	cout << "Give me a second numerator: ";
	cin >> a;
	cout << "Give me a second denominator: ";
	cin >> b;

	Fraction a2(a,b);
	cout << "The second fraction is " << a2.print() << endl;

	//Computation
	cout << "The following operations are completed: " << endl;	

	Fraction a3 = a1.add(a2);
	cout << "ADDITION: " << a1.print() << " plus " << a2.print() << " is " << a3.print() << endl;
	a3 = a1.subtract(a2);
	cout << "SUBTRACTION: " << a1.print() << " minus " << a2.print() << " is " << a3.print() << endl;
	a3 = a1.multiply(a2);
	cout << "MULTIPLICATION: " << a1.print() << " multiplied by " << a2.print() << " is " << a3.print() << endl;

	a3 = a1.divide(a2);
	cout << "DIVISION: " << a1.print() << " divided by " << a2.print() << " is " << a3.print() << endl;

	return 0;
}



