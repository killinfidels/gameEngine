#pragma once
#include "basics.h"
#include "object.h"
#include "texture.h"
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "menuItem.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;

bool init(const char* name, const int width, const int height);

void close();

void setFPS(int fps);

class KeyboardHandler
{
public:
	void handleKeyboardEvent(SDL_Event* event);

	bool isPressed(int keyCode);

	bool isReleased(int keyCode);

private:
	int keyState[];
};