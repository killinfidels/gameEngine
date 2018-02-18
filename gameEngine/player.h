#pragma once
#include "basics.h"
#include "object.h"

class Player : public Object
{
public:
	Player(int x, int y, int w, int h);
	~Player();

	void collision(SDL_Rect cObject, bool inside);

	enum directions
	{
		LEFT, RIGHT, UP, DOWN
	};

	void move(directions);

private:
	//keeps track of the last direction the player was traveling
	directions direction;
};