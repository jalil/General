#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


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
		bool isHomomorphism(std::vector<int> v1, std::vector<int> v2);
		bool isIn(int, std::vector<int>);
		void rotate90(std::vector<int>&);
		std::vector<int> rotate(int, std::vector<int>);
		
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

void Queens::rotate90(std::vector<int>& v) {
	int i, j;
	std::vector<std::vector<int> > matrix, rotatedMatrix;
	//init matrix
	for (i = 0; i < n; ++i) {
		std::vector<int> row;
		for (j = 0; j < n; ++j) {
			row.push_back(0);
		}
		matrix.push_back(row);
	}
	
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		matrix[it - v.begin()][*it] = 1;
	}
	
	//init rotatedMatrix
	
	for (i = 0; i < n; ++i) {
		std::vector<int> rotatedRow;
		for (j = 0; j < n; ++j) {
			rotatedRow.push_back(matrix[n - j - 1][i]);
		}
		rotatedMatrix.push_back(rotatedRow);
	}
	
	//re-encode matrix to 1D vector
	v.clear();
	for (std::vector<std::vector<int> >::iterator it = rotatedMatrix.begin(); it != rotatedMatrix.end(); ++it) {
		for (std::vector<int>::iterator innerIt = (*it).begin(); innerIt != (*it).end(); ++innerIt) {
			if (*innerIt != 0) {
				v.push_back(innerIt - (*it).begin());
			}
		}
	}
}

std::string Queens::printVector(std::vector<int> v) {
	int i;
	std::string s = "<";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		s += std::to_string(*it) + ", ";
	}
	return s.substr(0, s.length() - 2) + ">";
}

std::vector<int> Queens::rotate(int rotations, std::vector<int> v) {
	int i;
	
	for (i = 0; i < rotations; ++i) {
		rotate90(v);
	}
	
	return v;
}

bool Queens::isIn(int val, std::vector<int> v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		if (val == *it) {
			return true;
		}
	}
	return false;
}

bool Queens::isHomomorphism(std::vector<int> v1, std::vector<int> v2) {
	int i;
	for (i = 0; i < 4; ++i) {
		
		v2 = rotate(i, v2);
		if (v1 == v2) {
			std::cout << printVector(v1) << " equals " << printVector(v2) << std::endl;
			return true;
		}
	}
	return false;
}

void Queens::findSolutions(void) {
	int i;
	bool alreadyPresent;
	std::vector<int> homomorphisms;
	std::vector<std::vector<int> > uniqueSolutions;
	
	solve(0);
	/*
	for (std::vector<std::vector<int> >::iterator it = solutions.begin(); it != solutions.end(); ++it) {
		for (std::vector<std::vector<int> >::iterator innerIt = it; innerIt != solutions.end(); ++innerIt) {
			if ((!isIn(it - solutions.begin(), homomorphisms)) && (*it != *innerIt) && (isHomomorphism(*it, *innerIt))) {
				homomorphisms.push_back(innerIt - solutions.begin());
			}
		}
	}
	
	std::cout << "Here are the homos sir " << printVector(homomorphisms) << std::endl;
	
	//for (std::vector<int>::iterator it = homomorphisms.begin(); it != homomorphisms.end(); ++it) {
	//	std::cout << "a homo is " << *it << std::endl;
	//}
	
	//std::cout << "fuck a duckK" << std::endl;
	for (std::vector<std::vector<int> >::iterator it = solutions.begin(); it != solutions.end(); ++it) {
		//std::cout << it - solutions.begin() << std::endl;
		if (!isIn(it - solutions.begin(), homomorphisms)) {
			uniqueSolutions.push_back(*it);
		}
	}
	solutions = uniqueSolutions;*/
	
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
		else {
			std::cout << printBoard(queenPositions) << std::endl;
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
	//q.solve(0);
	q.findSolutions();
	std::cout << q.printSolutions() << std::endl;
	std::cout << q.numSolutions() << std::endl;
	return 0;
}

