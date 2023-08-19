#pragma once
#include <vector>

//I implemented this matrix as a column-major. I may change this to row-major matrix if I need it for Direct3D.
	//    0    3    6
	//    1    4    7
	//    2    5    8

namespace GMEngine {
	class GMEMatrix
	{
	public:
		//Constructor
		GMEMatrix();
		GMEMatrix(int in_rows, int in_cols);
		GMEMatrix(int in_rows, int in_cols, std::vector<float> dataContainer);

		//Copy Constructor
		GMEMatrix& operator=(const GMEMatrix& mat);

		//Destructor
		~GMEMatrix();

		//Functions
			//Addition
		GMEMatrix& operator+=(const GMEMatrix& mat);
		GMEMatrix operator+(const GMEMatrix& mat) const;
			//Subtraction
		GMEMatrix& operator-=(const GMEMatrix& mat);
		GMEMatrix operator-(const GMEMatrix& mat) const;
			//Scalar Multiplication
		GMEMatrix& operator*=(const float n);
		GMEMatrix operator*(const float n) const;
			//Multiplication
		GMEMatrix operator*(const GMEMatrix& mat) const;
			//Misc
		void show() const;
		void makeIdentity();
		float getDeterminant() const;
		float getCofactor(int selectedRow, int selectedCol) const;
		GMEMatrix getIdentity() const;
		GMEMatrix getTranspose() const;
		GMEMatrix getMinorMatrix(int selectedRow, int selectedCol) const;
		GMEMatrix getCofactorMatrix() const;
		GMEMatrix getAdjointMatrix() const;
		GMEMatrix getInverse() const;

		const int rows;
		const int cols;
		int nElements = rows * cols;
		float* dataPtr;
	};
}