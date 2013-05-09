#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vector2D.h"

namespace UsfulMath
{

class Rectangle
{
public:
		int left, top, right, bottom;
public:

	Rectangle()
	{ 
		left = top = right = bottom = 0; 
	}
	Rectangle(int left, int top, int right, int bottom)
		: left(left), top(top), right(right), bottom(bottom) {}
	Rectangle(Vector pos, Vector dim)
	{
		left = (int)pos.x; top = (int)pos.y;
		right = (int)(pos.x + dim.x);
		bottom = (int)(pos.y + dim.y);
	}
	~Rectangle() {}


	bool Intersect(Rectangle& otherRect)
	{
		if ( left <= otherRect.right && right >= otherRect.left )
		{
			if ( top <= otherRect.bottom && bottom >= otherRect.top )
			{
				return true;
			}
		}

		return false;
	}
};

}

#endif