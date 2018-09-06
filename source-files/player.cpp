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