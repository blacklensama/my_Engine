#pragma once

#include "background.h"
#include "stringManager.h"

class gameManager
{
public:
	gameManager();
	~gameManager();
	void update();
	void draw();
protected:
private:
	pictureManager _pic;
	stringManager _str;
	galStatue _status;
};