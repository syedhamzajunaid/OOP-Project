#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

//Texture wrapper class
class LTexture
{
    public:
        LTexture();
        ~LTexture();

        static SDL_Texture* LoadTexture(const char*);
        static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};
