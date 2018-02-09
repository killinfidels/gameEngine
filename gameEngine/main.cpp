#include "Header.h"

#include "menuItem.h"

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

	Player player1(screen_width / 2, screen_height / 2, 200, 150);

	Object object1(150, 200, false);

	Object screen(screen_height, screen_width, false);

	MenuItem test(25, 34, 150, 200);

	if (!init())
	{
		SDL_Delay(5000);
	}
	else
	{
		Texture sabrine(renderer, "img/sabrine.BMP");
		Texture vatar(renderer, "img/vatar.PNG");
		SDL_Event e;

		object1.setTexture(sabrine.texture);
		test.setTexture(vatar.texture);

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
					
					test.eventHandler(*e);

					if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
                        			case SDLK_w:
							player1.move(player1.UP);
							break;

						case SDLK_DOWN:
                        			case SDLK_s:
							player1.move(player1.DOWN);
							break;

						case SDLK_LEFT:
                       				case SDLK_a:
							player1.move(player1.LEFT);
							break;

						case SDLK_RIGHT:
                      				case SDLK_d:
							player1.move(player1.RIGHT);
							break;
						default:
							break;
						}
					}
				}

				player1.update();

				player1.collision(object1.rect, false);
				player1.collision(screen.rect, true);

				SDL_RenderClear(renderer);

				SDL_RenderCopy(renderer, sabrine.texture, NULL, &player1.rect);

				object1.render(renderer, (screen_width / 2) - (object1.rect.w/2), (screen_height / 2) - (object1.rect.h / 2));

				test.render(renderer, test.rect.x, test.rect.y);

				SDL_RenderPresent(renderer);

				SDL_Delay(16);
			}
		}
		sabrine.~Texture();
		vatar.~Texture();
	}

	object1.~Object();
	screen.~Object();
	player1.~Player();

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
