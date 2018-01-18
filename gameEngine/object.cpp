#include "object.h"

_object::_object(int h, int w, bool movable)
{
	_oTexture = NULL;

	_oMovable = movable;

	_h = h;
	_w = w;
	_x = NULL;
	_y = NULL;
	
	oRect.h = _h;
	oRect.w = _w;
	oRect.x = _x;
	oRect.y = _y;
}

void _object::render(SDL_Renderer* renderer, int x, int y)
{
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

	SDL_RenderCopy(renderer, _oTexture, NULL, &oRect);
}

bool _object::setTexture(SDL_Texture* oTexture)
{
	bool success = true;

	_oTexture = oTexture;

	if (_oTexture == NULL)
	{
		printf("couldnt set object texture");
		success = false;
	}

	return success;
}

void _object::centerX(int x)
{
	_x = x - (_w / 2);
}

void _object::centerY(int y)
{
	_y = y - (_h / 2);
}

_object::~_object()
{
	SDL_DestroyTexture(_oTexture);
	_oTexture = NULL;
}