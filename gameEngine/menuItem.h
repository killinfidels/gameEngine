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

	status mouseStatus;

private:

};
