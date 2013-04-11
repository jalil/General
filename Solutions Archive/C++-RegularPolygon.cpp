#include <iostream>
#include <cmath>
         
using namespace std;

double areaRegPolygon(double sideLen, double numSides) {
	return (((sideLen * sideLen) * numSides) / (4 * tan(M_PI / numSides)));
}

int main(int argc, const char *argv[]) {
	double sides, len;
	cout << "Give me the number of sides of the n-gon: ";
	cin >> sides;
	cout << "Give me the length of a side of the n-gon: ";
	cin >> len;
	cout << "The regular polygon with " << sides << " sides and a side length of " << len << " has area " << areaRegPolygon(len, sides) << endl;
	return 0;
}

