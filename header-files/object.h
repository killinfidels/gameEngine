#pragma once
#include "basics.h"
#include "windows.h"

class Object
{
public:
	Object(int w, int h, WindowM* _window);
	Object();
	~Object();

	void draw();

	bool dontSlowDown = true;
	
	void updateMovement();

	void clearTexture();

	void setRenderer(SDL_Renderer* _renderer);

	SDL_Rect rect;

	bool sprite = false;

	SDL_Rect textureRect;

protected:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

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
	
	bool collision(SDL_Rect bekt, bool inside)
	{
		bool col = false;
		if (inside)
		{
			//keeps the player inside the desired object
			if (inside)
			{
				//left side collision
				if (rect.x < bekt.x)
				{
					rect.x = bekt.x;
					col = true;
				}
				//right side collision
				if ((rect.x + rect.w) >(bekt.x + bekt.w))
				{
					rect.x = bekt.w - rect.w;
					col = true;
				}
				//top side collision
				if (rect.y < bekt.y)
				{
					rect.y = bekt.y;
					col = true;
				}
				//bottom side collision
				if ((rect.y + rect.h) >(bekt.y + bekt.h))
				{
					rect.y = bekt.h - rect.h;
					col = true;
				}
			}
		}
		else if (rect.y + rect.h > bekt.y && rect.y < bekt.y + bekt.h)
		{
			if (rect.x > bekt.x && rect.x < bekt.x + bekt.w)
			{
				velocity_x = 0;
				rect.x = bekt.x + bekt.w;
				col = true;
			}

			if (rect.x + rect.w > bekt.x && rect.x + rect.w < bekt.x + bekt.w)
			{
				velocity_x = 0;
				
				rect.x = bekt.x - rect.w;
				col = true;
			}	
		}
		//if the player is in the correct x position to make a collision
		else if ((rect.x + rect.w) > bekt.x && rect.x < (bekt.x + bekt.w))
		{
			//top side of the object
			if ((rect.y + rect.h) > bekt.y && (rect.y + rect.h) < (bekt.y + bekt.h))
			{
				velocity_y = 0;
				rect.y = bekt.y - rect.h;
				col = true;
			}
			//bottom side of the object
			if ((rect.y < (bekt.y + bekt.h) && rect.y > bekt.y))
			{
				velocity_y = 0;
				rect.y = bekt.y + bekt.h;
				col = true;
			}
		}

		return col;
	}
};
