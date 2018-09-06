#pragma once
#include "basics.h"
#include "windows.h"

class Texture
{
public:

	Texture(){}

	Texture(std::string path, WindowM* _window);
	
	~Texture();

	void setRenderer(SDL_Renderer* _renderer);

	bool createTexture(std::string path);

	bool createTextureFromText(TTF_Font* font, std::string path, SDL_Color color);

	SDL_Texture* getTexture();

private:
	SDL_Surface* surface;
	SDL_Texture* texture;

	SDL_Renderer* renderer;

	std::string _path;
};