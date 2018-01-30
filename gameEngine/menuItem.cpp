#include "menuItem.h"

menuItem::menuItem(int x, int y, int w, int h)//: mObject(w, h, false)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	//mObject.rect.x = x;
	//mObject.rect.y = y;
}

menuItem::~menuItem()
{
}
