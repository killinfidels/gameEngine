#pragma once
#include "Header.h"

class menuItem
{
public:
	object mObject;
	menuItem(int x, int y, int w, int h);
	~menuItem();

	void mouseStuff(SDL_Event* e);
	SDL_Rect rect;

	void setTextures(SDL_Texture* pressed, SDL_Texture* notPressed);
	
private:
	bool pressed;

	SDL_Texture* tPressed = NULL;
	SDL_Texture* tNotPressed = NULL;

	int mouseX;
	int mouseY;
};
