#pragma once
#include "GMVector.h"

namespace GMEngine
{
	class GMVector4 : public GMVector
	{
	// Some of the functions are commented because they are not needed for 4D Vectors.
	public:
		//Constructors
		GMVector4();
		GMVector4(const GMVector vec, float w = 1.0f);
		GMVector4(float x, float y, float z);
		GMVector4(float x, float y, float z, float w);

		//Copy Constructors
		GMVector4(const GMVector4& vec);
		GMVector4& operator=(const GMVector4& vec);

		//Destructor
		~GMVector4();

		//Functions
			//Addition
		GMVector4& operator+=(const GMVector4& vec);
		GMVector4 operator+(const GMVector4& vec) const;
			//Subtraction
		GMVector4& operator-=(const GMVector4& vec);
		GMVector4 operator-(const GMVector4& vec) const;
			//Scalar Multiplication
		GMVector4& operator*=(const float n);
		GMVector4 operator*(const float n) const;
			//Scalar Divison
		GMVector4& operator/=(float n);
		GMVector4 operator/(float n) const;
			//Dot Product
		//float operator*(const GMVector4& vec) const;
		//float dot(const GMVector4& vec) const;
			//Misc
		void show();
		//float getMagnitude();
		//void normalize();
		//GMVector4 getNormalized();
		//GMVector4 rotate(float angle, GMVector4& axis);

		//Elements
	public:
		float x;
		float y;
		float z;
		float w;
	};
}