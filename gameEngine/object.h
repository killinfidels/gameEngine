#pragma once
#include "Header.h"

class object
{
public:
	object(int h, int w, bool movable);
	~object();

	object(object&&) = default;

	void render(SDL_Renderer* renderer, int x, int y);

	bool setTexture(SDL_Texture* oTexture);

	SDL_Rect oRect;
private:

	bool ERRORED = false;

	SDL_Texture* _texture;

	int speed;
	int maxSpeed;

	int velocity_x;
	int velocity_y;

	/*
	void centerX(int x);
	void centerY(int y);
	*/

	bool _moveable;
};