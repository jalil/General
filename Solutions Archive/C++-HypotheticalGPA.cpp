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
	

std::pair<double, int> computeGPA(std::vector<std::pair<std::string, int> > v) {
	double sumHours, sumGPA;
	sumGPA = sumHours = 0.0;		

	for (std::vector<std::pair<std::string, int> >::iterator it = v.begin(); it != v.end(); it++) {
		sumGPA += letterGradeToNum(std::get<0>(*it)) * std::get<1>(*it);
		sumHours += std::get<1>(*it);
	}
	
	return std::make_pair(sumGPA / sumHours, sumHours);
}

std::vector<std::vector<std::pair<std::string, int> > > getHypotheticalSemesters(int n) {
	int i, j, k, m;
	std::string letterGrade;

	std::vector<std::vector<std::pair<std::string, int> > > hypotheticalSemesters;

	for (i = 0; i < n; ++i) {
		std::cout << "\nPossible Semester " << i + 1 << ": " <<  std::endl;
		std::cout << "\nHow many classes are you considering taking?\n  -->  ";
		std::cin >> m;
		
		std::vector<std::pair<std::string, int> > semester;		

		for (j = 0; j < m; ++j) {
			std::cout << "\nGive me the letter grade for class " << j + 1 << ": ";
			std::cin >> letterGrade;

			std::cout << "Give me the number of credit hours for the class: ";
			std::cin >> k;
	
			semester.push_back(std::make_pair(letterGrade, k));
		}
		hypotheticalSemesters.push_back(semester);
	}
	return hypotheticalSemesters;
}


std::vector<std::pair<double, int> > hypotheticalGPA(std::vector<std::vector<std::pair<std::string, int> > > v) {
	std::vector<std::pair<double, int> > dv; 
	for (std::vector<std::vector<std::pair<std::string, int> > >::iterator it = v.begin(); it != v.end(); ++it) {
		dv.push_back(computeGPA(*it));
	}
	return dv;
}

int main(int argc, const char *argv[]) {
	int n, numHours;
	double gpaSoFar;
	std::string grade;
	
	std::vector<std::pair<double, int> > gpas;
	
	std::cout << "How many credit hours have you taken?\n  -->  ";
	std::cin >> numHours;
	std::cout << "What is your current GPA?\n  -->  ";
	std::cin >> gpaSoFar;

	

	std::cout << "How many hypothetical semesters would you like to compute?\n  -->  ";
	std::cin >> n;
	
	gpas = hypotheticalGPA(getHypotheticalSemesters(n));

	std::cout << "Outcomes of the possible semesters:" << std::endl;
	for (std::vector<std::pair<double, int> >::iterator it =  gpas.begin(); it != gpas.end(); ++it) {
		std::cout << "In semester " << gpas.end() - it << " you would have a semester GPA of " << std::get<0>(*it) << " and an overall GPA of " << (gpaSoFar * numHours + std::get<0>(*it) * std::get<1>(*it)) / ( numHours + std::get<1>(*it)) << std::endl;
	}

	return 0;
}
	
