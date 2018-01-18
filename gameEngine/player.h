#pragma once
#include "Header.h"

class _player
{
public:
	_player(int x, int y, int w, int h);
	~_player();

	SDL_Rect pRect;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void slowDown(char s);
	void collision(SDL_Rect cObject);

	void update();

private:
	int speed = 4;
	int maxSpeed = 20;
	int _x = 0, _y = 0;
	int velocity_x = 0, velocity_y = 0;
};