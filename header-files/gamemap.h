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

    void createMap();

    void drawMap();

    void setCamXY(int _camX, _camY);

private:
    std::string path;

    std::vector<std::vector<int>> tileMapId;
    std::vector<std::vector<Object>> tileMap;
    
    Texture countingTexture;

    std::vector<Texture> tileTextures;

    SDL_Renderer* renderer = NULL;

    int tileN = 0;
    int w, h, x, y;
    int camX = 0, camY = 0;
}