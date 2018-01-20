#pragma once
#include "Header.h"

class menuItem
{
public:
	menuItem(int x, int y, int w, int h);
	~menuItem();

	SDL_Rect rect;

	object object;
private:

};
