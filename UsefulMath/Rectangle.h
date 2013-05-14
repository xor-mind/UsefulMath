#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vector2D.h"

namespace UsefulMath
{

class Rectangle
{
public:
		int left, top, right, bottom, w, h;
public:

	Rectangle()
	{ 
		left = top = right = bottom = 0; 
		CalcDim();
	}
	Rectangle(int left, int top, int right, int bottom)
		: left(left), top(top), right(right), bottom(bottom) { CalcDim(); }

	Rectangle(Vector2 pos,Vector2 dim)
	{
		left = (int)pos.x; top = (int)pos.y;
		right = (int)(pos.x + dim.x);
		bottom = (int)(pos.y + dim.y);
		CalcDim();
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

	// figure out width and height based on current x1,x2 and y1,y2.
	void CalcDim()
	{
		w = right - left; h = bottom - top; 
	}
};

}

#endif