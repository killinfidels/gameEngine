#pragma once
#include "Header.h"

class _player
{
public:
	_player(int x, int y, int w, int h);
	~_player();

	SDL_Rect pRect;

	void slowDown(char s);
	void collision(SDL_Rect cObject);

	void update();

	enum directions
	{
		LEFT, RIGHT, UP, DOWN
	};

public:
	void move(directions);

private:
	directions direction;

	int speed = 4;
	int maxSpeed = 20;
	int _x = 0, _y = 0;
	int velocity_x = 0, velocity_y = 0;
};