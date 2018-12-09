#include "../header-files/windows.h"

WindowM::WindowM(const char* windowName, int w, int h)
{
	name = windowName;
	width = w;
	height = h;

	window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, NULL);

	if (window == NULL)
	{
		printf(name);
		printf(":\nwindow could not be created:\nError:");
		printf(SDL_GetError());

		success = false;
	}
	else
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if (renderer == NULL)
		{
			printf(name);
			printf(":\nrenderer could not be created:\nError: ");
			printf(SDL_GetError());

			SDL_DestroyWindow(window);

			success = false;
		}
		else
		{
			if (SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND) != 0)
			{
				printf(name);
				printf(":\ncould not alpha blend:\nError: ");
				printf(SDL_GetError());
			}

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
	}
}

SDL_Window* WindowM::getWindow() { return window; }

SDL_Renderer* WindowM::getRenderer() { return renderer; }

WindowM::~WindowM()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
}