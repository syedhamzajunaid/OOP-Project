#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "GameLoop.h"
#include "Map.h"

using namespace std;
GameLoop *game = NULL;


int main(int argc, char *argv[])
{
    game = new GameLoop();
    game->init("Please work", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    while(game->is_running())
    {
        game->handleevents();
        game->update();
        game->render();
    }
    game->close();
    delete [] game;
    game = NULL;

    return 0;
}
