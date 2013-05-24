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
		std::string printMatrix(void);
		void rotate(int);
};

Matrix::Matrix(std::vector<std::vector<int> > v) {
	matrix = v;
	n = matrix.size();
}

Matrix::~Matrix() {}

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
	

std::vector<std::vector<int> > initMatrix(void) {
	int i,j,k,n;
	
	std::vector<std::vector<int> > matrix;

	std::cout << "What are the dimensions of the matrix?\n  -->  ";
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
	int rotations;
	Matrix myMatrix(initMatrix());
	
	std::cout << "\nYOUR INITIALIZED MATRIX IS:\n" << myMatrix.printMatrix() << std::endl;
	
	std::cout << "\nHow many 90 degree rotations would you like done?\n  -->  ";
	std::cin >> rotations;

	myMatrix.rotate(rotations);
	std::cout << "\nYOUR MATRIX AFTER " << rotations << " 90 DEGREE ROTATIONS IS:\n" << myMatrix.printMatrix() << std::endl;

	return 0;
}

