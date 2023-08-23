#pragma once
#include <vector>
#include "GMVector.h"

//I implemented this matrix as a column-major. I may change this to row-major matrix if I need it for Direct3D.
	//    0    3    6
	//    1    4    7
	//    2    5    8

namespace GMEngine
{
	class GMMatrix
	{
	public:
		//Constructors
		GMMatrix();
		GMMatrix(int in_rows, int in_cols);
		GMMatrix(int in_rows, int in_cols, std::vector<float> dataContainer);

		//Copy Constructor
		GMMatrix& operator=(const GMMatrix& mat);

		//Destructor
		~GMMatrix();

		//Functions
			//Addition
		GMMatrix& operator+=(const GMMatrix& mat);
		GMMatrix operator+(const GMMatrix& mat) const;
			//Subtraction
		GMMatrix& operator-=(const GMMatrix& mat);
		GMMatrix operator-(const GMMatrix& mat) const;
			//Scalar Multiplication
		GMMatrix& operator*=(const float n);
		GMMatrix operator*(const float n) const;
			//Vector Multiplication
		GMVector operator*(const GMVector vec);
			//Multiplication
		GMMatrix operator*(const GMMatrix& mat) const;
			//Misc
		void show() const;
		void makeIdentity();
		float getDeterminant() const;
		float getCofactor(int selectedRow, int selectedCol) const;
		GMMatrix getIdentity() const;
		GMMatrix getTranspose() const;
		GMMatrix getMinorMatrix(int selectedRow, int selectedCol) const;
		GMMatrix getCofactorMatrix() const;
		GMMatrix getAdjointMatrix() const;
		GMMatrix getInverse() const;

		//Elements
		const int rows;
		const int cols;
		int nElements = rows * cols;
		float* dataPtr;
	};
}