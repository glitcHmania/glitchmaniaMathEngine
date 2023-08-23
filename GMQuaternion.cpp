#include "GMQuaternion.h"

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
