#pragma once
#include "GMVector.h"
namespace GMEngine
{
	class GMQuaternion
	{
	public:
		//Constructors
		GMQuaternion();
		GMQuaternion(float scalar, GMVector vector);

		//Copy Constructors
		GMQuaternion(const GMQuaternion& quat);
		GMQuaternion& operator=(const GMQuaternion& quat);

		//Destructor
		~GMQuaternion();

		//Functions
			//Addition
		GMQuaternion& operator+=(const GMQuaternion& quat);
		GMQuaternion operator+(const GMQuaternion& quat) const;
			//Subtraction
		GMQuaternion& operator-=(const GMQuaternion& quat);
		GMQuaternion operator-(const GMQuaternion& quat) const;
			//Scalar Multiplication
		GMQuaternion& operator*=(const float n);
		GMQuaternion operator*(const float n) const;
			//Multiplication
		GMQuaternion multiply(const GMQuaternion& quat) const;
		GMQuaternion& operator*=(const GMQuaternion& quat);
		GMQuaternion operator*(const GMQuaternion& quat) const;
			//Misc
		float getNorm() const;
		void normalize();
		void convertToUnitNorm();
		GMQuaternion getConjugate() const;
		GMQuaternion getInverse() const;

		//Elements
		float scalar;
		GMVector vector;
	};
}

