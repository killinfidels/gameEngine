#include "../header-files/gamemap.h"

GameMap::GameMap(int mapW, int mapH, int tileX, int tileY)
{
    w = mapW;
    h = mapH;

    tileMap.resize(w);
    tileMapId.resize(w);

    for(int i = 0; i < w; i++)
    {
        tileMap[i].resize(h);
        tileMapId[i].resize(h);
    }
}

GameMap::~GameMap() {}

void GameMap::setRenderer(SDL_Renderer* _renderer)
{ renderer = _renderer; }

void GameMap::setCamXY(int _camX, _camY)
{ camX = _camX; camY = _camY; }

void GameMap::setTileTextures(std::string tilePath)
{
    countingTexture.setRenderer(renderer);

    path = tilePath + "/";

	//count number of tiles -- tileN
	bool picsLeft = true;
	do
	{
		if (countingTexture.createTexture(path + std::to_string(tileN) + ".png"))
		{
			tileN++;
		}
		else
		{
			picsLeft = false;
		}
	} while (picsLeft);

    tileTextures.resize(tileN);

	//store them in vector -- tileTextures
	for (int i = 0; i < tileN; i++)
	{
		tileTextures[i].setRenderer(renderer);

		std::cout << "loading tile: " << path + std::to_string(i) + ".png" << std::endl;
		tileTextures[i].createTexture(path + std::to_string(i) + ".png");
	}
}

void GameMap::createMap()
{
    for (int i = 0; i < w; i++)
    {
        int yObjectPos = camY;
        for (int b = 0; b < h; b++)
        {
            Object[i][b].setRenderer(renderer);

            if (tileMapId[i][b] < 0 && tileMapId[i][b] >= tileN)
            {
                printf("the tile is not valid:", tileMapId[i][b])
                Object[i][b].clearTexture();
            }
            else 
            {
                Object[i][b].setTexture(tileTextures[tileMapId[i][b]].getTexture());
            }
        }
    }

    printf("map created, ready for rendering\n");
}