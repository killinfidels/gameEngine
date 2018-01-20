#include "texture.h"

myTexture::myTexture(SDL_Renderer* renderer, std::string path)
{
	std::string _path = path;

	surface = IMG_Load(_path.c_str());

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (texture == NULL)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
		printf("failed to load image:\n");
	}
}

myTexture::~myTexture()
{
	surface = NULL;

	SDL_DestroyTexture(texture);
	texture = NULL;
}