#include "../header-files/object.h"

Object::Object(int w, int h, WindowM* _window)
{
	rect.h = h;
	rect.w = w;

	window = _window->getWindow();
	renderer = _window->getRenderer();
}

Object::Object()
{
	rect.h = 0;
	rect.w = 0;
	rect.y = 0;
	rect.x = 0;
}

void Object::setRenderer(SDL_Renderer* _renderer)
{
	renderer = _renderer;
}

void Object::draw()
{
	if (sprite)
	{
		SDL_RenderCopy(renderer, _texture, &textureRect, &rect);
	}
	else
	{
		SDL_RenderCopy(renderer, _texture, NULL, &rect);
	}
	
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

void Object::clearTexture()
{
	_texture = NULL;
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
	velocity_y = 0;
}

void Object::updateMovement()
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

	/*
	if (!dontSlowDown)
	{
		if (velocity_x > 0) { velocity_x = velocity_x - 0.1; }
		else if (velocity_x < 0) { velocity_x = velocity_x + 0.1; }

		if (velocity_y > 0.1) { velocity_y = velocity_y - 0.1; }
		else if (velocity_y < -0.1) { velocity_y = velocity_y + 0.1; }
		else velocity_y = 0;
	}
	*/
}

Object::~Object()
{
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}