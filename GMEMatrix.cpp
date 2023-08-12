#include "GMEMatrix.h"
#include <iostream>
#include <vector>
#include <assert.h>

GMEngine::GMEMatrix::GMEMatrix()
	:
	rows(3),
	cols(3)
{
	//I implemented this matrix as a column-major. I may change this to row-major matrix if I need it for Direct3D.
	//    0    3    6
	//    1    4    7
	//    2    5    8
	dataPtr = new float[nElements];

	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] = 0;
	}
}

GMEngine::GMEMatrix::GMEMatrix(int in_rows, int in_cols)
	:
	rows(in_rows),
	cols(in_cols)
{
	dataPtr = new float[nElements];
	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] = 0;
	}
}

GMEngine::GMEMatrix::GMEMatrix(int in_rows, int in_cols, std::vector<float> dataContainer)
	:
	rows(in_rows),
	cols(in_cols)
{
	dataPtr = new float[rows * cols];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			dataPtr[j * rows + i] = dataContainer[j * rows + i];
		}
	}
}

GMEngine::GMEMatrix& GMEngine::GMEMatrix::operator=(const GMEMatrix& mat)
{
	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] = mat.dataPtr[i];
	}
	return *this;
}

GMEngine::GMEMatrix::~GMEMatrix()
{
	delete[] dataPtr;
	dataPtr = nullptr;
}

GMEngine::GMEMatrix& GMEngine::GMEMatrix::operator+=(const GMEMatrix& mat)
{
	assert(rows == mat.rows && cols == mat.cols);
	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] += mat.dataPtr[i];
	}
	return *this;
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::operator+(const GMEMatrix& mat) const
{
	assert(rows == mat.rows && cols == mat.cols);
	GMEMatrix newMatrix;
	for (int i = 0; i < nElements; i++)
	{
		newMatrix.dataPtr[i] += mat.dataPtr[i];
	}

	return newMatrix;
}

GMEngine::GMEMatrix& GMEngine::GMEMatrix::operator-=(const GMEMatrix& mat)
{
	assert(rows == mat.rows && cols == mat.cols);
	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] -= mat.dataPtr[i];
	}
	return *this;
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::operator-(const GMEMatrix& mat) const
{
	assert(rows == mat.rows && cols == mat.cols);
	GMEMatrix newMatrix;
	for (int i = 0; i < nElements; i++)
	{
		newMatrix.dataPtr[i] -= mat.dataPtr[i];
	}
	return newMatrix;
}

GMEngine::GMEMatrix& GMEngine::GMEMatrix::operator*=(float n)
{
	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] *= n;
	}
	return *this;
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::operator*(float n) const
{
	GMEMatrix newMatrix = *this;
	for (int i = 0; i < nElements; i++)
	{
		newMatrix.dataPtr[i] *= n;
	}
	return newMatrix;
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::operator*(const GMEMatrix& mat) const
{
	assert(rows == mat.cols);
	std::vector<float> container(rows * mat.cols, 0);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
		{
			for (int k = 0; k < cols; k++)
				container[j * rows + i] += dataPtr[i + k * rows] * mat.dataPtr[j * mat.rows + k];
		}
	}

	return GMEMatrix(rows, mat.cols, container);
}

void GMEngine::GMEMatrix::show()
{
	std::cout << "[";
	for (int i = 0; i < rows; i++)
	{
		if (i != 0)
			std::cout << " ";
		for (int j = 0; j < cols; j++)
		{
			std::cout << dataPtr[j * rows + i];
			if (j != cols - 1)
				std::cout << ",";
		}
		if (i != rows - 1)
			std::cout << std::endl;
	}
	std::cout << "]" << std::endl;
}
