#pragma once
#include "Header.h"

class Object
{
public:
	Object(int w, int h, bool movable);
	~Object();

	void render(SDL_Renderer* renderer);

	bool _moveable;
	
	void update();

	SDL_Rect rect;

protected:
	bool ERRORED = false;

	SDL_Texture* _texture;

	float speed = 0.5;
	float maxSpeed = 10;

	float velocity_x = 0;
	float velocity_y = 0;

	float accelleration;

	void stopX(int x);
	void stopY(int y);

public:
	bool setTexture(SDL_Texture* oTexture);

	
	void setSpeed(float _speed)
	{
		speed = _speed;
	}
	void setMaxSpeed(float _speed) {
		maxSpeed = _speed;
	}
	float getSpeed()
	{
		return speed;
	}
	float getMaxSpeed()
	{
		return maxSpeed;
	}

	void setVelocityX(float velocity)
	{
		velocity_x = velocity;
		accelleration = velocity / 5;

	}
	void setVelocityY(float velocity)
	{
		velocity_y = velocity;
	}
	float getVelocityX()
	{
		return velocity_x;
	}
	float getVelocityY()
	{
		return velocity_y;
	}
	
	int ballCollision(SDL_Rect bekt, bool inside)
	{
		int i = 0;
		if (inside)
		{
			//keeps the player inside the desired object
			if (inside)
			{
				//left side collision
				if (rect.x < bekt.x)
				{
					i = 2;
					velocity_x = velocity_x * -1;
					rect.x = bekt.x;
					accelleration = accelleration * -1;
				}
				//right side collision
				if ((rect.x + rect.w) >(bekt.x + bekt.w))
				{
					i = 1;
					velocity_x = velocity_x * -1;
					rect.x = bekt.w - rect.w;
					accelleration = accelleration * -1;
				}
				//top side collision
				if (rect.y < bekt.y)
				{
					velocity_y = velocity_y * -1;
					rect.y = bekt.y;
				}
				//bottom side collision
				if ((rect.y + rect.h) >(bekt.y + bekt.h))
				{
					velocity_y = velocity_y * -1;
					rect.y = bekt.h - rect.h;
				}
			}
		}
		else if (rect.y + rect.h > bekt.y && rect.y < bekt.y + bekt.h)
		{
			float r = 0;
			
			float middle = 2;

			while (r < middle && r > -middle)
			{
				r = (rand() / (float)RAND_MAX * 10) - 5;
			}

			if (rect.x > bekt.x && rect.x < bekt.x + bekt.w)
			{
				velocity_y = r;
				velocity_x = (velocity_x + accelleration ) * -1;
				accelleration = accelleration * -1;
				rect.x = bekt.x + bekt.w;
			}

			if (rect.x + rect.w > bekt.x && rect.x + rect.w < bekt.x + bekt.w)
			{
				velocity_y = r;
				velocity_x = (velocity_x + accelleration) * -1;
				accelleration = accelleration * -1;
				rect.x = bekt.x - rect.w;
			}
		}
		return i;
	}
};
