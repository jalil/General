#include "C++-TrigonometryLibrary.cpp"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
	int i;
	double x;

	cout <<"You have the following choices:\n1 -> sine\n2 -> cosine\n3 -> tangent\n4 -> cotangent\n5 -> secant\n6 -> cosecant\nWhich would you like to do?\n --> ";
	cin >> i;

	cout << "What value would you like to pass to the chosen function: ";
	cin >> x;

	switch(i) {
		case 1:
	 		cout << "The value of sine(" << x <<") is " << sine(x) << endl;
			break;
		case 2:
			cout << "The value of cosine(" << x << ") is " << cosine(x) << endl;
			break;
		case 3:
			cout << "The value of tangent(" << x << ") is " << tangent(x) << endl;
			break;
		case 4:
			cout << "The value of cotangent(" << x << ") is " << cotangent(x) << endl;
			break;
		case 5:
			cout << "The value of secant(" << x << ") is " << secant(x) << endl;
			break;
		case 6:
			cout << "The value of cosecant(" << x << ") is " << cosecant(x) << endl;
			break;
		default:
			cout << "You did not provide a number mapping to a function. I suppose that " << x << " is " << x << endl;
			break;
	}
	
	return 0;
}
	
