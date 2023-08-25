#include "GMMatrix.h"
#include <iostream>
#include <vector>
#include <assert.h>

//I implemented this matrix as a column-major. I may change this to row-major matrix if I need it for Direct3D.
	//    0    3    6
	//    1    4    7
	//    2    5    8

GMEngine::GMMatrix::GMMatrix()
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

GMEngine::GMMatrix::GMMatrix(int in_rows, int in_cols)
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

GMEngine::GMMatrix::GMMatrix(int in_rows, int in_cols, std::vector<float> dataContainer)
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

GMEngine::GMMatrix& GMEngine::GMMatrix::operator=(const GMMatrix& mat)
{
	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] = mat.dataPtr[i];
	}
	return *this;
}

GMEngine::GMMatrix::~GMMatrix()
{
	delete[] dataPtr;
}

GMEngine::GMMatrix& GMEngine::GMMatrix::operator+=(const GMMatrix& mat)
{
	assert(rows == mat.rows && cols == mat.cols);
	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] += mat.dataPtr[i];
	}
	return *this;
}

GMEngine::GMMatrix GMEngine::GMMatrix::operator+(const GMMatrix& mat) const
{
	assert(rows == mat.rows && cols == mat.cols);
	std::vector<float> container;
	for (int i = 0; i < nElements; i++)
	{
		container.emplace_back(dataPtr[i] + mat.dataPtr[i]);
	}

	return GMMatrix(rows,cols,container);
}

GMEngine::GMMatrix& GMEngine::GMMatrix::operator-=(const GMMatrix& mat)
{
	assert(rows == mat.rows && cols == mat.cols);
	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] -= mat.dataPtr[i];
	}
	return *this;
}

GMEngine::GMMatrix GMEngine::GMMatrix::operator-(const GMMatrix& mat) const
{
	assert(rows == mat.rows && cols == mat.cols);
	std::vector<float> container;
	for (int i = 0; i < nElements; i++)
	{
		container.emplace_back(dataPtr[i] - mat.dataPtr[i]);
	}

	return GMMatrix(rows, cols, container);
}

GMEngine::GMMatrix& GMEngine::GMMatrix::operator*=(float n)
{
	for (int i = 0; i < nElements; i++)
	{
		dataPtr[i] *= n;
	}
	return *this;
}

GMEngine::GMMatrix GMEngine::GMMatrix::operator*(float n) const
{
	std::vector<float> container;
	for (int i = 0; i < nElements; i++)
	{
		container.emplace_back(dataPtr[i] * n);
	}

	return GMMatrix(rows, cols, container);
}

GMEngine::GMVector GMEngine::GMMatrix::operator*(const GMVector vec)
{
	//Vectors used in GME has 3 dimensions so this operation is fixed for 3x3 matricies.
	//I may change this if I need more dimensions in my vectors.
	if (rows == 3 && cols == 3)
	{
		return GMVector(dataPtr[0] * vec.x + dataPtr[3] * vec.y + dataPtr[6] * vec.z,
			dataPtr[1] * vec.x + dataPtr[4] * vec.y + dataPtr[7] * vec.z,
			dataPtr[2] * vec.x + dataPtr[5] * vec.y + dataPtr[8] * vec.z);
	}
}

GMEngine::GMMatrix GMEngine::GMMatrix::operator*(const GMMatrix& mat) const
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

	return GMMatrix(rows, mat.cols, container);
}

void GMEngine::GMMatrix::show() const
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

void GMEngine::GMMatrix::makeIdentity()
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

GMEngine::GMMatrix GMEngine::GMMatrix::getIdentity() const
{
	assert(rows == cols);
	std::vector<float> container(nElements,0);
	for (int i = 0; i < nElements; i += (rows + 1))
	{
		container[i] = 1;
	}
	return GMMatrix(rows,cols,container);
}

GMEngine::GMMatrix GMEngine::GMMatrix::getTranspose() const
{
	GMMatrix transpose(cols, rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			transpose.dataPtr[i * cols + j] = dataPtr[j * rows + i];
		}
	}
	return transpose;
}

GMEngine::GMMatrix GMEngine::GMMatrix::getMinorMatrix( int selectedRow, int selectedCol ) const
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
	return GMMatrix(rows - 1, cols - 1, container);
}

float GMEngine::GMMatrix::getDeterminant() const
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
			auto minorMatrix = getMinorMatrix(0, i);
			if (i % 2 == 0)
				det += dataPtr[i * rows] * minorMatrix.getDeterminant();
			else
				det -= dataPtr[i * rows] * minorMatrix.getDeterminant();
		}
		return det;
	}
}

float GMEngine::GMMatrix::getCofactor(int selectedRow, int selectedCol) const
{
	if((selectedRow + selectedCol) % 2 == 0)
		return getMinorMatrix(selectedRow, selectedCol).getDeterminant() ;
	else
		return -getMinorMatrix(selectedRow, selectedCol).getDeterminant();
}

GMEngine::GMMatrix GMEngine::GMMatrix::getCofactorMatrix() const
{
	std::vector<float> container(nElements);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			container[i * rows + j] = getCofactor(j, i);
		}
	}
	return GMMatrix(rows, cols, container);
}

GMEngine::GMMatrix GMEngine::GMMatrix::getAdjointMatrix() const
{
	return getCofactorMatrix().getTranspose();
}

GMEngine::GMMatrix GMEngine::GMMatrix::getInverse() const
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