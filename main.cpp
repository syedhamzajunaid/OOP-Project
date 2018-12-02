#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GameLoop.h"
#include "Map.h"
#include "SDL_Dimensions.h"

using namespace std;
GameLoop *game = NULL;

int main(int argc, char *argv[])
{

	srand(time(NULL));
    game = new GameLoop();
	int w = dimension::Screen_width();
	int h = dimension::Screen_height();
    game->init("Van with a plan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,w,h,false);
    game->m_render = true;

    while(game->is_running())
    {
        game->render();

    }
    game->update();

    game->close();

    return 0;
}
