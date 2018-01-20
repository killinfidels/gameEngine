#pragma once
#include "Header.h"

class _player
{
public:
	_player(int x, int y, int w, int h);
	~_player();

	SDL_Rect pRect;

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
	int _x = 0, _y = 0;
	int velocity_x = 0, velocity_y = 0;
};