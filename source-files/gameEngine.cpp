#include "../header-files/gameEngine.h"

Uint32 FPSticks = 0;

void setFPS(int fps)
{
	FPSticks = SDL_GetTicks() - FPSticks;

	if (1000 / fps >= FPSticks)
		SDL_Delay(1000 / fps - FPSticks);

	FPSticks = SDL_GetTicks();
}

void KeyboardHandler::handleKeyboardEvent(SDL_Event* event)
{
	keyState.setFlag(event->key.keysym.sym, event->key.state);
}

bool KeyboardHandler::isPressed(int keyCode)
{
	return (keyState.checkFlag(keyCode) == SDL_PRESSED);
}

bool KeyboardHandler::isReleased(int keyCode)
{
	return (keyState.checkFlag(keyCode) == SDL_RELEASED);
}

FlagArrays::FlagArrays(int _size)
{
	flags.resize(_size);
}

FlagArrays::FlagArrays()
{
}

void FlagArrays::resize(int flag)
{
	if (flag + 1 > size)
	{
		flags.resize(flag + 1);

		for (size; size < flag + 1; size++)
		{
			flags[flag] = false;
		}
	}
}

void FlagArrays::setFlag(int flag, bool state)
{
	resize(flag);

	flags[flag] = state;
}

bool FlagArrays::checkFlag(int flag)
{
	resize(flag);

	return flags[flag];
}

bool init()
{
	srand(time(NULL));

	bool success = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!IMG_Init)
		{
			printf("imagededed/n");
			printf(IMG_GetError());
		}
		else
		{
			if (!TTF_Init() == -1)
			{
				printf("ttfdeded/n");
				printf(TTF_GetError());
			}
		}
	}

	return success;
}

void close()
{
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}