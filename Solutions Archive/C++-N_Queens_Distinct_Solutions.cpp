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


void Queens::findSolutions(void) {
	solve(0);	
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

	std::cout << "What would you like the dimensions of your NxN chessboard to be?\n  N = ";
	std::cin >> n;

	Queens q(n);
	q.findSolutions();
	std::cout << q.printSolutions() << std::endl;
	std::cout << "The total number of distinct solutions is " << q.numSolutions() << " with a " << n << "x" << n << " grid." << std::endl;
	return 0;
}

