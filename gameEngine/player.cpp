#include "player.h"

player::player(int x, int y, int w, int h)
{
	//center player
	rect.x = x - (w / 2);
	rect.y = y - (h / 2);
	rect.w = w;
	rect.h = h;
}

player::~player()
{
	//SDL_DestroyTexture(_oTexture);
	//_oTexture = NULL;
}

void player::move(directions _direction)
{
	direction = _direction;

	switch (direction)
	{
	case player::UP:
		velocity_y = velocity_y - speed;
		break;
	case player::DOWN:
		velocity_y = velocity_y + speed;
		break;
	case player::LEFT:
		velocity_x = velocity_x - speed;
		break;
	case player::RIGHT:
		velocity_x = velocity_x + speed;
		break;

	default:
		break;
	}
}

void player::slowDown(char s)
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

void player::update()
{
	rect.x = rect.x + velocity_x;
	
	rect.y = rect.y + velocity_y;

	slowDown('b');
}

void player::collision(SDL_Rect oRect, bool inside)
{
	//keeps the player inside the desired object
	if (inside)
	{
		//left side collision
		if (rect.x < oRect.x)
		{
			stopX(oRect.x);
		}
		//right side collision
		if ((rect.x + rect.w) > (oRect.x + oRect.w))
		{
			stopX(oRect.x + oRect.w - rect.w);
		}
		//top side collision
		if (rect.y < oRect.y)
		{
			stopY(oRect.y);
		}
		//bottom side collision
		if ((rect.y + rect.h) > (oRect.y + oRect.h))
		{
			stopY(oRect.y + oRect.h - rect.h);
		}
	}
	else //keeps the player from going inside the desired object
	{
		//x cordinate collisions
		if (direction == LEFT || direction == RIGHT)
		{
			//if the player is in the correct y position to make a collision
			if ((rect.y + rect.h) > oRect.y && rect.y < (oRect.y + oRect.h))
			{
				//left side of the object
				if (direction == RIGHT && ((rect.x + rect.w) > oRect.x && (rect.x + rect.w) < (oRect.x + oRect.w)))
				{
					stopX(oRect.x - rect.w);
				}
				//right side of the object
				if (direction == LEFT && (rect.x < (oRect.x + oRect.w) && rect.x > oRect.x))
				{
					stopX(oRect.x + oRect.w);
				}
			}
		}
		//y cordinate collisions
		else if (direction == DOWN || direction == UP)
		{
			//if the player is in the correct x position to make a collision
			if ((rect.x + rect.w) > oRect.x && rect.x < (oRect.x + oRect.w))
			{
				//top side of the object
				if (direction == DOWN && ((rect.y + rect.h) > oRect.y && (rect.y + rect.h) < (oRect.y + oRect.h)))
				{
					stopY(oRect.y - rect.h);
				}
				//bottom side of the object
				if (direction == UP && (rect.y < (oRect.y + oRect.h) && rect.y > oRect.y))
				{
					stopY(oRect.y + oRect.h);
				}
			}
		}
	}
}

//puts rect.x in received x cordinate and sets velocity_x to 0
void player::stopX(int x)
{
	rect.x = x;
	velocity_x = 0;
}

//puts rect.y in received y cordinate and sets velocity_y to 0
void player::stopY(int y)
{
	rect.y = y;
	velocity_y = 0;
}