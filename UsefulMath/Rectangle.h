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

	void CalcX2Y2()
	{
		right = left + w; bottom = top + h;
	}

	//static Rect SubtractPosition( const Rect& dest, const Rect& src )
	//{
	//	Rect r(dest.left - src.left, dest.top - src.top, dest.right - src.left, dest.bottom - src.top);
	//	return r;
	//}

	Rectangle SubtractPosition( const Rectangle& src )
	{
		Rectangle r( left - src.left, top - src.top, right - src.left, bottom - src.top );
		return r;
	}

};

}

#endif