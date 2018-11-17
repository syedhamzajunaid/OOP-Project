#include "Map.h"
#include "LTexture.h"


Map::Map(const char* spritesheet)
{
    map_texture = LTexture::LoadTexture(spritesheet);
}

Map::~Map()
{}

void Map::Update()
{
    xpos = ypos = 0;
    /*
    srcrect.h = srcrect.w = 100;
    srcrect.x = srcrect.y = 0;

    destrect.x = x
    destrect.y = ypos;
    destrect.w = srcrect.w;
    destrect.h = srcrect.h;
    */
}

void Map::Render()
{
    //SDL_RenderClear(GameLoop::grenderer);
    SDL_RenderCopy(GameLoop::grenderer, map_texture, NULL, NULL);
    //SDL_RenderPresent(GameLoop::grenderer);
}


/*
int lvlone[20][25] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map()
{
    dirt = LTexture::LoadTexture("Assets/dirt.png");
    water = LTexture::LoadTexture("Assets/water.png");
    grass = LTexture::LoadTexture("Assets/grass.png");

    LoadMap(lvlone);
}

Map::~Map()
{
    dirt = NULL;
    water = NULL;
    grass = NULL;
}

void Map::LoadMap(int map_array[20][25])
{
    for(int row = 0; r < 20; row++)
    {
        for(int column = 0; column < 25; column++)
        {
            member_map_array[row][column] = map_array[row][column];
        }
    }
}

void Map::DrawMap()
{
    int type = 0;
    for(int row = 0; r < 20; row++)
        {
            for(int column = 0; column < 25; column++)
            {
                type = member_map_array[row][column];
            }
            switch(type)
            {
            case 0:

            }
        }
}
*/
