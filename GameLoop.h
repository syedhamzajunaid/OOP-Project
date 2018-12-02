#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "LTexture.h"
//#include "GameObject.h"
#include "Point.h"
#include "Timer.h"
#include "GameObject.h"

class PlayerVan ;
//class GameObject;
using namespace std;
class GameLoop
{
    public:
        GameLoop();
        ~GameLoop();
        static PlayerVan* playervan ;
        //static PlayerVan player;
        static bool CheckCollision(SDL_Rect A, SDL_Rect B);
        void init(const char*, int posx, int posy, int width, int height, bool fullscreen);
        void handleevents();
        void update();
        void render();
        void close();
        bool is_running() {return isrunning;}

        static SDL_Renderer* grenderer;
		static Timer timer;
        static bool is_present(Point* arr,int Size,Point point) ;

    public:
        bool isrunning;
        bool m_render;
        SDL_Window *gwindow;
};

