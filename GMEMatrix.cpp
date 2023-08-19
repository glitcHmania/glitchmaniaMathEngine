#include "GMEMatrix.h"
#include <iostream>
#include <vector>
#include <assert.h>

//I implemented this matrix as a column-major. I may change this to row-major matrix if I need it for Direct3D.
	//    0    3    6
	//    1    4    7
	//    2    5    8

GMEngine::GMEMatrix::GMEMatrix()
	:
	rows(3),
	cols(3)
{
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
	dataPtr = new float[nElements];

	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] = dataContainer[i];
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
	std::vector<float> container;
	for (int i = 0; i < nElements; i++)
	{
		container.emplace_back(dataPtr[i] + mat.dataPtr[i]);
	}

	return GMEMatrix(rows,cols,container);
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
	std::vector<float> container;
	for (int i = 0; i < nElements; i++)
	{
		container.emplace_back(dataPtr[i] - mat.dataPtr[i]);
	}

	return GMEMatrix(rows, cols, container);
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
	std::vector<float> container;
	for (int i = 0; i < nElements; i++)
	{
		container.emplace_back(dataPtr[i] * n);
	}

	return GMEMatrix(rows, cols, container);
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

void GMEngine::GMEMatrix::show() const
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

void GMEngine::GMEMatrix::makeIdentity()
{
	assert(rows == cols);
	for (int i = 0; i < nElements; i++)
	{
		if (i % (rows + 1) == 0)
			dataPtr[i] = 1;
		else
			dataPtr[i] = 0;
	}
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::getIdentity() const
{
	assert(rows == cols);
	std::vector<float> container(nElements,0);
	for (int i = 0; i < nElements; i += (rows + 1))
	{
		container[i] = 1;
	}
	return GMEMatrix(rows,cols,container);
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::getTranspose() const
{
	GMEMatrix transpose(cols, rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			transpose.dataPtr[i * cols + j] = dataPtr[j * rows + i];
		}
	}
	return transpose;
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::getMinorMatrix( int selectedRow, int selectedCol ) const
{
	std::vector<float> container;
	if (rows > 1 && cols > 1)
	{
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				if( i!= selectedCol && j != selectedRow )
					container.emplace_back(dataPtr[i * cols + j]);
			}
		}
	}
	return GMEMatrix(rows - 1, cols - 1, container);
}

float GMEngine::GMEMatrix::getDeterminant() const
{
	assert(rows == cols);
	if (rows == 1)
	{
		return dataPtr[0];
	}
	else
	{
		float det = 0.0f;
		for (int i = 0; i < cols; i++)
		{
			auto subMatrix = getMinorMatrix(0, i);
			if (i % 2 == 0)
				det += dataPtr[i * rows] * subMatrix.getDeterminant();
			else
				det -= dataPtr[i * rows] * subMatrix.getDeterminant();
		}
		return det;
	}
}

float GMEngine::GMEMatrix::getCofactor(int selectedRow, int selectedCol) const
{
	if((selectedRow + selectedCol) % 2 == 0)
		return getMinorMatrix(selectedRow, selectedCol).getDeterminant() ;
	else
		return -getMinorMatrix(selectedRow, selectedCol).getDeterminant();
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::getCofactorMatrix() const
{
	std::vector<float> container(nElements);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			container[i * rows + j] = getCofactor(j, i);
		}
	}
	return GMEMatrix(rows, cols, container);
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::getAdjointMatrix() const
{
	return getCofactorMatrix().getTranspose();
}

GMEngine::GMEMatrix GMEngine::GMEMatrix::getInverse() const
{
	float det = getDeterminant();
	if (det != 0)
	{
		float detInv = 1.0f / det;
		return  getAdjointMatrix() * detInv;
	}
	else
		return *this;
}