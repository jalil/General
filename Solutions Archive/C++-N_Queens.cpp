#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Queens {
	private:
		int n;
		std::vector<int> queenPositions;
		bool inDirection(int, int, int, int);
		bool checkDiagonals(int);
		bool checkCols(int);
	public:
		Queens(int);
		~Queens();
		bool solve(int);
		std::string printBoard(void);
		bool operator==(Queens);
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
		std::cout << printBoard() << std::endl;
		if (checkPosValidity(q)) {
			if (q == n -1 || solve(q + 1)) {
				return true;
			}
		}
	}
	removeQueen(q);
	return false;	
}

void Queens::removeQueen(int q) {
	if (q >= 0 && q < n) {
		queenPositions[q] = -1;
	}
}


std::string Queens::printBoard(void) {
	int i,j, q;
	
	std::string board = "", topAndBottom((4 * n) + 1, '-');
	
	board += topAndBottom + '\n';
	for (i = 0; i < n; ++i) {
		board += "|";
		q = getQueen(i);
		for (j = 0; j < n; ++j) {
			if (q != j) {
				board += "   |";
			}
			else {
				board += " Q |";
			}
		}
		board += '\n';
	}
	return board + topAndBottom;
}		
	 

bool Queens::operator==(Queens otherSolution) {
	return (queenPositions == otherSolution.getQueens());
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
	std::cout << "cols = " << checkCols(q) << " and diags = " << checkDiagonals(q) << std::endl;
	return (checkCols(q) && checkDiagonals(q));
}

int main(int argc, const char *argv[]) {
	Queens q(8);
	q.solve(0);
	std::cout << q.printBoard() << std::endl;
	return 0;
}

