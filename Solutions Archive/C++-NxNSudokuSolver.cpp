#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Sudoku {
	private:
		int n;
		std::vector<std::vector<int> > square;
		int numDigits(int);
		std::string printCell(int, int);
		bool checkCol(int, int);
		bool checkRow(int, int);
		std::pair<int, int> getNextPos(int, int);
	public:
		Sudoku(std::vector<std::vector<int> >);
		~Sudoku();
		std::string printPuzzle(void);
		int getPosition(int, int);
		void setPosition(int, int, int);
		void initConstants(void);
		bool checkPosValidity(int, int);
		bool solve(int, int);
};

int Sudoku::numDigits(int num) {
	int d = 0;

	while (num != 0) {
		num /= 10;
		++d;
	}
	return d;
}

std::string Sudoku::printCell(int h, int c) {
	int i, lenDelta;
	std::string s = " ";

	lenDelta = numDigits(h) - numDigits(c);

	for (i = 0; i < lenDelta; ++i) {
		s += ' ';
	}
	
	if (c != 0) {
		s += std::to_string(c) + " |";
	}
	else {
		s += " |";
	}

	return s;
}

std::string Sudoku::printPuzzle(void) {
	std::string puzzle, topAndBottom(((numDigits(n) + 3)* square.size()) + 1, '-');
	puzzle += topAndBottom + '\n';
	for (std::vector<std::vector<int> >::iterator it = square.begin(); it != square.end(); ++it) {
		std::string s = "|";
		for (std::vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit) {
			s += printCell(n, *vit);
		}
		puzzle += s + '\n';
	}

	return puzzle + topAndBottom;
}

Sudoku::Sudoku(std::vector<std::vector<int> > vvi) {
	n = vvi.size();
	square = vvi;
}

Sudoku::~Sudoku(){}

int Sudoku::getPosition(int r, int c) {
	if ((r > n - 1 || r < 0) || (c > n - 1 || c < 0)) {
		return -1;
	}
	else {
		return square[r][c];
	}
}

void Sudoku::setPosition(int r, int c, int v) {
	if (!((r > n - 1 || r < 0) || (c > n - 1 || c < 0))) {
		square[r][c] = v;
	}
}

void Sudoku::initConstants(void) {
	int r,c,i,j,v;

	std::cout << "\nDIRECTIONS:\n 1: The grid position (0,0) is the upper left corner\n 2: Row, columnar, and cell values must be between 0 and N where N is the row length\n" << std::endl;
	std::cout << "How many constant values would you like to add?\n  -->  ";
	std::cin >> j;
	
	for (i = 0; i < j; ++i) {
		std::cout << "CONSTANT ELEMENT " << i + 1 << ":\nGive me the row value: ";
		std::cin >> r;

		std::cout << "Give me the column value: ";
		std::cin >> c;

		std::cout << "Give me the cell value: ";
		std::cin >> v;

		setPosition(r,c,v);
	}
}

bool Sudoku::checkCol(int c, int v) {
	int i, count = 0;
	
	for (i = 0; i < n; ++i) {
		if (square[i][c] == v) {
			++count;
		}
	}

	return (count == 1);
}

bool Sudoku::checkRow(int r, int v) {
	int j, count = 0;
	
	for (j = 0; j < n; ++j) {
		if (square[r][j] == v) {
			++count;
		}
	}

	return (count == 1);
}

bool Sudoku::checkPosValidity(int r, int c) {
	int v = square[r][c];
	return (checkCol(c, v) && checkRow(r, v));
}

std::pair<int,int> Sudoku::getNextPos(int r, int c) {
	int newRow, newCol;
	if (r == n - 1 && c == n - 1) {
		newRow = newCol = 0;
	}
	else if (c == n - 1) {
		newRow = r + 1;
		newCol = 0;
	}
	else {
		newRow = r;
		newCol = c + 1;
	}

	return std::make_pair(newRow,newCol);
}

bool Sudoku::solve(int r, int c) {
	int i;
	std::pair<int,int> p = getNextPos(r,c);
	if (getPosition(r,c) != 0) {
		return (solve(std::get<0>(p), std::get<1>(p)));
	
	}
	else {
		for (i = 1; i < n + 1; ++i) {
			setPosition(r,c,i);
			if (checkPosValidity(r,c)) {
				if (r == n - 1 && c == n - 1 || solve(std::get<0>(p), std::get<1>(p))) {
					return true;
				}
				
			}
		}
		setPosition(r,c,0);
		return false;
	}
}	

std::vector<std::vector<int> > initSquare(int n) {
	int i,j;
	std::vector<std::vector<int> > v;
	for (i = 0; i < n; ++i) {
		std::vector<int> vPrime;
		for (j = 0; j < n; ++j) {
			vPrime.push_back(0);
		}
		v.push_back(vPrime);
	}
	return v;
}

int main(int argc, const char *argv[]) {
	int n;
	
	while (true) {
		std::cout << "What are the dimensions of the NxN square?\n  N = ";
		std::cin >> n;
		
		if (n < 2) {
			std::cout << "The minimum grid has an N value of 2" << std::endl;
		}
		else {
			break;
		}
	}

	Sudoku puzzle(initSquare(n));
	puzzle.initConstants();	

	std::cout << "\nYour initialized puzzle:" << std::endl;

	std::cout << puzzle.printPuzzle() << std::endl;

	std::cout << "\nYour solved puzzle:" << std::endl;	
	
	puzzle.solve(0,0);

	std::cout << puzzle.printPuzzle() << std::endl;	
	
	return 0;
}


