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
{ 
	camX = _camX;
	camY = _camY;
	
	int yObjectPos = camY;

	for (int hhh = 0; hhh < h; hhh++)
	{
		int xObjectPos = camX;

		for (int www = 0; www < w; www++)
		{
			tileMap[hhh][www].rect.x = xObjectPos;
			xObjectPos = xObjectPos + tW;

			tileMap[hhh][www].rect.y = yObjectPos;
		}

		yObjectPos = yObjectPos + tH;
	}
}

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
			if (sheet)
			{
				tileMap[hhh][www].setTexture(tilesTexture.getTexture());
				tileMap[hhh][www].textureRect = tileRects[tileMapId[hhh][www]];
				tileMap[hhh][www].sprite = true;
			}
			else
			{
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

void GameMap::drawMap(SDL_Rect cam)
{
	for (int hhh = 0; hhh < h; hhh++)
		for (int www = 0; www < w; www++)
			tileMap[hhh][www].draw(cam);
}

void GameMap::setTileMap(std::vector<std::vector<int>> _tileMap)
{
	for (int hhh = 0; hhh < h; hhh++)
		for (int www = 0; www < w; www++)
			tileMapId[hhh][www] = _tileMap[hhh][www];
}

void GameMap::setMapFromFile(std::string mapPath)
{

}

void GameMap::setTilesTexture(std::string tilePath)
{
	sheet = true;

	int tileSheetWidth, tileSheetHeight;
	int tileTextureWidth, tileTextureHeight;
	int tileSheetColumns, tileCount;

	std::ifstream tilefile;
	std::string line;

	tilesTexture.setRenderer(renderer);
	tilesTexture.createTexture(tilePath + ".png");

	tilefile.open(tilePath + ".tsx", std::ios::in);

	if (!tilefile.is_open())
	{
		printf("could not open tile file:", tilePath + ".tsx");
	}
	else
	{
		while (std::getline(tilefile, line))
		{
			int pos;
			std::string number;

			pos = line.find("tilewidth");
			if (pos != std::string::npos)
			{
				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				tileTextureWidth = std::stoi(number);
			}

			pos = line.find("tileheight");
			if (pos != std::string::npos)
			{
				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				tileTextureHeight = std::stoi(number);
			}

			pos = line.find("tilecount");
			if (pos != std::string::npos)
			{
				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				tileCount = std::stoi(number);
			}

			pos = line.find("columns");
			if (pos != std::string::npos)
			{
				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				tileSheetColumns = std::stoi(number);
			}

			pos = line.find("image source");
			if (pos != std::string::npos)
			{
				pos = line.find("width");
				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				tileSheetWidth = std::stoi(number);

				pos = line.find("height");
				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				tileSheetHeight = std::stoi(number);
			}
		}

		tilefile.close();

		int tilesPerColumn = tileSheetWidth / tileTextureWidth;

		int tilesSet = 0;

		tileRects.resize(tileCount);

		for (int cols = 0; cols < tileSheetColumns; cols++)
		{
			for (int tiles = 0; tiles < tilesPerColumn; tiles++)
			{
				tileRects[tilesSet].x = tileTextureWidth * tiles;
				tileRects[tilesSet].y = tileTextureHeight * cols;
				tileRects[tilesSet].w = tileTextureWidth;
				tileRects[tilesSet].h = tileTextureHeight;

				tilesSet++;

				if (tilesSet == tileCount)
				{
					tiles = tilesPerColumn;
					cols = tileSheetColumns;
				}
			}
		}
	}
}

CollisionObjects::CollisionObjects(std::string name, std::string path)
{
	std::ifstream tilefile;
	std::string line;
	bool layerFound = false;

	tilefile.open(path, std::ios::in);

	if (!tilefile.is_open())
	{
		printf("could not open tile file:", path);
	}
	else
	{
		while (std::getline(tilefile, line))
		{
			int pos;
			std::string number;

			pos = line.find(name);
			if (pos != std::string::npos)
			{
				layerFound = true;
			}

			pos = line.find("x");
			if (pos != std::string::npos && layerFound)
			{
				objAmount++;
				collisObject.resize(objAmount);

				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				collisObject[objAmount - 1].rect.x = std::stoi(number);


				pos = line.find("y");

				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				collisObject[objAmount - 1].rect.y = std::stoi(number);


				pos = line.find("width");

				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				collisObject[objAmount - 1].rect.w = std::stoi(number);


				pos = line.find("height");

				pos = line.find("\"", pos) + 1;

				number = line.substr(pos, line.find("\"", pos) - pos);

				collisObject[objAmount - 1].rect.h = std::stoi(number);
			}
		}

		tilefile.close();
	}
}

CollisionObjects::~CollisionObjects()
{
}