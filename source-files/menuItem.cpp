#include "../header-files/menuItem.h"

MenuItem::MenuItem(int x, int y, int w, int h, WindowM* _window) : Object(w, h, _window)
{
	rect.x = x;
	rect.y = y;
}

void MenuItem::setTextures(SDL_Texture* notPressedTexture, SDL_Texture* pressedTexture)
{
	pressed = pressedTexture;
	notPressed = notPressedTexture;

	setTexture(notPressed);
}

void MenuItem::eventHandler(SDL_Event* e)
{
	if (e->window.windowID == SDL_GetWindowID(window))
	{
		if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
		{
			SDL_GetMouseState(&mouseX, &mouseY);

			if (!(mouseX > rect.x && mouseX < rect.x + rect.w && mouseY > rect.y && mouseY < rect.y + rect.h))
				clicked = false;
			else if (e->type != SDL_MOUSEBUTTONDOWN)
				clicked = false;
			else
				clicked = true;
		}
		else
		{
			clicked = false;
		}
	}
}

bool MenuItem::activated()
{
	if (clicked)
	{
		setTexture(pressed);
	}

	return clicked;
}

MenuItem::~MenuItem()
{
	SDL_DestroyTexture(pressed);
	pressed = NULL;
	SDL_DestroyTexture(notPressed);
	notPressed = NULL;
}