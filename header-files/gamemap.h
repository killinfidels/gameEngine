#include "basics.h"
#include "texture.h"
#include "object.h"

class GameMap
{
public:
    GameMap(int mapW, int mapH, int tileW, int tileH);
    ~GameMap();

    void setRenderer(SDL_Renderer* _renderer);

    std::vector<std::vector<int>> getTileMap();
    void setTileMap( std::vector<std::vector<int>> _tileMap);

    void setTileTextures(std::string tilePath);
	void setTilesTexture(std::string tilePath);

    void createMap();

    void drawMap();

    void setCamXY(int _camX, int _camY);

	void setMapFromFile(std::string mapPath);

private:
    std::string path;

    std::vector<std::vector<int>> tileMapId;
    std::vector<std::vector<Object>> tileMap;
    
    Texture countingTexture;

    std::vector<Texture> tileTextures;
	Texture tilesTexture;

	std::vector<SDL_Rect> tileRects;

    SDL_Renderer* renderer = NULL;

	bool sheet = false;

    int tileN = 0;
    int w, h, tW, tH;
    int camX = 0, camY = 0;
};