#include <iostream>
using namespace std;

class Point {
public:
	double x,y,z;
	Point() {
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}
	Point(double ax, double ay, double az) {
		x = ax;
		y = ay;
		z = az;
	}
	void printPoint() {
		std::cout << "The point is: (" << x << "," << y	<< "," << z <<")" << endl;
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
	void setZ(double az) {
		z = az;
	}
	double getZ() {
		return z;
	}
};

class ThreeDimVector {
public:
	Point head, tail, vectComponents;
	ThreeDimVector(double xComponent, double yComponent, double zComponent) {
		vectComponents.setX(xComponent);
		vectComponents.setY(yComponent);
		vectComponents.setZ(zComponent);
	}
	ThreeDimVector(Point aHead, Point aTail) {
		head = aHead;
		tail = aTail;
		makeComponents();
	}
	void makeComponents() {
		vectComponents.setX(head.getX() - tail.getX());
		vectComponents.setY(head.getY() - tail.getY());
		vectComponents.setZ(head.getZ() - tail.getZ());
	}	
	double getMagnitude() {
		double x,y,z,mag;
		x = vectComponents.getX();
		y = vectComponents.getY();
		z = vectComponents.getZ();
	        mag = (x * x) + (y * y) + (z*z);
		//square root of mag
		double low = 1.0;
        	double high = mag;
        	for (int i = 0; i < 30; i++) {
                	double currEst = (high + low) / 2;
                	if (currEst * currEst > mag) {
                        	high = currEst;
                	}
                	else if (currEst * currEst == mag) {
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
				
	Point getHead() {
		return head;
	}
	Point getTail() {
		return tail;
	}
	void setHead(Point aHead) {
		head = aHead;
		makeComponents();
	}
	void setTail(Point aTail) {
		tail = aTail;
		makeComponents();
	}
	void print() {
		head.printPoint();
		tail.printPoint();
	}

	void printVector() {
		std::cout << "<" << vectComponents.getX() << "," << vectComponents.getY() << "," << vectComponents.getZ() << ">" << endl;
	}
};

ThreeDimVector vectorAddition(ThreeDimVector a, ThreeDimVector b) {
	ThreeDimVector result((a.vectComponents.getX() + b.vectComponents.getX()), (a.vectComponents.getY() + b.vectComponents.getY()), (a.vectComponents.getZ() + b.vectComponents.getZ()));
	return result;
}

ThreeDimVector vectorSubtraction(ThreeDimVector a, ThreeDimVector b) {
	ThreeDimVector result((a.vectComponents.getX() - b.vectComponents.getX()), (a.vectComponents.getY() - b.vectComponents.getY()), (a.vectComponents.getZ() - b.vectComponents.getZ()));
	return result;
}

double dotProduct(ThreeDimVector a, ThreeDimVector b) {
	return ((a.vectComponents.getX() * b.vectComponents.getX()) + (a.vectComponents.getY() * b.vectComponents.getY()) + (a.vectComponents.getZ() * b.vectComponents.getZ()));
}

ThreeDimVector crossProduct(ThreeDimVector a, ThreeDimVector b) {
	double i,j,k;
	i = (a.vectComponents.getY() * b.vectComponents.getZ()) - (a.vectComponents.getZ() * b.vectComponents.getY());
	j = -((a.vectComponents.getX() * b.vectComponents.getZ()) - (a.vectComponents.getZ() * b.vectComponents.getX()));
	k = (a.vectComponents.getX() * b.vectComponents.getY()) - (a.vectComponents.getY() * b.vectComponents.getX());
	ThreeDimVector resultVect(i,j,k);
	return resultVect;
}

int main() {
	int x,y,z, opt;
	int coordArr[2];
	char xyz[] = {'x','y','z'};
	char charInput;
	bool isloop = true;
	double dotProductResult;

	ThreeDimVector resultVector(0,0,0);
	ThreeDimVector avec(0,0,0);
	ThreeDimVector bvec(0,0,0);

	std::cout << "Welcome to the three dimensional vector computation program!" << endl;
	while (isloop == true){
		std::cout << "You may proceed by choosing one of the below options by typing in the number corresponding to the selection.\n\t1. Create vector\n\t2. Vector addition\n\t3. Vector subtraction\n\t4. Dot product\n\t5. Cross product\n\t6. Return the magnitude of a vector\n\t7. Quit" <<"\nOption number: ";
		cin >> opt;
		if (opt == 1) {
			std::cout << "You have the option to choose between vector 'a' and vector 'b'. Please insert either 'a' or 'b' to designate which vector you would like to create :";
			cin >> charInput;
			std::cout << "A vector is composed of two points. Please input the x, y, and z coordinates of the head point as follows:"<< endl;
			for (int i = 0; i < 3; i++) {
				std::cout << "Please insert the " << xyz[i] << "-coordinate: ";
				cin >> coordArr[i];
				std::cout << xyz[i] << "-coordinate received"<<endl;
			}
			Point p(coordArr[0],coordArr[1],coordArr[2]);
			std::cout << "Now the x, y, and z coordinates of the tail point as follows: " << endl;
			for (int i = 0; i < 3; i++) {
				std::cout << "Please insert the " << xyz[i] << "-coordinate: ";
				cin >> coordArr[i];
				std::cout << xyz[i] << "-coordinate received" << endl;
			}
			Point q(coordArr[0],coordArr[1],coordArr[2]);
			if (charInput == 'a') {
				avec.setHead(p);
				avec.setTail(q);
				std::cout << "Vector a is: " << endl;
				avec.printVector();
			}
			else if (charInput == 'b') {
				bvec.setHead(p);
				bvec.setTail(q);
				std::cout << "Vector b is: " << endl;
				bvec.printVector();
			}
			else {
				std::cout << "You did not choose a correct vector designation." << endl;
			}
		}
		else if (opt == 2) {
			std::cout << "\nYou have chosen to add vector 'a' to vector 'b', which is:" << endl;
			avec.printVector();
			std::cout << "   +" << endl;
			bvec.printVector();
			resultVector = vectorAddition(avec, bvec);
			std::cout << "   ="<<endl;
			resultVector.printVector();
		}
		else if (opt == 3) {
			std::cout << "\nYou have chosen to subtract vector 'b' from vector 'a', which is:" <<endl;
			avec.printVector();
			std::cout << "   -" << endl;
			bvec.printVector();
			resultVector = vectorSubtraction(avec, bvec);
			std::cout << "   = " << endl;
			resultVector.printVector();
		}
		else if (opt == 4) {
			std::cout << "\nYou have chosen to take the dot product of 'a' and 'b', which is:" << endl;
			avec.printVector();
			std::cout <<"  dot" << endl;
			bvec.printVector();
			dotProductResult = dotProduct(avec, bvec);
			std::cout << "   = \n  " << dotProductResult << endl;
		}	
		else if (opt == 5) {
			std::cout << "\nYou have cosen to take the cross product of 'a' and 'b', which is:" << endl;
			avec.printVector();
			std::cout << "   X" << endl;
			bvec.printVector();
			resultVector = crossProduct(avec, bvec);
			std::cout << "   =" << endl;
			resultVector.printVector();	
		}
		else if (opt == 6) {
			std::cout << "You have chosen to return the magnitude of a vector. Choose 'a' or 'b' by entering the matching character: ";
			std::cin >> charInput;
			if (charInput == 'a') {
				dotProductResult= avec.getMagnitude();
			}
			else {
				dotProductResult = bvec.getMagnitude();
			}	
		std::cout << "The vector " << charInput << " has a magnitude of " << dotProductResult << endl;
		}
		else if (opt == 7) {	
			std::cout << "Goodbye!" << endl;
			isloop = false;
		}
	}
	return 0;
}

