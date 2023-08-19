#pragma once
namespace GMEngine {
	class GMEVector
	{
	public:
		//Constructors
		GMEVector();
		GMEVector(float x, float y, float z);

		//Copy Constructors
		GMEVector(const GMEVector& vec);
		GMEVector& operator=(const GMEVector& vec);

		//Destructor
		~GMEVector();

		//Functions
			//Addition
		GMEVector& operator+=(const GMEVector& vec);
		GMEVector operator+(const GMEVector& vec) const;
		//Subtraction
		GMEVector& operator-=(const GMEVector& vec);
		GMEVector operator-(const GMEVector& vec) const;
		//Scalar Multiplication
		GMEVector& operator*=(const float n);
		GMEVector operator*(const float n) const;
		//Scalar Divison
		GMEVector& operator/=(float n);
		GMEVector operator/(float n) const;
		//Dot Product
		float operator*(const GMEVector& vec) const;
		float dot(const GMEVector& vec) const;
		//Cross Product
		GMEVector operator%(const GMEVector& vec) const;
		GMEVector& operator%=(const GMEVector& vec);
		GMEVector cross(const GMEVector& vec) const;
		//Misc
		float getMagnitude();
		void normalize();
		GMEVector getNormalized();

		//Elements
		float x;
		float y;
		float z;
	};
}