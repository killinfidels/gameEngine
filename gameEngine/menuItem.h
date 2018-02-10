#pragma once
#include "object.h"

class MenuItem : public Object
{
public:
	MenuItem(int x, int y, int w, int h);
	~MenuItem();

	enum status
	{
		MOUSECLICK, MOUSEOVER, MOUSEHOLD, MOUSENOTHING
	};

	void eventHandler(SDL_Event* e);
	bool activated();
	void setTextures(SDL_Texture* notPressedTexture, SDL_Texture* pressedTexture);
	

private:
	int mouseX, mouseY;
	
	status clickStatus;
	status locationStatus;

	bool clicked = false;

	SDL_Texture* pressed = NULL;
	SDL_Texture* notPressed = NULL;
};
