#pragma once
#include "basics.h"

class WindowM
{
public:
	WindowM(const char* _name, int _w, int _h);
	~WindowM();

	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	const char* name;

	int width;
	int height;

	bool success = true;
};