#include <iostream>
#include <vector>
#include <utility>

double letterGradeToNum(std::string s) {
	double out;
	//Use only the first character of the grade -- we will not consider A+, A-, etc.
	char c = s[0];
	switch(c) {
		case 'a':
		case 'A':
			out = 4.0;
			break;
		case 'b':
		case 'B':
			out = 3.0;
			break;
		case 'c':
		case 'C':
			out = 2.0;
			break;
		case 'd':
		case 'D':
			out = 1.0;
			break;
		default:
			out = 0.0;
			break;
	}
	return out;
}
	

double computeGPA(std::vector<std::pair<std::string, int> > v) {
	double sumHours, sumGPA;
	sumGPA = sumHours = 0.0;		

	for (std::vector<std::pair<std::string, int> >::iterator it = v.begin(); it != v.end(); it++) {
		sumGPA += letterGradeToNum(std::get<0>(*it)) * std::get<1>(*it);
		sumHours += std::get<1>(*it);
	}
	
	return sumGPA / sumHours;
}


int main(int argc, const char *argv[]) {
	int i,j,k;
	std::string grade;
	std::vector<std::pair<std::string, int> > v;
	
	std::cout << "How many classes are you taking?\n  -->  ";
	std::cin >> j;

	for (i = 0; i < j; i++) {
		std::cout << "\nGive me the letter grade for class " << i + 1 << ": ";
		std::cin >> grade;

		std::cout << "Give me the number of credit hours: ";
		std::cin >> k;

		v.push_back(std::make_pair(grade, k));
	}

	std::cout << "\n\nGiven the classes listed, your GPA is " << computeGPA(v) << std::endl;
	return 0;
}
	
