#include "Header.h"

const char* windowName = "A window";

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool loadMedia();

void exit();

bool init()
{
	bool success = true;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, NULL);

		if (window == NULL)
		{
			printf("it deded");
			printf(SDL_GetError());

			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			if (renderer == NULL)
			{
				printf("it drendededed");
				printf(SDL_GetError());

				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				if (!IMG_Init)
				{
					printf("imagededed");
					printf(IMG_GetError());
				}
			}
		}
	}

	return success;
}

int main(int argc, char* args[])
{
	bool quit = false;

	_player player1(screen_width / 2, screen_height / 2, 200, 150);

	_object object1(150, 200, false);

	if (!init())
	{
		SDL_Delay(5000);
	}
	else
	{
		_texture vatar(renderer, "img/sabrine.BMP");
		SDL_Event e;

		object1.setTexture(vatar.texture);

		if (!loadMedia())
		{
			SDL_Delay(5000);
		}
		else
		{
			while (!quit)
			{
				if (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}


					if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							player1.move(player1.UP);
							break;
						case SDLK_DOWN:
							player1.move(player1.DOWN);
							break;
						case SDLK_LEFT:
							player1.move(player1.LEFT);
							break;
						case SDLK_RIGHT:
							player1.move(player1.RIGHT);
							break;
						case SDLK_w:
							player1.move(player1.UP);
							break;
						case SDLK_s:
							player1.move(player1.DOWN);
							break;
						case SDLK_a:
							player1.move(player1.LEFT);
							break;
						case SDLK_d:
							player1.move(player1.RIGHT);
							break;
						default:
							break;
						}
					}
				}

				player1.update();

				player1.collision(object1.oRect);

				SDL_RenderClear(renderer);

				SDL_RenderCopy(renderer, vatar.texture, NULL, &player1.pRect);

				object1.render(renderer, screen_width / 2, screen_height / 2);

				SDL_RenderPresent(renderer);

				SDL_Delay(16);
			}
		}
		vatar.~_texture();
	}

	object1.~_object();
	player1.~_player();

	exit();

	return 0;
}

bool loadMedia()
{
	return true;
}

void exit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}