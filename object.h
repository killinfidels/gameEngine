#pragma once
#include "basics.h"

class Object
{
public:
	Object(int w, int h, bool movable);
	~Object();

	void draw(SDL_Renderer* renderer);

	bool dontSlowDown;
	
	void update();

	SDL_Rect rect;

protected:
	bool ERRORED = false;

	SDL_Texture* _texture;

	float speed = 0.5;
	float maxSpeed = 20;

	double velocity_x = 0;
	double velocity_y = 0;

	double accelleration;

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

	void setVelocityX(double velocity)
	{
		velocity_x = velocity;
		if (velocity_x < 0)
			accelleration = (velocity / 5) * -1;
		else
			accelleration = velocity / 5;

	}
	void setVelocityY(double velocity)
	{
		velocity_y = velocity;
	}
	double getVelocityX()
	{
		return velocity_x;
	}
	double getVelocityY()
	{
		return velocity_y;
	}
	
	int ballCollision(SDL_Rect bekt, bool inside)
	{
		int duck = 0;
		if (inside)
		{
			//keeps the player inside the desired object
			if (inside)
			{
				//left side collision
				if (rect.x < bekt.x)
				{
					duck = 2;
					velocity_x = velocity_x * -1;
					rect.x = bekt.x;
				}
				//right side collision
				if ((rect.x + rect.w) >(bekt.x + bekt.w))
				{
					duck = 1;
					velocity_x = velocity_x * -1;
					rect.x = bekt.w - rect.w;
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
				duck = 3;
				velocity_y = r;
				if (velocity_x < 0)
					velocity_x = velocity_x - accelleration;
				else
					velocity_x = velocity_x + accelleration;
				velocity_x = velocity_x  * -1;
				
				rect.x = bekt.x + bekt.w;
			}

			if (rect.x + rect.w > bekt.x && rect.x + rect.w < bekt.x + bekt.w)
			{
				duck = 3;
				velocity_y = r;
				if (velocity_x < 0)
					velocity_x = velocity_x - accelleration;
				else
					velocity_x = velocity_x + accelleration;
				velocity_x = velocity_x * -1;
				
				rect.x = bekt.x - rect.w;
			}
		}
		return duck;
	}
};
