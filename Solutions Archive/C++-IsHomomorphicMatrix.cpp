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
		int isHomomorphism(Matrix);
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

int Matrix::isHomomorphism(Matrix otherMatrix) {
	int i;
	for (i = 0; i < 4; ++i) {
		otherMatrix.rotate(1);
		if (matrix == otherMatrix.getVectors()) {
			return i;
		}
	}
	return -1;
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
	v1[0][2] = 1;
	v1[1][6] = 1;
	v1[2][3] = 1;
	v1[3][0] = 1;
	v1[4][4] = 1;
	v1[5][1] = 1;
	v1[6][5] = 1;

	//init v2
	v2[0][3] = 1;
	v2[1][1] = 1;
	v2[2][6] = 1;
	v2[3][4] = 1;
	v2[4][2] = 1;
	v2[5][0] = 1;
	v2[6][5] = 1;

	Matrix matrix1(v1), matrix2(v2);
	
	std::cout << "\nYOUR INITIALIZED MATRICES ARE:\n" << "\nMATRIX ONE:\n" << matrix2.printMatrix() << "\nMATRIX TWO:\n" << matrix2.printMatrix() <<  std::endl;

	i = matrix1.isHomomorphism(matrix2);
	if (i == -1) {
		std::cout << "\nMatrix 1 and Matrix 2 are not homomorphic." << std::endl;
	}
	else {
		std::cout << "\nMatrix 1 and Matrix 2 are homomorphic as can be seen when you rotate Matrix 2 by 90-degrees " << i << " times." << std::endl;
	}
	return 0;
}

