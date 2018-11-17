#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "LTexture.h"
#include "GameObject.h"
using namespace std;
class GameLoop
{
    public:
        GameLoop();
        ~GameLoop();

        void init(const char*, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleevents();
        void update();
        void render();
        void close();
        bool is_running() {return isrunning;}

        static SDL_Renderer *grenderer;

    public:
        bool isrunning;
        SDL_Window *gwindow;
};

