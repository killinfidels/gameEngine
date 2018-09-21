#include "../header-files/texture.h"

Texture::Texture(std::string path, WindowM* _window)
{
	renderer = _window->getRenderer();

	createTexture(path);
}

void Texture::setRenderer(SDL_Renderer* _renderer)
{
	renderer = _renderer;
}

bool Texture::createTexture(std::string path)
{
	surface = IMG_Load(path.c_str());

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (texture == NULL)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
		printf("failed to load image: %s\n", path.c_str());

		return false;
	}

	return true;
}

bool Texture::createTextureFromText(TTF_Font* font, std::string path, SDL_Color color)
{

	surface = TTF_RenderText_Solid(font, path.c_str(), color);

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (texture == NULL)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
		printf("failed to load image:\n", path);

		return false;
	}

	return true;
}

SDL_Texture* Texture::getTexture()
{
	return texture;
}

Texture::~Texture()
{
	//TTF_CloseFont(_font);

	SDL_FreeSurface(surface);
	surface = NULL;
	SDL_DestroyTexture(texture);
	texture = NULL;
}