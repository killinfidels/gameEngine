#include "../header-files/player.h"

Player::Player(int x, int y, int w, int h) : Object(w, h, false)
{
	rect.x = x;
	rect.y = y;
}

Player::~Player()
{
}

void Player::move(directions _direction)
{
	direction = _direction;

	switch (direction)
	{
	case Player::UP:
		velocity_y = velocity_y - speed;
		break;
	case Player::DOWN:
		velocity_y = velocity_y + speed;
		break;
	case Player::LEFT:
		velocity_x = velocity_x - speed;
		break;
	case Player::RIGHT:
		velocity_x = velocity_x + speed;
		break;

	default:
		break;
	}
}

void Player::collision(SDL_Rect oRect, bool inside)
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