#ifndef MAP_H
#define MAP_H
#include "GameLoop.h"
#include "Point.h"

class Map
{
    public:
        Map(const char* spritesheet, int, int);
        ~Map();
        void Update();
        void Render();
        bool PlaceObjects(int x, int y);
        SDL_Rect *blocks = new SDL_Rect[41];
        SDL_Rect *nodes = new SDL_Rect[71];
        int adj_matrix[71][71] = {{0}};

    protected:
		Point pos;
        SDL_Texture* map_texture;
        SDL_Rect srcrect, destrect;

};
#endif // MAP_H
