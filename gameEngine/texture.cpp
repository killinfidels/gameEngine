#include "texture.h"

Texture::Texture(SDL_Renderer* renderer, std::string path)
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

Texture::~Texture()
{
	surface = NULL;

	SDL_DestroyTexture(texture);
	texture = NULL;
}