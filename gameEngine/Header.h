#pragma once
#ifndef _cat_
#define _cat_

#include <SDL.h>

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "object.h"
#include "texture.h"
#include <cstdlib>
#include <ctime>

const int screen_width = 1280;
const int screen_height = 720;

class KeyboardHandler
{
public:
	void handleKeyboardEvent(SDL_Event* event)
	{
		keyState[event->key.keysym.sym] = event->key.state;
	}

	bool isPressed(int keyCode)
	{
		return (keyState[keyCode] == SDL_PRESSED);
	}

	bool isReleased(int keyCode)
	{
		return (keyState[keyCode] == SDL_RELEASED);
	}

private:
	int keyState[];
};
#endif // !cat

