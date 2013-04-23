#include <iostream>
#include <string>

class C2DVector {
	public:
	int x,y;
	C2DVector() {x = 0; y = 0;}
	C2DVector (int, int);
	//vector addition
	C2DVector operator + (C2DVector);
	//vector subtraction
	C2DVector operator - (C2DVector);
	
	std::string print();
};

C2DVector::C2DVector(int head, int tail) {
	x = head;
	y = tail;
}

C2DVector C2DVector::operator+ (C2DVector argumentVector) {
	return C2DVector(x + argumentVector.x, y + argumentVector.y);
}

C2DVector C2DVector::operator- (C2DVector argumentVector) {
	return C2DVector(x - argumentVector.x, y - argumentVector.y);
}

std::string C2DVector::print() {
	std::string s = "<" + std::to_string(x) + ", " + std::to_string(y) + ">";
	return s;
}

int main(int argc, const char *argv[]) {
	int a,b,c,d;

	std::cout << "Give me the x value of the first vector: ";
	std::cin >> a;
	
	std::cout << "Give me the y value of the first vector: ";
	std::cin >> b;

	std::cout << "Give me the x value of the second vector: ";
	std::cin >> c;
	
	std::cout << "Give me the y value of the second vector: ";
	std::cin >> d;

	C2DVector firstVector(a,b);
	C2DVector secondVector(c,d);
	C2DVector resultVector;

	std::cout << "\nThe first vector is " << firstVector.print() << " and the second vector is " << secondVector.print() << "." << std::endl;
	
	resultVector = firstVector + secondVector;
	std::cout << "The result of " << firstVector.print() << " + " << secondVector.print() << " is " << resultVector.print() << std::endl;
	
	resultVector = firstVector - secondVector;
	std::cout << "The result of " << firstVector.print() << " - " << secondVector.print() << " is " << resultVector.print() << std::endl;

	return 0;
}

