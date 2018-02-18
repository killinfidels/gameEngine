#pragma once

#include <gameEngine.h>
#include <iostream>

const char* windowName = "PONG";
const int screen_width = 1280;
const int screen_height = 720;

//init flag
bool initialized = init(windowName, screen_width, screen_height);

//handles keyboard input
KeyboardHandler keyHandler;

enum gameState
{
	MAINMENU, PLAYING, PAUSED, OPTIONS, RESTART, ENDSTATE
};

gameState currentState = MAINMENU; //program state


//Object objects
Object screen(screen_width, screen_height, false);

Object counter1(80, 80, false);

Object counter2(80, 80, false);

Object winText(700, 350, false);


//Player objects
Player player1(15, (screen_height / 2) - 45, 30, 90);

Player player2(screen_width - 15 - 30, (screen_height / 2) - 45, 30, 90);

//MenuItem objects

MenuItem mPlay(480, 320, 320, 80);

MenuItem mOptions(480, 480, 320, 80);

MenuItem mExit(480, 640, 320, 80);

MenuItem pUnpause(480, 320, 320, 80);
MenuItem pRestart(480, 480, 320, 80);
MenuItem pReturn(480, 640, 320, 80);

MenuItem oWeeb(480, 320, 320, 80);

MenuItem ball(screen_width / 2 - 15, screen_height / 2 - 15, 30, 30);

//Texture objects
Texture vatar(renderer, "img/vatar.png");
Texture paddle(renderer, "img/paddle.png");
Texture paddle2(renderer, "img/gamepaddle.png");
Texture mainmenutemplate(renderer, "img/mainmenutemplate.bmp");
Texture gamemap(renderer, "img/gamemap.png");
Texture circle(renderer, "img/ball.png");
Texture wokeball(renderer, "img/hyperglarp.png");

Texture mainmenu(renderer, "img/mainMenu.png");
Texture pausemenu(renderer, "img/PauseScreen.png");
Texture optionsmenu(renderer, "img/optionsMenu.png");

Texture tPlay(renderer, "img/menuButtonPlay.png");
Texture tOptions(renderer, "img/menuButtonOptions.png");
Texture tExit(renderer, "img/menuButtonExit.png");

Texture tUnpause(renderer, "img/pauseButtonUnpause.png");
Texture tRestart(renderer, "img/pauseButtonRestart.png");
Texture tReturn(renderer, "img/pauseButtonReturn.png");

Texture tWeebOn(renderer, "img/optionsButtonWeebOn.png");
Texture tWeebOff(renderer, "img/optionsButtonWeebOff.png");

Texture jojo(renderer, "img/jojobg.png");

//text textures
Texture winTextTexture;
Texture countNumbers[11]; //textures to be used by the counter Object
	//unused textures
		//Texture hepl(renderer, "img/plshepl.jpg");
		//Texture sabrine(renderer, "img/sabrine.bmp");

//font stuff
TTF_Font* arial = TTF_OpenFont("arial.ttf", 24);
SDL_Color White = { 255, 255, 255 };
SDL_Color Red = { 255, 0, 0 };