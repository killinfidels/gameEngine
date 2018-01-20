#include "menuItem.h"

menuItem::menuItem(int x, int y, int w, int h): object(w, h, false)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	object.rect.x = x;
	object.rect.y = y;
}

menuItem::~menuItem()
{
}