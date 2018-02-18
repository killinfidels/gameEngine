#pragma once
#include "basics.h"

class Texture
{
public:

	Texture(){}

	Texture(SDL_Renderer* renderer, std::string path);
	
	~Texture();

	bool createTexture(SDL_Renderer* renderer, std::string path);

	bool createTextureFromText(SDL_Renderer* renderer, TTF_Font* font, std::string path, SDL_Color color);

	SDL_Texture* getTexture();

private:
	SDL_Surface* surface;
	SDL_Texture* texture;

	std::string _path;
};