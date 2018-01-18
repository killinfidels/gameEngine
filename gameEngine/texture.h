#pragma once
#include "Header.h"

class _texture
{
public:
	_texture(SDL_Renderer* renderer, std::string path);
	~_texture();

	SDL_Surface* surface;
	SDL_Texture* texture;

private:
	std::string _tPath;
};