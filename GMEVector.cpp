#include "GMEVector.h"
#include <assert.h>
#include <math.h>

GMEngine::GMEVector::GMEVector()
	:
	x(0.0f),
	y(0.0f),
	z(0.0f)
{
}

GMEngine::GMEVector::GMEVector(float x, float y, float z)
	:
	x(x),
	y(y),
	z(z)
{
}

GMEngine::GMEVector::GMEVector(const GMEVector& vec)
	:
	x(vec.x),
	y(vec.y),
	z(vec.z)
{
}

GMEngine::GMEVector& GMEngine::GMEVector::operator=(const GMEVector& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;

	return *this;
}

GMEngine::GMEVector::~GMEVector()
{
}

GMEngine::GMEVector& GMEngine::GMEVector::operator+=(const GMEVector& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;

	return *this;
}

GMEngine::GMEVector GMEngine::GMEVector::operator+(const GMEVector& vec) const
{
	return GMEVector(x + vec.x, y + vec.y, z + vec.z);
}

GMEngine::GMEVector& GMEngine::GMEVector::operator-=(const GMEVector& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;

	return *this;
}

GMEngine::GMEVector GMEngine::GMEVector::operator-(const GMEVector& vec) const
{
	return GMEVector(x - vec.x, y - vec.y, z - vec.z);
}

GMEngine::GMEVector& GMEngine::GMEVector::operator*=(float n)
{
	x *= n;
	y *= n;
	z *= n;

	return *this;
}

GMEngine::GMEVector GMEngine::GMEVector::operator*(float n) const
{
	return GMEVector(x * n, y * n, z * n);
}

GMEngine::GMEVector& GMEngine::GMEVector::operator/=(float n)
{
	assert(n != 0);
	x /= n;
	y /= n;
	z /= n;

	return *this;
}

GMEngine::GMEVector GMEngine::GMEVector::operator/(float n) const
{
	assert(n != 0);
	return GMEVector(x / n, y / n, z / n);
}

float GMEngine::GMEVector::operator*(const GMEVector& vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

float GMEngine::GMEVector::dot(const GMEVector& vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

GMEngine::GMEVector GMEngine::GMEVector::operator%(const GMEVector& vec) const
{
	return GMEVector(
		y * vec.z - vec.y * z,
		z * vec.x - vec.z * x,
		x * vec.y - vec.x * y
	);
}

GMEngine::GMEVector& GMEngine::GMEVector::operator%=(const GMEVector& vec)
{
	x = y * vec.z - vec.y * z;
	y = z * vec.x - vec.z * x;
	z = x * vec.y - vec.x * y;

	return *this;
}

GMEngine::GMEVector GMEngine::GMEVector::cross(const GMEVector& vec) const
{
	return GMEVector(
		y * vec.z - vec.y * z,
		z * vec.x - vec.z * x,
		x * vec.y - vec.x * y
	);
}

float GMEngine::GMEVector::getMagnitude()
{
	return sqrt(x * x + y * y + z * z);
}

void GMEngine::GMEVector::normalize()
{
	float mag = getMagnitude();
	float magInv = 0.0f;
	if (mag > 0.0f)
		magInv = 1.0f / mag;

	x *= magInv;
	y *= magInv;
	z *= magInv;
}

GMEngine::GMEVector GMEngine::GMEVector::getNormalized()
{
	float mag = getMagnitude();
	float magInv = 0.0f;
	if (mag > 0.0f)
		magInv = 1.0f / mag;

	return GMEVector(x * magInv, y * magInv, z * magInv);
}
