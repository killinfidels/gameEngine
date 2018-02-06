#pragma once
#include "Header.h"

class Texture
{
public:
	Texture(SDL_Renderer* renderer, std::string path);
	~Texture();

	SDL_Surface* surface;
	SDL_Texture* texture;

private:
	std::string _path;
};