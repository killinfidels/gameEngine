#include "../header-files/gameEngine.h"

Uint32 FPSticks = 0;

void setFPS(int fps)
{
	FPSticks = SDL_GetTicks() - FPSticks;

	if (1000 / fps >= FPSticks)
		SDL_Delay(1000 / fps - FPSticks);

	FPSticks = SDL_GetTicks();
}

int KeyboardHandler::indexHandler(int keyCode)
{
	int indexN;
	for (int i = 0; i <= keys; i++)
	{
		if (i != keys)
		{
			if (keyIndex[i] == keyCode)
			{
				indexN = i;
				i = keys + 1;
			}
		}
		else
		{
			keys++;
			keyIndex.resize(keys);
			keyIndex[i] = keyCode;
			indexN = i;
			i = keys + 1;
		}
	}

	return indexN;
}

void KeyboardHandler::handleKeyboardEvent(SDL_Event* event)
{
	keyState.setFlag(indexHandler(event->key.keysym.sym), event->key.state);
}

bool KeyboardHandler::isPressed(int keyCode)
{
	return (keyState.checkFlag(indexHandler(keyCode)) == SDL_PRESSED);
}

bool KeyboardHandler::isReleased(int keyCode)
{
	return (keyState.checkFlag(indexHandler(keyCode)) == SDL_RELEASED);
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
	Uint32 seeed = time(NULL);
	srand(seeed);
	//std::cout << seeed << std::endl;

	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
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
		
		if (!TTF_Init() == -1)
		{
			printf("ttfdeded/n");
			printf(TTF_GetError());
		}

		//Initialize SDL_mixer
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			printf("soundeded/n");
			printf(Mix_GetError());
		}
	}

	return success;
}

void close()
{
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}