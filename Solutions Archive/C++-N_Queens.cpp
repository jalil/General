#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Queens {
	private:
		int n;
		std::vector<int> queenPositions;
		bool checkDiagonal(int);
		bool checkRows(int);
		bool checkCols(int);
	public:
		Queens(int);
		~Queens();
		void solve(q);
		std::string printBoard(void);
		bool operator==(Queens);
		std::vector<int> getQueens(void);
		int getQueen(int);
		void setQueen(int, int);
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

void Queens::solve(int q) {
	

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

bool Queens::checkPosValidity(int q) {
	return true;
}

int main(int argc, const char *argv[]) {
	Queens q(8);
	q.setQueen(0,1);
	q.setQueen(1,2);
	std::cout << q.printBoard() << std::endl;
	return 0;
}

