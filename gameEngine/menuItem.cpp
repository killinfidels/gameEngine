#include "menuItem.h"

MenuItem::MenuItem(int x, int y, int w, int h) : Object(w, h, false)
{
	rect.x = x;
	rect.y = y;

	//mObject.rect.x = x;
	//mObject.rect.y = y;
}

void MenuItem::eventHandler(SDL_Event* e)
{
//	SDL_MOUSEBUTTONDOWN
//SDL_MOUSEBUTTONUP
	switch(e->type)
	{
	case MOUSEBUTTONDOWN:
		clickStatus = MOUSECLICK
		break;
	case MOUSEMOTION:
		mouseX = e->motion.x;
		mouseY = e->motion.y;
		break;
	default:
		clickStatus = MOUSENOTHING;
		break;
	}
	
	if (!(mouseX > rect.x && mouseX < rect.x + rect.w))
		locationStatus = MOUSENOTHING;
	else if (!(mouseY > rect.y && mouseY < rect.y + rect.h))
		locationStatus = MOUSENOTHING;
	else
		locationStatus = MOUSEOVER;
				
}

bool MenuItem::pressed()
{
	if (clickStatus == MOUSECLICK && locationStatus)
		return true;
	return false;
}

MenuItem::~MenuItem()
{
}
