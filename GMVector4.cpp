#include "GMVector4.h"
#include <assert.h>
#include <math.h>
#include <iostream>
#include "GMQuaternion.h"

// Some of the functions are commented because they are not needed for 4D Vectors.

GMEngine::GMVector4::GMVector4()
	:
	x(0.0f),
	y(0.0f),
	z(0.0f),
	w(1.0f)
{
}

GMEngine::GMVector4::GMVector4(const GMVector vec, float w)
	:
	x(vec.x),
	y(vec.y),
	z(vec.z),
	w(w)
{
}

GMEngine::GMVector4::GMVector4(float x, float y, float z)
	:
	x(x),
	y(y),
	z(z),
	w(1.0f)
{
}

GMEngine::GMVector4::GMVector4(float x, float y, float z, float w)
	:
	x(x),
	y(y),
	z(z),
	w(w)
{
}

GMEngine::GMVector4::GMVector4(const GMVector4& vec)
	:
	x(vec.x),
	y(vec.y),
	z(vec.z),
	w(vec.w)
{
}

GMEngine::GMVector4& GMEngine::GMVector4::operator=(const GMVector4& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;

	return *this;
}

GMEngine::GMVector4::~GMVector4()
{
}

GMEngine::GMVector4& GMEngine::GMVector4::operator+=(const GMVector4& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;

	return *this;
}

GMEngine::GMVector4 GMEngine::GMVector4::operator+(const GMVector4& vec) const
{
	return GMVector4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

GMEngine::GMVector4& GMEngine::GMVector4::operator-=(const GMVector4& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;

	return *this;
}

GMEngine::GMVector4 GMEngine::GMVector4::operator-(const GMVector4& vec) const
{
	return GMVector4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

GMEngine::GMVector4& GMEngine::GMVector4::operator*=(float n)
{
	x *= n;
	y *= n;
	z *= n;
	w *= n;

	return *this;
}

GMEngine::GMVector4 GMEngine::GMVector4::operator*(float n) const
{
	return GMVector4(x * n, y * n, z * n, w * n);
}

GMEngine::GMVector4& GMEngine::GMVector4::operator/=(float n)
{
	assert(n != 0);
	x /= n;
	y /= n;
	z /= n;
	w /= n;

	return *this;
}

GMEngine::GMVector4 GMEngine::GMVector4::operator/(float n) const
{
	assert(n != 0);
	return GMVector4(x / n, y / n, z / n, w / n);
}

//float GMEngine::GMVector4::operator*(const GMVector4& vec) const
//{
//	return x * vec.x + y * vec.y + z * vec.z;
//}
//
//float GMEngine::GMVector4::dot(const GMVector4& vec) const
//{
//	return x * vec.x + y * vec.y + z * vec.z;
//}

void GMEngine::GMVector4::show()
{
	std::cout << "[";
	std::cout << x << std::endl;
	std::cout << " " << y << std::endl;
	std::cout << " " << z << std::endl;
	std::cout << " " << w;
	std::cout << "]" << std::endl;
}

//float GMEngine::GMVector4::getMagnitude()
//{
//	return sqrt(x * x + y * y + z * z);
//}
//
//void GMEngine::GMVector4::normalize()
//{
//	float mag = getMagnitude();
//	float magInv = 0.0f;
//	if (mag > 0.0f)
//		magInv = 1.0f / mag;
//
//	x *= magInv;
//	y *= magInv;
//	z *= magInv;
//}

//GMEngine::GMVector4 GMEngine::GMVector4::getNormalized()
//{
//	float mag = getMagnitude();
//	float magInv = 0.0f;
//	if (mag > 0.0f)
//		magInv = 1.0f / mag;
//
//	return GMVector4(x * magInv, y * magInv, z * magInv);
//}

//GMEngine::GMVector4 GMEngine::GMVector4::rotate(float angle, GMVector4& axis)
//{
//	//Normalize the axis, create the pure and real quaternions.
//	axis.normalize();
//	GMQuaternion pureQuat(0, (*this));
//	GMQuaternion realQuat(angle, axis);
//
//	//Convert real quaternion to unit norm and get its inverse to use for divison operation.
//	realQuat.convertToUnitNorm();
//	auto realQuatInv = realQuat.getInverse();
//	auto rotatedQuat = realQuat * pureQuat * realQuatInv;
//
//	return rotatedQuat.vector;
//}
