#include "player.h"

_player::_player(int x, int y, int w, int h)
{
	//center player
	_x = x - (w / 2);
	_y = y - (h / 2);

	pRect.x = _x;
	pRect.y = _y;
	pRect.w = w;
	pRect.h = h;
}

_player::~_player()
{
	//SDL_DestroyTexture(_oTexture);
	//_oTexture = NULL;
}

void _player::moveUp()
{
	velocity_y = velocity_y - speed;
}

void _player::moveDown()
{
	velocity_y = velocity_y + speed;
}

void _player::moveLeft()
{
	velocity_x = velocity_x - speed;
}

void _player::moveRight()
{
	velocity_x = velocity_x + speed;
}

void _player::slowDown(char s)
{
	switch (s)
	{
	case 'x':

		if (velocity_x > 0) { velocity_x--; }
		else if (velocity_x < 0) { velocity_x++; }

		break;

	case 'y':

		if (velocity_y > 0) { velocity_y--; }
		else if (velocity_y < 0) { velocity_y++; }

		break;

	case 'b':

		if (velocity_x > 0) { velocity_x--; }
		else if (velocity_x < 0) { velocity_x++; }

		if (velocity_y > 0) { velocity_y--; }
		else if (velocity_y < 0) { velocity_y++; }

		break;

	default:
		break;
	}

	if (velocity_x > maxSpeed)
	{
		velocity_x = maxSpeed;
	}
	if (velocity_x < -maxSpeed)
	{
		velocity_x = -maxSpeed;
	}
	if (velocity_y > maxSpeed)
	{
		velocity_y = maxSpeed;
	}
	if (velocity_y < -maxSpeed)
	{
		velocity_y = -maxSpeed;
	}
}

void _player::update()
{
	if (pRect.x > 0 && (pRect.x + pRect.w) < screen_width)
	{
		pRect.x = pRect.x + velocity_x;
	}
	else if (pRect.x <= 0 && velocity_x > 0)
	{
		pRect.x = pRect.x + velocity_x;
	}
	else if ((pRect.x + pRect.w) >= screen_width && velocity_x < 0)
	{
		pRect.x = pRect.x + velocity_x;
	}

	if (pRect.y > 0 && (pRect.y + pRect.h) < screen_height)
	{
		pRect.y = pRect.y + velocity_y;
	}
	else if (pRect.y <= 0 && velocity_y > 0)
	{
		pRect.y = pRect.y + velocity_y;
	}
	else if ((pRect.y + pRect.h) >= screen_height && velocity_y < 0)
	{
		pRect.y = pRect.y + velocity_y;
	}

	if (pRect.x <= 0 && velocity_x < 0)
	{
		pRect.x = 0;
		velocity_x = 0;
	}
	else if ((pRect.x + pRect.w) >= screen_width && velocity_x > 0)
	{
		pRect.x = screen_width - pRect.w;
		velocity_x = 0;
	}

	if (pRect.y <= 0 && velocity_y < 0)
	{
		pRect.y = 0;
		velocity_y = 0;
	}
	else if ((pRect.y + pRect.h) >= screen_height && velocity_y > 0)
	{
		pRect.y = screen_height - pRect.h;
		velocity_y = 0;
	}

	_player::slowDown('b');
}

void _player::collision(SDL_Rect _oRect)
{
	if (pRect.y <= (_oRect.y + _oRect.h) && !(pRect.y <= _oRect.y) && !((pRect.x + pRect.w) < _oRect.x || pRect.x > (_oRect.x + _oRect.w)))
	{
		pRect.y = (_oRect.y + _oRect.h);
		velocity_y = 0;
	}
	else if ((pRect.y + pRect.h) >= _oRect.y && !(pRect.y >= _oRect.y) && !((pRect.x + pRect.w) < _oRect.x || pRect.x > (_oRect.x + _oRect.w)))
	{
		pRect.y = (_oRect.y - pRect.h);
		velocity_y = 0;
	}
}