#include "Header.h"
#include "player.h"
#include "menuItem.h"

const char* windowName = "A window";

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

KeyboardHandler keyHandler;

enum gameState
{
	MAINMENU, PLAYING, PAUSED, OPTIONS
};

gameState currentState = MAINMENU;

bool loadMedia();

void close();

bool init()
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
		window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, NULL);

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
					if (!TTF_Init()==-1)
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

int main(int argc, char* args[])
{
	bool quit = false;

	Player player1(15, (screen_height / 2) - 45, 30, 90);

	Player player2(screen_width - 15 - 30, (screen_height / 2) - 45, 30, 90);

	//Object object1(200, 150, false);

	Object screen(screen_width, screen_height, false);

	Object counter1(80, 80, false);
	counter1.rect.x = 480;

	Object counter2(80, 80, false);
	counter2.rect.x = 720;

	Object cowboy(700, 350, false);
	cowboy.rect.x = screen_width/2 - cowboy.rect.w/2;
	cowboy.rect.y = screen_height/2;

	//MenuItem mTest(25, 34, 200, 150);

	MenuItem mPlay(480, 320, 320, 80);

	MenuItem mOptions(480, 480, 320, 80);

	MenuItem mExit(480, 640, 320, 80);

	MenuItem ball(screen_width / 2 - 15, screen_height / 2 - 15, 30, 30);

	ball._moveable = true;

	ball.setVelocityX(-5);
	ball.setVelocityY(-1);

	if (!init())
	{
		SDL_Delay(5000);
	}
	else
	{
		TTF_Font* arial = TTF_OpenFont("arial.ttf", 24);
		SDL_Color White = { 255, 255, 255 };
		SDL_Color Red = { 255, 0, 0 };
		

		Texture count[11];

		Texture yeehaw;

		yeehaw.createTextureFromText(renderer, arial, "yeee haww, cowboyy, you did it!!!!!", Red);

		for (int i = 0; i < 11; i++)
		{
			if (i < 10)
			{
				count[i].createTextureFromText(renderer, arial, std::to_string(0) + std::to_string(i), White);
			}
			else
			{
				count[i].createTextureFromText(renderer, arial, std::to_string(i), White);
			}
		}

		//Texture sabrine(renderer, "img/sabrine.bmp");
		Texture vatar(renderer, "img/vatar.png");
		//Texture hepl(renderer, "img/plshepl.jpg");
		Texture paddle(renderer, "img/paddle.png");
		Texture paddle2(renderer, "img/gamepaddle.png");
		Texture mainmenu(renderer, "img/mainmenutemplate.bmp");
		Texture gamemap(renderer, "img/gamemap.png");
		Texture circle(renderer, "img/ball.png");
		Texture wokeball(renderer, "img/hyperglarp.png");
		
		SDL_Event e;

		//object1.setTexture(sabrine.getTexture());
		//mTest.setTextures(vatar.getTexture(), sabrine.getTexture());
		mPlay.setTextures(vatar.getTexture(), vatar.getTexture());
		mOptions.setTextures(vatar.getTexture(), vatar.getTexture());
		mExit.setTextures(vatar.getTexture(), vatar.getTexture());

		ball.setTexture(circle.getTexture());

		screen.setTexture(mainmenu.getTexture());

		player1.setTexture(paddle.getTexture());
		player2.setTexture(paddle.getTexture());

		counter1.setTexture(count[0].getTexture());
		counter2.setTexture(count[0].getTexture());
		cowboy.setTexture(yeehaw.getTexture());

		if (!loadMedia())
		{
			SDL_Delay(5000);
		}
		else
		{
			int yaes = 0, yaes2 = 0;
			while (!quit)
			{
				if (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}


					//mTest.eventHandler(&e);
					mPlay.eventHandler(&e);
					mOptions.eventHandler(&e);
					mExit.eventHandler(&e);
					ball.eventHandler(&e);

					switch (e.type)
					{
					case SDL_KEYDOWN:
					case SDL_KEYUP:
						keyHandler.handleKeyboardEvent(&e);
						break;
					default:
						break;
					}
				}

				if (mPlay.activated())
				{
					currentState = PLAYING;
					screen.setTexture(gamemap.getTexture());
				}

				SDL_RenderClear(renderer);

				screen.render(renderer);

				switch (currentState)
				{
				case MAINMENU:
					mPlay.render(renderer);
					mOptions.render(renderer);
					mExit.render(renderer);

					if (keyHandler.isPressed(SDLK_RETURN))
					{
						currentState = PLAYING;
						screen.setTexture(gamemap.getTexture());
					}

					if (mPlay.activated())
						mPlay.setTexture(paddle2.getTexture());

					if (mOptions.activated())
						mOptions.setTexture(paddle2.getTexture());

					if (mExit.activated())
					{
						mExit.setTexture(paddle2.getTexture());
						quit = true;
					}


					break;
				case PLAYING:

					SDL_RenderDrawLine(renderer, screen_width/2, 0, screen_width/2, screen_height);

					if (keyHandler.isPressed(SDLK_1) && yaes != 0) {
						yaes--;
						counter1.setTexture(count[yaes].getTexture());
					}
						
					if (keyHandler.isPressed(SDLK_2) && yaes != 10) {
						yaes++;
						counter1.setTexture(count[yaes].getTexture());
					}

					if (keyHandler.isPressed(SDLK_w))
						player1.move(player1.UP);
					if (keyHandler.isPressed(SDLK_s))
						player1.move(player1.DOWN);

					if (keyHandler.isPressed(SDLK_UP))
						player2.move(player2.UP);
					if (keyHandler.isPressed(SDLK_DOWN))
						player2.move(player2.DOWN);

				/*	if (mTest.activated())
						mTest.setTexture(hepl.getTexture());*/

					player1.update();
					player2.update();

					switch (ball.ballCollision(screen.rect, true))
					{
					case 1:
						yaes++;
						if (yaes > 10)
							yaes = 10;
						ball.setVelocityX(-5);
						ball.setVelocityY(-1);
						ball.rect.x = screen_width / 2 - ball.rect.w / 2;
						ball.rect.y = screen_height / 2 - ball.rect.h / 2;
						counter1.setTexture(count[yaes].getTexture());
						break;
					case 2:
						yaes2++;
						if (yaes2 > 10)
							yaes2 = 10;
						ball.setVelocityX(-5);
						ball.setVelocityY(-1);
						ball.rect.x = screen_width / 2 - ball.rect.w / 2;
						ball.rect.y = screen_height / 2 - ball.rect.h / 2;
						counter2.setTexture(count[yaes2].getTexture());
						break;
					default:
						break;
					}
					
					ball.ballCollision(player1.rect, false);
					ball.ballCollision(player2.rect, false);

					ball.update();


					player1.collision(screen.rect, true);
					player2.collision(screen.rect, true);

					player1.render(renderer);
					player2.render(renderer);

					counter1.render(renderer);
					counter2.render(renderer);

					if (ball.activated())
						ball.setTexture(wokeball.getTexture());

					ball.render(renderer);

					//object1.render(renderer);

					//mTest.render(renderer);
					
					if (yaes == 10 || yaes2 == 10)
					{
						cowboy.render(renderer);
					}
					break;
				case PAUSED:
					break;
				case OPTIONS:
					break;
				default:
					break;
				}

				SDL_RenderPresent(renderer);

				SDL_Delay(16);
			}
		}
	}

	close();

	return 0;
}

bool loadMedia()
{
	return true;
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