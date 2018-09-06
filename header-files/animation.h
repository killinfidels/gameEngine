#pragma once
#include "basics.h"
#include "texture.h"
#include "storage.h"

class Animation
{
public:
	Animation(std::string _name, std::string _path, WindowM* _window);
	~Animation();

	void getFrameTime();
	void setFrameTime(int spot, int value);

	SDL_Texture* play();

private:

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	bool animationStart = false;
	Uint32 tStart = 0;
	Uint32 tMark = 0;
	int currentFrame = 0;
	int frameN = 0;

	Texture countingTexture;

	std::string path;
	std::string name;
	std::string dataPath;
	std::vector<Texture> frames;
	std::vector<int> frameTimes;
};