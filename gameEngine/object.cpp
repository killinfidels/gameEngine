#include "object.h"

Object::Object(int w, int h, bool moveable)
{
	rect.h = h;
	rect.w = w;
}

void Object::render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, _texture, NULL, &rect);
}

bool Object::setTexture(SDL_Texture* texture)
{
	bool success = true;

	_texture = texture;

	if (_texture == NULL)
	{
		printf("couldnt set object texture\n");
		success = false;
	}

	return success;
}

//puts rect.x in received x cordinate and sets velocity_x to 0
void Object::stopX(int x)
{
	rect.x = x;
	velocity_x = 0;
}

//puts rect.y in received y cordinate and sets velocity_y to 0
void Object::stopY(int y)
{
	rect.y = y;
	velocity_y = (velocity_y*-1) - ((velocity_y*-1) / 2);
}

void Object::update()
{
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

	rect.x = rect.x + velocity_x;

	rect.y = rect.y + velocity_y;

	if (!_moveable)
	{
		if (velocity_x > 0) { velocity_x = velocity_x - 0.1; }
		else if (velocity_x < 0) { velocity_x = velocity_x + 0.1; }

		if (velocity_y > 0.1) { velocity_y = velocity_y - 0.1; }
		else if (velocity_y < -0.1) { velocity_y = velocity_y + 0.1; }
		else velocity_y = 0;
	}

	/*
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
	*/
}

Object::~Object()
{
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}