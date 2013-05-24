#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Queens {
	private:
		int n;
		std::vector<int> queenPositions;
		std::vector<std::vector<int> > solutions;
		bool isUniqueSolution();
		bool inDirection(int, int, int, int);
		bool checkDiagonals(int);
		bool checkCols(int);
	public:
		Queens(int);
		~Queens();
		bool solve(int);
		std::string printSolutions(void);
		std::string printBoard(std::vector<int>);
		std::vector<int> getQueens(void);
		int getQueen(int);
		void setQueen(int, int);
		void removeQueen(int);
		bool checkPosValidity(int);
};

Queens::Queens(int numQueens) {
	int i;
	n = numQueens;
	for (i = 0; i < numQueens; ++i) {
		queenPositions.push_back(-1);
	}
}

Queens::~Queens() {}

bool Queens::solve(int q) {
	int i;
	for (i = 0; i < n; ++i) {
		setQueen(q, i);
		if (checkPosValidity(q)) {
			if (q == n - 1) {
				if (isUniqueSolution()) {
					solutions.push_back(queenPositions);
					return false;
				}
			}	
			else if(solve(q + 1)) {
				return true;
			}
		}
	}
	removeQueen(q);
	return false;	
}

bool Queens::isUniqueSolution() {
	for (std::vector<std::vector<int> >::iterator it = solutions.begin(); it != solutions.end(); ++it) {
		if (queenPositions == *it) {
			return false;
		}
	}	
	return true;
}

void Queens::removeQueen(int q) {
	if (q >= 0 && q < n) {
		queenPositions[q] = -1;
	}
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
	 
std::vector<int> Queens::getQueens(void) {
	return queenPositions;
}

int Queens::getQueen(int idx) {
	return (!(idx >= queenPositions.size())) ? queenPositions[idx] : -1;
}

void Queens::setQueen(int i, int v) {
	if (!(i > queenPositions.size())) {
		queenPositions[i] = v;
	}
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
		if ((r + (rD * i) > n) || (r + (rD * i) < 0) || (c + (cD * i) > n) || (c + (cD * i) < 0)) {
			return false;
		}
		else {
			if (getQueen(r + (rD * i)) == c + (cD * i )) {
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
	Queens q(7);
	q.solve(0);
	std::cout << q.printSolutions() << std::endl;
	return 0;
}

