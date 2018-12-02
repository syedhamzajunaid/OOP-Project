#include "GameObject.h"
#include "GameLoop.h"
#include "Map.h"

GameObject::GameObject(){}

GameObject::~GameObject()
{
    SDL_DestroyTexture(objTexture);
    objTexture = NULL;
    std::cout << "Game Object destroyed." << std::endl;
    destrect = {0,0,0,0};
}


void GameObject::Render()
{
	// Renders all objects on screen
	SDL_RenderCopyEx(GameLoop::grenderer, objTexture,NULL, &destrect, angle, NULL, SDL_FLIP_NONE);
}

bool GameObject::check_collision(SDL_Rect B, SDL_Rect A)
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


void GameObject::Update(SDL_Event e, SDL_Rect* blocks)
{
    if(e.key.keysym.sym == SDLK_LEFT)
    {
        if(angle != -90)
        {
            angle = -90;
        }
        pos.x = pos.x - 2;
        destrect.x = pos.x;
        for(int i = 0; i < 41; i++)
        {
            if(check_collision(blocks[i], destrect))
            {
                collision = true;
                break;
            }
        }
        if (collision)
        {
            pos.x = pos.x + 2;
            destrect.x = pos.x;
            collision = false;
        }
    }

   else if(e.key.keysym.sym == SDLK_RIGHT)
    {
        if(angle != 90)
        {
            angle = 90;
        }
        pos.x = pos.x + 2;
        destrect.x = pos.x;
        for(int i = 0; i < 41; i++)
        {
            if(check_collision(blocks[i], destrect))
            {
                collision = true;
                break;
            }
        }
        if(collision)
        {
            pos.x = pos.x - 2;
            destrect.x = pos.x;
            collision = false;
        }
    }

    else if(e.key.keysym.sym == SDLK_UP)
    {
        if(angle != 0)
        {
            angle = 0;
        }
        pos.y = pos.y - 2;
        destrect.y = pos.y;
        for(int i = 0; i < 41; i++)
        {
            if(check_collision(blocks[i], destrect))
            {
                collision = true;
                break;
            }
        }
        if(collision)
        {
            pos.y = pos.y + 2;
            destrect.y = pos.y;
            collision = false;
        }
    }

    else if(e.key.keysym.sym == SDLK_DOWN)
    {
        if(angle != 180)
        {
            angle = 180;
        }
        pos.y = pos.y + 2;
        destrect.y = pos.y;
        for(int i = 0; i < 41; i++)
        {
            if(check_collision(blocks[i], destrect))
            {
                collision = true;
                break;
            }
        }
        if(collision)
        {
            pos.y = pos.y - 2;
            destrect.y = pos.y;
            collision = false;
        }
    }
}

SDL_Rect GameObject::GetDestRect()
{
    return destrect;
}
