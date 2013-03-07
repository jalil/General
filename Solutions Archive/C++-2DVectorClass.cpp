#include <iostream>
using namespace std;

class Point {
public:
	double x,y;
	Point() {
		x = 0.0;
		y = 0.0;
	}
	Point(double ax, double ay) {
		x = ax;
		y = ay;
	}
	void printPoint() {
		std::cout << "The point is: (" << x << "," << y	<< ")" << endl;
	}
	void setX(double ax) {
		x = ax;
	}
	double getX() {
		return x;
	}
	void setY(double ay) {
		y = ay;
	}
	double getY() {
		return y;
	}
};

class TwoDimVector {
public:
	Point head, tail;
	TwoDimVector(double x0, double y0, double x1, double y1) {
		head.setX(x1);
		head.setY(y1);
		tail.setX(x0);
		tail.setY(y0);
	}
	TwoDimVector( Point aHead, Point aTail) {
		head = aHead;
		tail = aTail;
	}
	Point getHead() {
		return head;
	}
	Point getTail() {
		return tail;
	}
	void setHead(Point aHead) {
		head = aHead;
	}
	void setTail(Point aTail) {
		tail = aTail;
	}
	void print() {
		head.printPoint();
		tail.printPoint();
	}
	void printVector() {
		std::cout << "The head has point (" << head.getX() << "," << head.getY() << ")" << " and the tail has point (" << tail.getX() << "," << tail.getY() << ")" << endl;
	}
};

int main() {
	int x,y;
	char charInput;
	bool isloop = true;
	std::cout << "Welcome to the simple two dimensional vector representation program!" << endl;
	while (isloop == true){
		std::cout << "A vector is composed of two points. Please give me the x-coordinate of the head vector:";
		std::cin >> x;
		std::cout << "Now the y-coordinate of the head vector: ";
		std::cin >> y;
		Point p(x,y);
		std::cout << "Now the x-coordinate of the tail vector: ";
		std::cin >> x;
		std::cout << "Finally, the y-coordinate of the tail vector: ";
		std::cin >> y;
		Point q(x,y);
		TwoDimVector vec(p,q);
		vec.printVector();
		std::cout <<"Would you like to continue? [y/n]" << endl;
		std::cin >> charInput;
		if (charInput != 'y') {	
			std::cout << "Goodbye!" << endl;
			isloop = false;
		}
	}
	return 0;
}

