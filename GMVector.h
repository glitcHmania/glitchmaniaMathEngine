#pragma once
namespace GMEngine
{
	class GMVector
	{
	public:
		//Constructors
		GMVector();
		GMVector(float x, float y, float z);

		//Copy Constructors
		GMVector(const GMVector& vec);
		GMVector& operator=(const GMVector& vec);

		//Destructor
		~GMVector();

		//Functions
			//Addition
		GMVector& operator+=(const GMVector& vec);
		GMVector operator+(const GMVector& vec) const;
			//Subtraction
		GMVector& operator-=(const GMVector& vec);
		GMVector operator-(const GMVector& vec) const;
			//Scalar Multiplication
		GMVector& operator*=(const float n);
		GMVector operator*(const float n) const;
			//Scalar Divison
		GMVector& operator/=(float n);
		GMVector operator/(float n) const;
			//Dot Product
		float operator*(const GMVector& vec) const;
		float dot(const GMVector& vec) const;
			//Cross Product
		GMVector operator%(const GMVector& vec) const;
		GMVector& operator%=(const GMVector& vec);
		GMVector cross(const GMVector& vec) const;
			//Misc
		void show();
		float getMagnitude();
		void normalize();
		GMVector getNormalized();
		GMVector rotate(float angle, GMVector& axis);

		//Elements
		float x;
		float y;
		float z;
	};
}