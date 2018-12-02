#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

//Texture wrapper class
class LTexture
{
private:
    int width, height ;

    public:
        LTexture();
        ~LTexture();

    static SDL_Texture* LoadTexture(const char*);
};
