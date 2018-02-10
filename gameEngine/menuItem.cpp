#include "menuItem.h"

menuItem::menuItem(int x, int y, int w, int h): mObject(w, h, false)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	mObject.rect.x = x;
	mObject.rect.y = y;
}

void menuItem::mouseStuff(SDL_Event* e)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_GetMouseState(&mouseX, &mouseY);

		if (!(mouseX > rect.x && mouseX < (rect.x + rect.w) && mouseY > rect.y && mouseY < (rect.y + rect.h)))
		{
			pressed = false;
		}
		else if (e->type != SDL_MOUSEBUTTONDOWN)
		{
			pressed = false;
		}
		else
		{
			pressed = true;
		}
	}

	if (pressed)
	{
		mObject.setTexture(tPressed);
	}
	else
	{
		mObject.setTexture(tNotPressed);
	}
}

void menuItem::setTextures(SDL_Texture* pressed, SDL_Texture* notPressed)
{
	tPressed = pressed;
	tNotPressed = notPressed;
}

menuItem::~menuItem()
{
	mObject.~object();

	SDL_DestroyTexture(tPressed);
	tPressed = NULL;
	SDL_DestroyTexture(tNotPressed);
	tNotPressed = NULL;
}