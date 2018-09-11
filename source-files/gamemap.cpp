#include "../header-files/gamemap.h"

GameMap::GameMap(int mapW, int mapH, int tileW, int tileH)
{
    w = mapW;
    h = mapH;

	tW = tileW;
	tH = tileH;

    tileMap.resize(h);
    tileMapId.resize(h);

    for(int i = 0; i < h; i++)
    {
        tileMap[i].resize(w);
        tileMapId[i].resize(w);
    }

	for (int hhh = 0; hhh < h; hhh++)
		for (int www = 0; www < w; www++)
		{
			tileMapId[hhh][www] = 0;

			tileMap[hhh][www].rect.w = tW;
			tileMap[hhh][www].rect.h = tH;
		}
			
}

GameMap::~GameMap() {}

void GameMap::setRenderer(SDL_Renderer* _renderer)
{ renderer = _renderer; }

void GameMap::setCamXY(int _camX, int _camY)
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
	int yObjectPos = camY;

    for (int hhh = 0; hhh < h; hhh++)
    {
        int xObjectPos = camX;
		
        for (int www = 0; www < w; www++)
        {
			tileMap[hhh][www].rect.x = xObjectPos;
			xObjectPos = xObjectPos + tW;

			tileMap[hhh][www].rect.y = yObjectPos;

			tileMap[hhh][www].setRenderer(renderer);

            if (tileMapId[hhh][www] < 0 && tileMapId[hhh][www] >= tileN)
            {
				printf("the tile is not valid:", tileMapId[hhh][www]);
                tileMap[hhh][www].clearTexture();
            }
            else 
            {
				tileMap[hhh][www].setTexture(tileTextures[tileMapId[hhh][www]].getTexture());
            }
        }

		yObjectPos = yObjectPos + tH;
    }

    printf("map created, ready for rendering\n");
}

void GameMap::drawMap()
{
	for (int hhh = 0; hhh < h; hhh++)
		for (int www = 0; www < w; www++)
			tileMap[hhh][www].draw();
}

void GameMap::setTileMap(std::vector<std::vector<int>> _tileMap)
{
	for (int hhh = 0; hhh < h; hhh++)
		for (int www = 0; www < w; www++)
			tileMapId[hhh][www] = _tileMap[hhh][www];
}