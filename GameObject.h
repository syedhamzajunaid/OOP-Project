#pragma once
#include "GameLoop.h"

class GameObject
{
    public:
        GameObject(const char* spritesheet);
        ~GameObject();
        void Update();
        void Render();


    protected:
        int xpos, ypos;
        SDL_Texture* objTexture;
        SDL_Rect srcrect, destrect;

};


