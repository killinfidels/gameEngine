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
	SDL_Rect zerro;

	zerro.x = 0;
	zerro.y = 0;
	zerro.w = 0;
	zerro.h = 0;

	draw(zerro);
}

void Object::draw(SDL_Rect cam, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderRect;

	renderRect.x = rect.x - cam.x;
	renderRect.y = rect.y - cam.y;
	renderRect.w = cam.w;
	renderRect.h = cam.h;

	if (cam.w == 0)
	{
		renderRect.w = rect.w;
		renderRect.h = rect.h;

		if (sprite)
		{
			SDL_RenderCopyEx(renderer, _texture, &textureRect, &renderRect, angle, center, flip);
		}
		else
		{
			SDL_RenderCopyEx(renderer, _texture, NULL, &renderRect, angle, center, flip);
		}
	}
	else
	{
		if ((renderRect.x + rect.w > 0 && renderRect.x < renderRect.w)
			&& (renderRect.y + rect.h > 0 && renderRect.y < cam.h))
		{
			renderRect.w = rect.w;
			renderRect.h = rect.h;

			if (sprite)
			{
				SDL_RenderCopyEx(renderer, _texture, &textureRect, &renderRect, angle, center, flip);
			}
			else
			{
				SDL_RenderCopyEx(renderer, _texture, NULL, &renderRect, angle, center, flip);
			}
		}
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

	if (!dontSlowDown)
	{
		float minSpeed = 1;
		float slowdown = 0.5;

		if (velocity_y > 0)
			if (velocity_y < minSpeed)
				velocity_y = 0;
			else
				velocity_y = velocity_y - slowdown;

		if (velocity_y < 0)
			if (velocity_y > -minSpeed)
				velocity_y = 0;
			else
				velocity_y = velocity_y + slowdown;


		if (velocity_x > 0)
			if (velocity_x < minSpeed)
				velocity_x = 0;
			else
				velocity_x = velocity_x - slowdown;

		if (velocity_x < 0)
			if (velocity_x > -minSpeed)
				velocity_x = 0;
			else
				velocity_x = velocity_x + slowdown;
	}
}

Object::~Object()
{
	/*SDL_DestroyTexture(_texture);
	_texture = NULL;*/
}