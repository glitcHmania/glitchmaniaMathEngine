#pragma once
#include <vector>

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

		void show();

		const int rows;
		const int cols;
		int nElements = rows * cols;
		float* dataPtr;
	};
}