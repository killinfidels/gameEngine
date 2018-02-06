#include "menuItem.h"

MenuItem::MenuItem(int x, int y, int w, int h) : Object(w, h, false)
{
	rect.x = x;
	rect.y = y;

	//mObject.rect.x = x;
	//mObject.rect.y = y;
}

MenuItem::~MenuItem()
{
}
