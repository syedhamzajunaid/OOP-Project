#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include <vector>
#include "Point.h"
#include "GameLoop.h"
#include "LTexture.h"
#include "Map.h"
#include "GameObject.h"
//#include "Vehicles.h"
//#include "PlayerVan.h"
#include "Queue.h"
#include "Powerups.h"
#include "SpeedBoost.h"
#include "TimeBoost.h"
#include "Obstacles.h"
#include "RoadBlock.h"
#include "Rubble.h"
#include "FuelBoost.h"
#include "SDL_Dimensions.h"

class PlayerVan;
class Vehicles;

PlayerVan* playervan = NULL;
Queue* objects_queue ;
GameObject* timeboost = NULL ;
SDL_Renderer* GameLoop::grenderer = NULL;
Map *city_map;
Timer GameLoop::timer;

GameLoop::GameLoop()
{}

GameLoop::~GameLoop()
{}


void GameLoop::init(const char* title, int posx, int posy, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen == true)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

	int Screen_Width = dimension::Screen_width();
	int Screen_Height = dimension::Screen_height();

	//Initialize SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		isrunning = false;
	}
	else
    {
        gwindow = SDL_CreateWindow(title, posx, posy, width, height, flags);
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
            isrunning = true;
		}

    }
    objects_queue = new Queue() ;
     city_map = new Map("Assets/Map.png");

	// Generating Powerups and obstacles
    int random = 10 + (rand() % 50) ;
	std::cout << "Random: " << random << std::endl;
	Point* locations = new Point[random];
    playervan = new PlayerVan("Assets/Player.png");
    objects_queue->Enqueue(playervan) ; //Moven't
    int i = 0;
    while (i < random)
    {
        int x = rand() % Screen_Width;
        int y = rand() % Screen_Height;
        Point point;

        if (city_map->PlaceObjects( x, y))
        {
            point.x = x ;
            point.y = y ;

			// To check if not a powerup/obs exist there already.
            if ((GameLoop::is_present(locations,random,point)) == false)
            {
				locations[i] = point ;
				int r = rand() % 6 ;

				// Random generation of powerups/obs
				switch(r)
				{
					case 0:
						timeboost = new TimeBoost("Assets/TimeBoost.png",x,y);
						objects_queue->Enqueue(timeboost);
						std :: cout << "TimeBoost Location: " <<locations[i].x << "," << locations[i].y << std::endl ;
						i++ ;
						break;

                    case 1:
                        timeboost = new FuelBoost("Assets/FuelBoost.png",x,y);
						objects_queue->Enqueue(timeboost);
						std :: cout << "FuelBoost Location: " <<locations[i].x << "," << locations[i].y << std::endl ;
						i++ ;
						break;
					case 2:
						timeboost = new SpeedBoost("Assets/SpeedBoost.png",x,y);
						objects_queue->Enqueue(timeboost);
						//std :: cout << "SpeedBoost Location: " <<locations[i].x << "," << locations[i].y << std::endl ;
						i++ ;
						break;
					case 3:
						timeboost = new RoadBlock("Assets/Obstacles.png",x,y);
						objects_queue->Enqueue(timeboost);
						//std :: cout << "RoadBlock Location: " <<locations[i].x << "," << locations[i].y << std::endl ;
						i++ ;
						break ;
					case 4:
						timeboost = new Rubble("Assets/Rubble2.png",x,y);
						objects_queue->Enqueue(timeboost);
						//std :: cout << "Rubble Location: " <<locations[i].x << "," << locations[i].y << std::endl ;
						i++ ;
						break ;

					default:
						break ;
				}
			}
        }
        else
        {
            continue;
        }
	}
}

void GameLoop::update()
{
    city_map->Update();

}

void GameLoop::handleevents()
{
    SDL_Event e;
    int x, y;
    SDL_GetMouseState( &x, &y );

    while(SDL_PollEvent(&e)!=0)
    {
        if(e.type == SDL_QUIT)
        {
            isrunning = false;
            break;
        }
        else if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            //cout << x << " " << y << endl;
        }
        else
        {

            playervan->Update(e, city_map->blocks);
        }
    }
}

void GameLoop::render()
{
    SDL_RenderClear(grenderer);
    city_map->Render();
    playervan->Render();
	playervan->SetFuel();
    objects_queue->Render();
    this->handleevents(); // Update van
    objects_queue->CollisionManager();
	SDL_RenderPresent(grenderer);
}


// For random position of powerups and obs
bool GameLoop::CheckCollision(SDL_Rect A, SDL_Rect B)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}
	//If none of the sides from A are outside B
	return true;
}


bool GameLoop::is_present(Point* arr, int Size, Point point)
{
	for (int i = 0; i < Size; i++)
	{
		if (arr[i] == point)
			return true;
	}
	return false;
}


void GameLoop::close()
{
    SDL_DestroyWindow(gwindow);
    SDL_DestroyRenderer(grenderer);
    objects_queue->Clean();
    SDL_Quit();
    cout << "game cleaned" << endl;
}



