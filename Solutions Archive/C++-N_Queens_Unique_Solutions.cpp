#include <iostream>
#include <vector>
#include <string>

class SolutionFilter {
	private:
		int n;
		std::vector<std::vector<int> > encodedSolutions;
		std::vector<std::vector<std::vector<int> > > decodedSolutions;
		
		std::string printMat(std::vector<std::vector<int> >);
		void rotate90(std::vector<std::vector<int> >&);
		bool isIn(int, std::vector<int>);
		bool isUnique(std::vector<std::vector<int> >, std::vector<std::vector<int> >);
		std::vector<std::vector<int> > mirror(std::vector<std::vector<int> >);
		std::vector<std::vector<int> > rotate(int, std::vector<std::vector<int> >);
		std::vector<std::vector<std::vector<int> > > decodeSolutions(std::vector<std::vector<int> >);
		void encodeSolutions(void);
	public:
		SolutionFilter(std::vector<std::vector<int> >);
		~SolutionFilter();
		std::vector<std::vector<int> > getUniques(void);
};

SolutionFilter::SolutionFilter(std::vector<std::vector<int> > v) {
	if (!v.empty()) {
		n = v[0].size();
	}
	else {
		n = 0;
	}

	encodedSolutions = v;
	decodedSolutions = decodeSolutions(encodedSolutions);
}

SolutionFilter::~SolutionFilter() {}

std::vector<std::vector<std::vector<int> > > SolutionFilter::decodeSolutions(std::vector<std::vector<int> > v) {
	int i, j;
	
	std::vector<std::vector<std::vector<int> > > decodedV;
	for (std::vector<std::vector<int> >::iterator it = v.begin(); it != v.end(); ++it) {
		std::vector<std::vector<int> > matrix;
		for (i = 0; i < n; ++i) {
			std::vector<int> row;
			for (j = 0; j < n; ++j) {
				row.push_back(0);
			}
			matrix.push_back(row);
		}
		
		for (std::vector<int>::iterator innerIt = (*it).begin(); innerIt != (*it).end(); ++innerIt) {
			matrix[innerIt - (*it).begin()][*innerIt] = 1;
		}
		decodedV.push_back(matrix);
	}
	
	return decodedV;
}

void SolutionFilter::encodeSolutions(void) {
	encodedSolutions.clear();
	for (std::vector<std::vector<std::vector<int> > >::iterator it = decodedSolutions.begin(); it != decodedSolutions.end(); ++it) {
		std::vector<int> encMatrix;
		for (std::vector<std::vector<int> >::iterator vit = (*it).begin(); vit != (*it).end(); ++vit) {
			for (std::vector<int>::iterator eit = (*vit).begin(); eit != (*vit).end(); ++eit) {
				if (*eit != 0) {
					encMatrix.push_back(eit - (*vit).begin());
				}
			}
		}
		encodedSolutions.push_back(encMatrix);
	}
}

std::vector<std::vector<int> > SolutionFilter::mirror(std::vector<std::vector<int> > matrix) {
	std::vector<std::vector<int> > mirror;
	
	for (std::vector<std::vector<int> >::iterator it = matrix.begin(); it != matrix.end(); ++it) {
		std::vector<int> mirrorRow;
		for (std::vector<int>::reverse_iterator rit = (*it).rbegin(); rit != (*it).rend(); ++rit) {
			mirrorRow.push_back(*rit);
		}
		mirror.push_back(mirrorRow);
	}
	return mirror;
}

void SolutionFilter::rotate90(std::vector<std::vector<int> >& matrix) {
	int i, j;
	std::vector<std::vector<int> > rotatedMatrix;
	
	for (i = 0; i < n; ++i) {
		std::vector<int> rotatedRow;
		for (j = 0; j < n; ++j) {
			rotatedRow.push_back(matrix[n - j - 1][i]);
		}
		rotatedMatrix.push_back(rotatedRow);
	}
	
	matrix = rotatedMatrix;
}

std::vector<std::vector<int> > SolutionFilter::rotate(int rotations, std::vector<std::vector<int> > v) {
	int i;
	
	for (i = 0; i < rotations; ++i) {
		rotate90(v);
	}
	
	return v;
}

bool SolutionFilter::isUnique(std::vector<std::vector<int> > v1, std::vector<std::vector<int> > v2) {
	int i;
	for (i = 0; i < 4; ++i) {	
		v2 = rotate(1, v2);
		if (v1 == v2) {
			return false;
		}
	}
	
	v2 = mirror(v2);
	
	for (i = 0; i < 4; i++) {
			v2 = rotate(1, v2);
			if (v1 == v2) {
				return false;
			}
		}
	
	return true;
}

bool SolutionFilter::isIn(int val, std::vector<int> v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		if (val == *it) {
			return true;
		}
	}
	return false;
}

std::string SolutionFilter::printMat(std::vector<std::vector<int> > v) {
	std::string s = "";
	for (std::vector<std::vector<int> >::iterator it = v.begin(); it != v.end(); ++it) {
		s += "<";
		for (std::vector<int>::iterator j = (*it).begin(); j != (*it).end(); ++j) {
			s += std::to_string(*j) + ", ";
		}
		s = s.substr(0, s.length() - 2) + "> \n";
	}
	return s;
}

std::vector<std::vector<int> > SolutionFilter::getUniques(void) {
	std::vector<int> duplicates;
	std::vector<std::vector<std::vector<int> > > uniques;
	
	for (std::vector<std::vector<std::vector<int> > >::iterator i = decodedSolutions.begin(); i != decodedSolutions.end(); ++i) {
		for (std::vector<std::vector<std::vector<int> > >::iterator j = i + 1; j != decodedSolutions.end(); ++j) {
			if (!(isIn(i - decodedSolutions.end(), duplicates)) && (i != j) && !(isUnique(*i, *j))) {
				duplicates.push_back(j - decodedSolutions.begin());
			}
		}
	}
	
	for (std::vector<std::vector<std::vector<int> > >::iterator i = decodedSolutions.begin(); i != decodedSolutions.end(); ++i) {
		if (!isIn(i - decodedSolutions.begin(), duplicates)) {
			uniques.push_back(*i);
		}
	}
	
	decodedSolutions = uniques;
	
	encodeSolutions();
	
	return encodedSolutions;
	
}

class Queens {
	private:
		int n;
		std::string printVector(std::vector<int>);
		std::vector<int> queenPositions;
		std::vector<std::vector<int> > solutions;
		std::string printBoard(std::vector<int>);
		bool inDirection(int, int, int, int);
		bool checkDiagonals(int);
		bool checkCols(int);
		bool solve(int);
		int getQueen(int);
		void setQueen(int, int);
		void removeQueen(int);
		bool checkPosValidity(int);
				
	public:
		Queens(int);
		~Queens();
		void findSolutions(void);
		int numSolutions(void);
		std::string printSolutions(void);
};

Queens::Queens(int len) {
	int i;
	
	n = len;
	
	for (i = 0; i < n; ++i) {
		queenPositions.push_back(-1);
	}
}

Queens::~Queens() {}


std::string Queens::printVector(std::vector<int> v) {
	int i;
	std::string s = "<";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		s += std::to_string(*it) + ", ";
	}
	return s.substr(0, s.length() - 2) + ">";
}


void Queens::findSolutions(void) {
	solve(0);
	SolutionFilter theFilter(solutions);
	solutions = theFilter.getUniques();
}

bool Queens::solve(int q) {
	int i;
	for (i = 0; i < n; ++i) {
		setQueen(q,i);
		if (checkPosValidity(q)) {
			if (q == n - 1) {
				solutions.push_back(queenPositions);
				removeQueen(q);
				return false;
			
			}	
			else if(solve(q + 1)) {
				return true;
			}
		}
	}
	removeQueen(q);
	return false;	
}

int Queens::numSolutions(void) {
	return solutions.size();
}


void Queens::removeQueen(int q) {
	queenPositions[q] = -1;
}

std::string Queens::printSolutions(void) {
	std::string solutionString = "";
	for (std::vector<std::vector<int> >::iterator it = solutions.begin(); it != solutions.end(); ++it) {
		solutionString += printBoard(*it) + '\n';
	}
	return solutionString;
}

std::string Queens::printBoard(std::vector<int> aBoard) {
	int i,j, q;
	
	std::string board = "", topAndBottom((4 * n) + 1, '-');
	
	board += topAndBottom + '\n';
	for (i = 0; i < n; ++i) {
		board += "|";
		q = aBoard[i];
		for (j = 0; j < n; ++j) {
			if (q != j) {
				board += "   |";
			}
			else {
				board += " Q |";
			}
		}
		board += '\n' + topAndBottom + '\n';
	}
	return board;
}		
	 
//std::vector<int> Queens::getQueens(void) {
//	return queenPositions;
//}

int Queens::getQueen(int idx) {
	return queenPositions[idx];
}

void Queens::setQueen(int i, int v) {
	queenPositions[i] = v;
}

bool Queens::checkCols(int q) {
	int currQueenCol = getQueen(q), count = 0;
	for (std::vector<int>::iterator it = queenPositions.begin(); it != queenPositions.end(); ++it) {
		if (currQueenCol == *it) {
			++count;
		}
	}
	return (count == 1);
}

bool Queens::inDirection(int r, int c, int rD, int cD) {
	int i;
	for (i = 1; i < n; ++i) {
		if ((r + (rD * i) >= n) || (r + (rD * i) < 0) || (c + (cD * i) >= n) || (c + (cD * i) < 0)) {
			return false;
		}
		else {
			if (getQueen(r + (rD * i)) != -1 && getQueen(r + (rD * i)) == c + (cD * i )) {
				return true;
			}
		}
	}
	return false;
}

bool Queens::checkDiagonals(int q) {
	//q == index of queen, queenPositions[q] == queen col
	if (!(inDirection(q, getQueen(q), 1, 1))) {
		if (!(inDirection(q, getQueen(q), -1, 1))) {
			if (!(inDirection(q, getQueen(q), 1, -1))) {
				if (!(inDirection(q, getQueen(q), -1, -1))) {
					return true;
				}
			}
		}
	}
	return false;
}
		

bool Queens::checkPosValidity(int q) {
	return (checkCols(q) && checkDiagonals(q));
}

int main(int argc, const char *argv[]) {
	int n;

	std::cout << "How many rows?\n  -->  ";
	std::cin >> n;

	Queens q(n);
	q.findSolutions();
	std::cout << q.printSolutions() << std::endl;
	std::cout << q.numSolutions() << std::endl;
	return 0;
}

