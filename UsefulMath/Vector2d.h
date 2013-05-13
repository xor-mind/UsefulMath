#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <cmath>

//typedef UsefulMath::Vector2 Vec2

namespace UsefulMath
{

class Vector2
{
public:

	float x, y;

public:

	Vector2(float x0,float y0):x(x0),y(y0){}
	Vector2() {};

	Vector2 floor() { return Vector2( std::floor(x), std::floor(y) ); }
	Vector2 Round() { return Vector2( (x > 0.0f) ? ::floor(x + 0.5f) : ceil(x - 0.5f), (y > 0.0f) ? ::floor(y + 0.5f) : ceil(y - 0.5f) ); }

	float	Length() const // Get the Vector2D's magnitude.	
	{
		return (float)sqrt(x*x + y*y);
	}
	float	LengthSqr() const // Get the Vector2D's magnitude squared.
	{
		return (x*x + y*y);
	}

	// Vector2 Transformation Functions
	void RotateVectorCounterClockwise(float angle)
	{
			float     x0 = x,
					  cosa = cos(angle),
					  sina = sin(angle); 
			
			// point rotation as derived from the angle sum formulas in trig, sin(a+b) and cos(a+b)
			x = x0*cosa-y*sina;
			y = y*cosa+x0*sina;
	}

	int      operator==(const Vector2& rhs)
	{
		if (!(*this != rhs))
			return 1;
		else
			return 0;
	}
	int      operator!=(const Vector2& rhs)
	{
		if (x != rhs.x || y != rhs.y)
			return 1;
		else
			return 0;
	}
	Vector2   operator* (const float rhs)
	{
		return (Vector2(*this) *= rhs);
	}
	Vector2   operator/ (const float rhs)
	{
		return (Vector2(*this) /= rhs);
	}
	Vector2&  operator*= (const float rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}
	Vector2&  operator*= (const Vector2& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}
	Vector2&  operator/= (const float rhs)
	{
		x/=rhs;
		y/=rhs;
		return (*this);
	}
	Vector2   operator+ (const Vector2& rhs)
	{
		return (Vector2(*this) += rhs);
	}
	Vector2&  operator+=(const Vector2& rhs)
	{
		x+=rhs.x;
		y+=rhs.y;
		return (*this);
	}
	Vector2   operator- (const Vector2& rhs)
	{
		return (Vector2(*this) -= rhs);
	}
	Vector2&  operator-=(const Vector2& rhs)
	{
		x-=rhs.x;
		y-=rhs.y;
		return (*this);
	}

	friend Vector2 operator * (float f, const Vector2& v)
	{
	  return Vector2(v.x*f,v.y*f);
	}
};


}

#endif
