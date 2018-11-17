#ifndef MAP_H
#define MAP_H
#include "GameLoop.h"

class Map
{
    public:
        Map(const char* spritesheet);
        ~Map();
        void Update();
        void Render();


    protected:
        int xpos, ypos;
        SDL_Texture* map_texture;
        SDL_Rect srcrect, destrect;

};
/*
{
    public:
        Map();
        ~Map();
        void LoadMap(int map_array[20][25]);
        void DrawMap();

    protected:
        SDL_Rect src, dest;
        SDL_Texture *dirt, *grass, *water;

        int member_map_array[20][25];
};
*/
#endif // MAP_H
