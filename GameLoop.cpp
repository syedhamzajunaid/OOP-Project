#include "GameLoop.h"
#include "LTexture.h"
#include "Map.h"

GameObject *playervan;
Map *level;
SDL_Renderer* GameLoop::grenderer = NULL;



GameLoop::GameLoop()
{
    isrunning = true;
}

GameLoop::~GameLoop()
{}

void GameLoop::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen == true)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

	//Initialize SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		isrunning = false;
	}
	else
    {
        gwindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if( gwindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			isrunning = false;
		}
		else
		{
			grenderer = SDL_CreateRenderer(gwindow, -1, 0);
			if(grenderer == NULL)
            {
                printf( "Renderer could not be created! %s\n", SDL_GetError() );
            }
            else
            {
                SDL_SetRenderDrawColor(grenderer, 255, 255, 255, 255);
            }
		}

    }
    //Texture = new LTexture();
    playervan = new GameObject("Assets/Player.png");
    level = new Map("Assets/Map.png");
//    Texture.LoadFromFile("Assets/Player.png",grenderer);
//    playervan = Texture.get_texture();

}

void GameLoop::handleevents()
{
    SDL_Event event;
    while(isrunning)
    {
        if(event.type == SDL_QUIT)
        {
            isrunning = false;
            break;
        }
        else
        {
            break;
        }

    }
}

void GameLoop::update()
{
    playervan->Update();
    level->Update();
}

void GameLoop::render()
{
    SDL_RenderClear(grenderer);
    level->Render();
    playervan->Render();
    SDL_RenderPresent(grenderer);
}

void GameLoop::close()
{
    SDL_DestroyWindow(gwindow);
    SDL_DestroyRenderer(grenderer);
    SDL_Quit();
    cout << "game cleaned" << endl;
}
