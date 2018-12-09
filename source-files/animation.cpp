#include "../header-files/animation.h"

Animation::Animation(std::string _name, std::string _path, WindowM* _window)
{
	window = _window->getWindow();
	renderer = _window->getRenderer();

	//countingTexture.setRenderer(renderer);

	path = _path + "/";
	name = _name;
	dataPath = path + name + ".txt";

	//count number of frames -- frameN
	bool picsLeft = true;
	do
	{
		std::string temp = path + std::to_string(frameN) + ".png";

		if (IMG_Load(temp.c_str()))
		{
			frameN++;
		}
		else
		{
			picsLeft = false;
		}
	} while (picsLeft);

	std::cout << "there are " << frameN << " frames" << std::endl;

	frames.resize(frameN);
	frameTimes.resize(frameN);

	//store them in vector -- frames
	for (int i = 0; i < frameN; i++)
	{
		frames[i].setRenderer(renderer);

		std::cout << "loading frames: " << path + std::to_string(i) + ".png" << std::endl;
		frames[i].createTexture(path + std::to_string(i) + ".png");
	}

	//create frame time file
	if (!loadData(frameTimes, frameN, &dataPath))
	{
		for (int i = 0; i < frameN; i++)
		{
			frameTimes[i] = 1000;
		}

		createData(frameTimes, frameN, &dataPath);
	}

	std::cout << std::endl;
}

SDL_Texture* Animation::play()
{
	if (!animationStart)
	{
		animationStart = true;
		tStart = SDL_GetTicks();
	}

	if (SDL_GetTicks() - tStart >= frameTimes[currentFrame])
	{
		currentFrame++;
		tStart = SDL_GetTicks();
	}

	if (currentFrame >= frameN)
	{
		animationStart = false;
		currentFrame = 0;
		return NULL;
	}
	else
		return frames[currentFrame].getTexture();
}

void Animation::getFrameTime()
{
	printf("frametimes:\n");
	for (int i = 0; i < frameN; i++)
	{
		std::string s = std::to_string(frameTimes[i]);
		printf(s.c_str());
		printf("\n");
	}
}

void Animation::setFrameTime(int spot, int value)
{
	frameTimes[spot] = value;
	std::cout << "frame: " << spot << "\nframetime: " << value << std::endl;
}

Animation::~Animation()
{
	saveData(frameTimes, frameN, &dataPath);

	/*for (int i = 0; i < frameN; i++)
		frames[i].~Texture();*/
}