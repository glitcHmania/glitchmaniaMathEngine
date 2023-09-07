#include "GMVector.h"
#include <assert.h>
#include <math.h>
#include <iostream>
#include "GMQuaternion.h"

GMEngine::GMVector::GMVector()
	:
	x(0.0f),
	y(0.0f),
	z(0.0f),
	w(1.0f)
{
}

GMEngine::GMVector::GMVector(float x, float y, float z)
	:
	x(x),
	y(y),
	z(z),
	w(1.0f)
{
}

GMEngine::GMVector::GMVector(float x, float y, float z, float w)
	:
	x(x),
	y(y),
	z(z),
	w(w)
{
}

GMEngine::GMVector::GMVector(const GMVector& vec)
	:
	x(vec.x),
	y(vec.y),
	z(vec.z),
	w(1.0f)
{
}

GMEngine::GMVector& GMEngine::GMVector::operator=(const GMVector& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = 1.0f;

	return *this;
}

GMEngine::GMVector::~GMVector()
{
}

GMEngine::GMVector& GMEngine::GMVector::operator+=(const GMVector& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;

	return *this;
}

GMEngine::GMVector GMEngine::GMVector::operator+(const GMVector& vec) const
{
	return GMVector(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

GMEngine::GMVector& GMEngine::GMVector::operator-=(const GMVector& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;

	return *this;
}

GMEngine::GMVector GMEngine::GMVector::operator-(const GMVector& vec) const
{
	return GMVector(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

GMEngine::GMVector& GMEngine::GMVector::operator*=(float n)
{
	x *= n;
	y *= n;
	z *= n;
	w *= n;

	return *this;
}

GMEngine::GMVector GMEngine::GMVector::operator*(float n) const
{
	return GMVector(x * n, y * n, z * n, w * n);
}

GMEngine::GMVector& GMEngine::GMVector::operator/=(float n)
{
	assert(n != 0);
	x /= n;
	y /= n;
	z /= n;
	w /= n;

	return *this;
}

GMEngine::GMVector GMEngine::GMVector::operator/(float n) const
{
	assert(n != 0);
	return GMVector(x / n, y / n, z / n, w / n);
}

float GMEngine::GMVector::operator*(const GMVector& vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

float GMEngine::GMVector::dot(const GMVector& vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

GMEngine::GMVector GMEngine::GMVector::operator%(const GMVector& vec) const
{
	return GMVector(
		y * vec.z - vec.y * z,
		z * vec.x - vec.z * x,
		x * vec.y - vec.x * y,
		1.0f
	);
}

GMEngine::GMVector& GMEngine::GMVector::operator%=(const GMVector& vec)
{
	x = y * vec.z - vec.y * z;
	y = z * vec.x - vec.z * x;
	z = x * vec.y - vec.x * y;

	return *this;
}

GMEngine::GMVector GMEngine::GMVector::cross(const GMVector& vec) const
{
	return GMVector(
		y * vec.z - vec.y * z,
		z * vec.x - vec.z * x,
		x * vec.y - vec.x * y,
		1.0f
	);
}

void GMEngine::GMVector::show()
{
	std::cout << "[";
	std::cout << x << std::endl;
	std::cout << " " << y << std::endl;
	std::cout << " " << z << std::endl;
	std::cout << " " << w;
	std::cout << "]" << std::endl;
}

float GMEngine::GMVector::getMagnitude()
{
	return sqrt(x * x + y * y + z * z);
}

void GMEngine::GMVector::normalize()
{
	float mag = getMagnitude();
	float magInv = 0.0f;
	if (mag > 0.0f)
		magInv = 1.0f / mag;

	x *= magInv;
	y *= magInv;
	z *= magInv;
	w *= magInv;
}

GMEngine::GMVector GMEngine::GMVector::getNormalized()
{
	float mag = getMagnitude();
	float magInv = 0.0f;
	if (mag > 0.0f)
		magInv = 1.0f / mag;

	return GMVector(x * magInv, y * magInv, z * magInv, w * magInv);
}

GMEngine::GMVector GMEngine::GMVector::rotate(float angle, GMVector& axis)
{
	//Normalize the axis, create the pure and real quaternions.
	axis.normalize();
	GMQuaternion pureQuat(0, (*this));
	GMQuaternion realQuat(angle, axis);

	//Convert real quaternion to unit norm and get its inverse to use for divison operation.
	realQuat.convertToUnitNorm();
	auto realQuatInv = realQuat.getInverse();
	auto rotatedQuat = realQuat * pureQuat * realQuatInv;

	return rotatedQuat.vector;
}
