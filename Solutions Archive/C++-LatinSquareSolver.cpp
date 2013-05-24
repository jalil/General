#include <iostream>
#include <vector>
#include <string>
#include <utility>

class LatinSquare {
	private:
		std::vector<std::vector<int> > square;
	public:
		LatinSquare(std::vector<std::vector<int> >);
		~LatinSquare();
		std::string printPuzzle(void);
		int getPosition(int, int);
		void setPosition(int, int, int);
		bool checkPosValidity(int, int);
		bool checkCol(int, int);
		bool checkRow(int, int);
		std::pair<int, int> getNextPos(int, int);
		bool solve(int, int);
};

std::string LatinSquare::printPuzzle(void) {
	std::string puzzle, topAndBottom(37, '-');
	puzzle += topAndBottom + '\n';
	for (std::vector<std::vector<int> >::iterator it = square.begin(); it != square.end(); ++it) {
		std::string s = "|";
		for (std::vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit) {
			s += ' ' + std::to_string(*vit) + " |";
		}
		puzzle += s + '\n';
	}
	return puzzle + topAndBottom;
}

LatinSquare::LatinSquare(std::vector<std::vector<int> > vvi) {
	square = vvi;
}

LatinSquare::~LatinSquare(){}
	int LatinSquare::getPosition(int r, int c) {
	if ((r > 8 || r < 0) || (c > 8 || c < 0)) {
		return -1;
	}
	else {
		return square[r][c];
	}
}

void LatinSquare::setPosition(int r, int c, int v) {
	square[r][c] = v;
}

bool LatinSquare::checkCol(int c, int v) {
	int i, count = 0;
	for (i = 0; i < 9; ++i) {
		if (square[i][c] == v) {
			++count;
		}
	}
	return (count == 1);
}

bool LatinSquare::checkRow(int r, int v) {
	int j, count = 0;
	for (j = 0; j < 9; ++j) {
		if (square[r][j] == v) {
			++count;
		}
	}

	return (count == 1);
}

bool LatinSquare::checkPosValidity(int r, int c) {
	int v = square[r][c];
	return (checkCol(c, v) && checkRow(r, v));
}

std::pair<int,int> LatinSquare::getNextPos(int r, int c) {
	int newRow, newCol;
	if (r == 8 && c == 8) {
		newRow = newCol = 0;
	}
	else if (c == 8) {
		newRow = r + 1;
		newCol = 0;
	}
	else {
		newRow = r;
		newCol = c + 1;
	}

	return std::make_pair(newRow,newCol);
}

bool LatinSquare::solve(int r, int c) {
	int i;
	std::pair<int,int> p = getNextPos(r,c);
	if (getPosition(r,c) != 0) {
		return (solve(std::get<0>(p), std::get<1>(p)));
	}
	else {
		for (i = 1; i < 10; ++i) {
			setPosition(r,c,i);
			if (checkPosValidity(r,c)) {
				if (r == 8 && c == 8 || solve(std::get<0>(p), std::get<1>(p))) {
					return true;
				}
			}
		}
		setPosition(r,c,0);
		return false;
	}
}	

std::vector<std::vector<int> > initSquare(void) {
	int i,j;
	std::vector<std::vector<int> > v;
	for (i = 0; i < 9; ++i) {
		std::vector<int> vPrime;
		for (j = 0; j < 9; ++j) {
			vPrime.push_back(0);
		}
		v.push_back(vPrime);
	}
	return v;
}

int main(int argc, const char *argv[]) {
	int i, j, r, c, v;
	LatinSquare puzzle(initSquare());

	std::cout << "How many values would you like to add to the puzzle?\n --> ";
	std::cin >> j;

	for (i = 0; i < j; ++i) {
		std::cout << "\nBe careful. You are now adding element " << i << " to the puzzle" << std::endl;

		std::cout << "Give me the row value: ";
		std::cin >> r;

		std::cout << "Give me the column value: ";
		std::cin >> c;

		std::cout << "Give me the numeric value for that cell: ";
		std::cin >> v;

		puzzle.setPosition(r,c,v);
	}

	std::cout << "Your initialized puzzle:" << std::endl;

	std::cout << puzzle.printPuzzle() << std::endl;

	std::cout << "\nOur solved puzzle:" << std::endl;	

	puzzle.solve(0,0);
	std::cout << puzzle.printPuzzle() << std::endl;	

return 0;
}
