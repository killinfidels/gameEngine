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

void _player::move(directions _direction)
{
	direction = _direction;

	switch (direction)
	{
	case _player::UP:
		velocity_y = velocity_y - speed;
		break;
	case _player::DOWN:
		velocity_y = velocity_y + speed;
		break;
	case _player::LEFT:
		velocity_x = velocity_x - speed;
		break;
	case _player::RIGHT:
		velocity_x = velocity_x + speed;
		break;

	default:
		break;
	}
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
	pRect.x = pRect.x + velocity_x;
	
	pRect.y = pRect.y + velocity_y;

	slowDown('b');
}

void _player::collision(SDL_Rect oRect, bool inside)
{
	//keeps the player inside the desired object
	if (inside)
	{
		//left side collision
		if (pRect.x < oRect.x)
		{
			stopX(oRect.x);
		}
		//right side collision
		if ((pRect.x + pRect.w) > (oRect.x + oRect.w))
		{
			stopX(oRect.x + oRect.w - pRect.w);
		}
		//top side collision
		if (pRect.y < oRect.y)
		{
			stopY(oRect.y);
		}
		//bottom side collision
		if ((pRect.y + pRect.h) > (oRect.y + oRect.h))
		{
			stopY(oRect.y + oRect.h - pRect.h);
		}
	}
	else //keeps the player from going inside the desired object
	{
		//x cordinate collisions
		if (direction == LEFT || direction == RIGHT)
		{
			//if the player is in the correct y position to make a collision
			if ((pRect.y + pRect.h) > oRect.y && pRect.y < (oRect.y + oRect.h))
			{
				//left side of the object
				if (direction == RIGHT && ((pRect.x + pRect.w) > oRect.x && (pRect.x + pRect.w) < (oRect.x + oRect.w)))
				{
					stopX(oRect.x - pRect.w);
				}
				//right side of the object
				if (direction == LEFT && (pRect.x < (oRect.x + oRect.w) && pRect.x > oRect.x))
				{
					stopX(oRect.x + oRect.w);
				}
			}
		}
		//y cordinate collisions
		else if (direction == DOWN || direction == UP)
		{
			//if the player is in the correct x position to make a collision
			if ((pRect.x + pRect.w) > oRect.x && pRect.x < (oRect.x + oRect.w))
			{
				//top side of the object
				if (direction == DOWN && ((pRect.y + pRect.h) > oRect.y && (pRect.y + pRect.h) < (oRect.y + oRect.h)))
				{
					stopY(oRect.y - pRect.h);
				}
				//bottom side of the object
				if (direction == UP && (pRect.y < (oRect.y + oRect.h) && pRect.y > oRect.y))
				{
					stopY(oRect.y + oRect.h);
				}
			}
		}
	}
}

//puts pRect.x in received x cordinate and sets velocity_x to 0
void _player::stopX(int x)
{
	pRect.x = x;
	velocity_x = 0;
}

//puts pRect.y in received y cordinate and sets velocity_y to 0
void _player::stopY(int y)
{
	pRect.y = y;
	velocity_y = 0;
}