#pragma once
#include "basics.h"
#include "windows.h"
#include "object.h"
#include "texture.h"
#include "menuItem.h"
#include "animation.h"
#include "gamemap.h"

bool init();

void close();

void setFPS(int fps);

class FlagArrays
{
public:
	FlagArrays();
	FlagArrays(int size);

	void setFlag(int flag, bool state);

	bool checkFlag(int flag);

private:
	//bool flags[];
	void resize(int flag);
	int size = 0;
	std::vector<bool> flags;
};

class KeyboardHandler
{
public:
	void handleKeyboardEvent(SDL_Event* event);

	bool isPressed(int keyCode);

	bool isReleased(int keyCode);

private:
	int indexHandler(int keyCode);
	std::vector<int> keyIndex;
	int keys = 0;
	FlagArrays keyState;
};