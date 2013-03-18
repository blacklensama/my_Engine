#pragma once

#include "stdafx.h"

class rectangle : public xiayuObject
{
public:
	rectangle();
	rectangle(float x1, float y1, float x2, float y2);
	void setRect(float x1, float y1, float x2, float y2);
	bool InRectangle(float x1, float x2);
	~rectangle(){};
private:
	float _x1,_x2,_y1,_y2;
};