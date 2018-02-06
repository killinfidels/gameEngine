#pragma once
#include "Header.h"

class Player
{
public:
	Player(int x, int y, int w, int h);
	~Player();

	SDL_Rect rect;

	void slowDown(char s);
	void collision(SDL_Rect cObject, bool inside);

	void update();

	enum directions
	{
		LEFT, RIGHT, UP, DOWN
	};

	void move(directions);

private:
	void stopX(int x);
	void stopY(int y);
	
	//keeps track of the last direction the player was traveling
	directions direction;

	int speed = 4;
	int maxSpeed = 20;
	int velocity_x = 0, velocity_y = 0;
};