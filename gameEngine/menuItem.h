#pragma once
#include "object.h"

class MenuItem : public Object
{
public:

    //object mObject;
	MenuItem(int x, int y, int w, int h);
	~MenuItem();

	enum status
	{
		MOUSECLICK, MOUSEOVER, MOUSEHOLD, MOUSENOTHING
	};

	void MenuItem::eventHandler(SDL_Event* e)
	bool MenuItem::pressed()
	

private:
	int mouseX, mouseY;
	
	status clickStatus;
	status locationStatus;
};
