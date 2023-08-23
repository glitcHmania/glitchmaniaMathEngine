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
		GMQuaternion& operator+=(const GMQuaternion& quat);
		GMQuaternion operator+(const GMQuaternion& quat) const;
		GMQuaternion& operator-=(const GMQuaternion& quat);
		GMQuaternion operator-(const GMQuaternion& quat) const;

		//Elements
		float scalar;
		GMVector vector;
	};
}

