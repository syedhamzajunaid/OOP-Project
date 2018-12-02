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
        SDL_Rect *blocks = new SDL_Rect[41];
        bool PlaceObjects(int x, int y);

    protected:
		Point pos;
        SDL_Texture* map_texture;
        SDL_Rect srcrect, destrect;

};
#endif // MAP_H
