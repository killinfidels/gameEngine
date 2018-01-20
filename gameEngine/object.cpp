#include "object.h"

object::object(int h, int w, bool moveable)
{
	_texture = NULL;

	_moveable = moveable;
	
	rect.h = h;
	rect.w = w;
	rect.x = 0;
	rect.y = 0;
}

void object::render(SDL_Renderer* renderer, int x, int y)
{
	/* OLD STUFF
	if (x == NULL || y == NULL)
	{
		if (!ERRORED)
		{
			printf("invalid cordinations, rendering object at 0, 0 \n");
			ERRORED = true;
		}

		oRect.x = NULL;
		oRect.y = NULL;
	}
	else
	{
		centerX(x);
		centerY(y);

		oRect.x = _x;
		oRect.y = _y;
	}
	*/

	rect.x = x;
	rect.y = y;

	SDL_RenderCopy(renderer, _texture, NULL, &rect);
}

bool object::setTexture(SDL_Texture* texture)
{
	bool success = true;

	_texture = texture;

	if (_texture == NULL)
	{
		printf("couldnt set object texture");
		success = false;
	}

	return success;
}

/*
void object::centerX(int x)
{
	_x = x - (_w / 2);
}

void object::centerY(int y)
{
	_y = y - (_h / 2);
}
*/

object::~object()
{
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}