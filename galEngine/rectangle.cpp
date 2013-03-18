#include "rectangle.h"

rectangle::rectangle()
{
	_x1 = _x2 = _y1 = _y2 = 0;
}

rectangle::rectangle(float x1, float y1, float x2, float y2)
{
	setRect(x1,y1,x2,y2);
}

void rectangle::setRect(float x1, float y1, float x2, float y2)
{
	_x1 = x1;
	_x2 = x2;
	_y1 = y1;
	_y2 = y2;
}

bool rectangle::InRectangle(float x1, float y1)
{
	if (x1 < _x2 && x1 > _x1)
	{
		if (y1 < _y2 && y1 > _y1)
		{
			return true;
		}
	}
	return false;
}