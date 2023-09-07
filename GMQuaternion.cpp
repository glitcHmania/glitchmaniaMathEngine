#include "GMQuaternion.h"
#include "GMVector.h"
#define _USE_MATH_DEFINES
#include <math.h>

GMEngine::GMQuaternion::GMQuaternion()
	:
	scalar(0.0f),
	vector(0,0,0)
{
}

GMEngine::GMQuaternion::GMQuaternion(float scalar, GMVector vector)
	:
	scalar(scalar),
	vector(vector)
{
}

GMEngine::GMQuaternion::GMQuaternion(const GMQuaternion& quat)
	:
	scalar(quat.scalar),
	vector(quat.vector)
{
}

GMEngine::GMQuaternion& GMEngine::GMQuaternion::operator=(const GMQuaternion& quat)
{
	scalar = quat.scalar;
	vector = quat.vector;
	return *this;
}

GMEngine::GMQuaternion::~GMQuaternion()
{
}

GMEngine::GMQuaternion& GMEngine::GMQuaternion::operator+=(const GMQuaternion& quat)
{
	scalar += quat.scalar;
	vector += quat.vector;
	return *this;
}

GMEngine::GMQuaternion GMEngine::GMQuaternion::operator+(const GMQuaternion& quat) const
{
	return GMQuaternion(scalar + quat.scalar, vector + quat.vector);
}

GMEngine::GMQuaternion& GMEngine::GMQuaternion::operator-=(const GMQuaternion& quat)
{
	scalar -= quat.scalar;
	vector -= quat.vector;
	return *this;
}

GMEngine::GMQuaternion GMEngine::GMQuaternion::operator-(const GMQuaternion& quat) const
{
	return GMQuaternion(scalar - quat.scalar, vector - quat.vector);
}

GMEngine::GMQuaternion& GMEngine::GMQuaternion::operator*=(const float n)
{
	scalar *= n;
	vector *= n;
	return *this;
}

GMEngine::GMQuaternion GMEngine::GMQuaternion::operator*(const float n) const
{
	return GMQuaternion(scalar * n, vector * n);
}

GMEngine::GMQuaternion GMEngine::GMQuaternion::multiply(const GMQuaternion& quat) const
{
	return GMQuaternion(scalar * quat.scalar - vector.dot(quat.vector),
		quat.vector * scalar + vector * quat.scalar + vector.cross(quat.vector));
}

GMEngine::GMQuaternion& GMEngine::GMQuaternion::operator*=(const GMQuaternion& quat)
{
	(*this) = multiply(quat);
	return *this;
}

GMEngine::GMQuaternion GMEngine::GMQuaternion::operator*(const GMQuaternion& quat) const
{
	return multiply(quat);
}

float GMEngine::GMQuaternion::getNorm() const
{
	return sqrt(scalar * scalar + vector * vector);
}

void GMEngine::GMQuaternion::normalize()
{
	float norm = getNorm();
	if (norm != 0) 
	{
		float normInv = 1 / norm;
		scalar *= normInv;
		vector *= normInv;
	}
}

void GMEngine::GMQuaternion::convertToUnitNorm()
{
	float radian = scalar * (M_PI / 180.0f);
	vector.normalize();
	scalar = cosf(radian * 0.5f);
	vector *= sinf(radian * 0.5f);
}

GMEngine::GMQuaternion GMEngine::GMQuaternion::getConjugate() const
{
	return GMQuaternion(scalar, vector * (-1));
}

GMEngine::GMQuaternion GMEngine::GMQuaternion::getInverse() const
{
	float norm = getNorm();
	auto conj = getConjugate();

	float abs = 1.0f;
	if (norm != 0.0f)
		abs = 1 / (norm * norm);

	return GMQuaternion(conj.scalar * abs, conj.vector * abs);
}
