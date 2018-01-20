#pragma once
#include "Header.h"

class myTexture
{
public:
	myTexture(SDL_Renderer* renderer, std::string path);
	~myTexture();

	SDL_Surface* surface;
	SDL_Texture* texture;

private:
	std::string _path;
};