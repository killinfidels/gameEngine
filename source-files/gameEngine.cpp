#include "../header-files/gameEngine.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void setFPS(int fps)
{
	SDL_Delay(1000 / fps);
}

void KeyboardHandler::handleKeyboardEvent(SDL_Event* event)
{
	keyState[event->key.keysym.sym] = event->key.state;
}

bool KeyboardHandler::isPressed(int keyCode)
{
	return (keyState[keyCode] == SDL_PRESSED);
}

bool KeyboardHandler::isReleased(int keyCode)
{
	return (keyState[keyCode] == SDL_RELEASED);
}

bool init(const char* name, const int width, const int height)
{
	srand(time(NULL));

	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, NULL);

		if (window == NULL)
		{
			printf("it deded/n");
			printf(SDL_GetError());

			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			if (renderer == NULL)
			{
				printf("it drendededed/n");
				printf(SDL_GetError());

				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

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
		}
	}

	return success;
}

void close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}