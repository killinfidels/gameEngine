#pragma once
#include "Header.h"

class _object
{
public:
	_object(int h, int w, bool movable);
	~_object();

	void render(SDL_Renderer* renderer, int x, int y);

	bool setTexture(SDL_Texture* oTexture);

	SDL_Rect oRect;
private:

	bool ERRORED = false;

	SDL_Texture* _oTexture;

	int speed;
	int maxSpeed;

	int velocity_x;
	int velocity_y;

	void centerX(int x);
	void centerY(int y);

	int _h, _w, _x, _y;
	bool _oMovable;
};