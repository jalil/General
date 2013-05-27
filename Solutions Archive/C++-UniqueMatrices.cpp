#include <iostream>
#include <string>
#include <vector>

class Matrix {
	private:
		int n;
		std::vector<std::vector<int> > matrix;
		void rotate90(void);
	public:
		Matrix(std::vector<std::vector<int> >);
		~Matrix();
		std::vector<std::vector<int> > getVectors(void);
		bool operator==(Matrix);

		std::string printMatrix(void);
		void mirror(void);
		bool isUnique(Matrix);
		void rotate(int);
};

Matrix::Matrix(std::vector<std::vector<int> > v) {
	matrix = v;
	n = matrix.size();
}

Matrix::~Matrix() {}

std::vector<std::vector<int> > Matrix::getVectors(void) {
	return matrix;
}

bool Matrix::operator==(Matrix otherMatrix) {
	return (matrix == otherMatrix.getVectors());
}	

std::string Matrix::printMatrix(void) {
	std::string mat = "";
	for (std::vector<std::vector<int> >::iterator it = matrix.begin(); it != matrix.end(); ++it) {
		mat += "<";
		for (std::vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit) {
			mat += std::to_string(*vit) + ", ";
		}
		mat = mat.substr(0, mat.length() - 2) + "> \n";
	}
	return mat;
}

void Matrix::mirror(void) {
	int i,j;
	std::vector<std::vector<int> > mirrorV;
	for (std::vector<std::vector<int> >::iterator it = matrix.begin(); it != matrix.end(); ++it) {
		std::vector<int> mirrorRow;
		for (std::vector<int>::reverse_iterator rit = (*it).rbegin(); rit != (*it).rend(); ++rit) {
			mirrorRow.push_back(*rit);
		}
		mirrorV.push_back(mirrorRow);
	}
	matrix = mirrorV;
}

void Matrix::rotate90(void) {
	int i,j;
	std::vector<std::vector<int> > rotV;

	for (i = 0; i < n; ++i) {
		std::vector<int> rowRot;
		for (j = 0; j < n; ++j) {
			rowRot.push_back(matrix[n - j - 1][i]);
		}
		rotV.push_back(rowRot);
	}
	matrix = rotV;
}

void Matrix::rotate(int r) {
	int i, numRotations = r % 4;
	
	if (numRotations < 0) {
		numRotations = 4 + numRotations;
	}
	
	for (i = 0; i < numRotations; ++i) {
		rotate90();
	}
}		

bool Matrix::isUnique(Matrix otherMatrix) {
	int i;
	//check if equal
	if (matrix == otherMatrix.getVectors()) {
		return false;
	}	
	//check if matrix 2 is a simple rotation of the first matrix
	for (i = 0; i < 4; ++i) {
		otherMatrix.rotate(1);
		if (matrix == otherMatrix.getVectors()) {
			return false;
		}
	}
	//mirror matrix 2 and re-check for rotational differences
	otherMatrix.mirror();

	for (i = 0; i < 4; ++i) {
		otherMatrix.rotate(1);
		if (matrix == otherMatrix.getVectors()) {
			return false;
		}
	}

	return true;
}	

std::vector<std::vector<int> > initMatrix(void) {
	int i,j,k,n;
	
	std::vector<std::vector<int> > matrix;

	std::cout << "What will the dimensions of you NxN matrix be?\n  N = ";
	std::cin >> n;

	for (i = 0; i < n; ++i) {
		std::vector<int> row;
		for (j = 0; j < n; ++j) {
			std::cout << "\nELEMENT IN ROW " << i  << " AND COL " << j << ":" << std::endl;
			std::cout << "What is the value at this coordinate?\n  -->  ";
			std::cin >> k;
			
			row.push_back(k);
		}
		matrix.push_back(row);
	}
	
	return matrix;
}

int main(int argc, const char *argv[]) {
	bool areUnique;
	int i,j, rotations;
	std::vector<std::vector<int> > v1, v2;

	for (i = 0; i < 7; ++i) {
		std::vector<int> innerV;
		for (j = 0; j < 7; ++j) {
			innerV.push_back(0);
		}
		v1.push_back(innerV);
		v2.push_back(innerV);
	}

	//init v1
	v1[0][1] = 1;
	v1[1][3] = 1;
	v1[2][0] = 1;
	v1[3][6] = 1;
	v1[4][4] = 1;
	v1[5][2] = 1;
	v1[6][5] = 1;

	//init v2
	v2[0][1] = 1;
	v2[1][4] = 1;
	v2[2][2] = 1;
	v2[3][0] = 1;
	v2[4][6] = 1;
	v2[5][3] = 1;
	v2[6][5] = 1;

	Matrix matrix1(v1), matrix2(v2);
	
	std::cout << "\nYOUR INITIALIZED MATRICES ARE:\n" << "\nMATRIX ONE:\n" << matrix2.printMatrix() << "\nMATRIX TWO:\n" << matrix2.printMatrix() <<  std::endl;

	areUnique = matrix1.isUnique(matrix2);
	if (areUnique) {
		std::cout << "\nMatrix 1 and Matrix 2 are unique matrices." << std::endl;
	}
	else {
		std::cout << "\nMatrix 1 and Matrix 2 are distinct matrices." << std::endl;
	}
	return 0;
}

