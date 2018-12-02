#include "Enemy.h"
#include "Map.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


Enemy::Enemy(){}

Enemy::Enemy(const char* spritesheet, int x, int y, int ang)
{
    enemy_texture = LTexture::LoadTexture(spritesheet);
    srcrect.x = 1;
	srcrect.y = 54;
	srcrect.w = 30;
	srcrect.h = 20;

	xpos = x;
	ypos = y;
	angle = ang;

	if(angle == 0)
    {
        speed_x = 0;
        speed_y = -1;
    }
    else if(angle == 90)
    {
        speed_x = 1;
        speed_y = 0;
    }
    else if(angle == 180)
    {
        speed_x = 0;
        speed_y = 1;
    }
    else if(angle == -90)
    {
        speed_x = -1;
        speed_y = 0;
    }

    destrect.x = xpos;
    destrect.y = ypos;
    destrect.w = srcrect.w/2;
    destrect.h = srcrect.h;;
    collision = false;
	present = true;
}


bool Enemy::check_collision(SDL_Rect B, SDL_Rect A)
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

void Enemy::Render()
{
    SDL_RenderCopyEx(GameLoop::grenderer, enemy_texture, NULL, &destrect, angle, NULL, SDL_FLIP_NONE);
}

void Enemy::Update(SDL_Rect* nodes, int adjacency_matrix[71][71])
{
    int adjacent_nodes[4] = {0};
    srand(time(NULL));
    destrect.x = destrect.x + speed_x;
    destrect.y = destrect.y + speed_y;
    if(collision == false)
    {
        for(int i = 0; i < 71; i++)
        {
            if(check_collision(destrect, nodes[i]))
            {
                collision = true;
                current_node = i;
            }
        }
    }
    cout << current_node << endl;
    if(collision == true)
    {
        int cnt = 0;
        for(int i = 0; i < 71; i++)
        {
            if(adjacency_matrix[current_node][i] != 0)
            {
                adjacent_nodes[cnt] = i;
                cnt++;
            }
        }
        int random_index = 4 - (rand() % 4);
        while(adjacent_nodes[random_index] == 0)
        {
            random_index = 4 - (rand() % 4);
        }
        next_node = adjacent_nodes[random_index];

        cout << next_node << endl;
        int x_distance = nodes[current_node].x - nodes[next_node].x;
        int y_distance = nodes[current_node].y - nodes[next_node].y;



        if(x_distance > 2)
        {
            speed_x = -1;
            speed_y = 0;
            angle = -90;
            destrect.y = nodes[current_node].y + (nodes[current_node].h)*0.6;
        }
        else if(x_distance < -2)
        {
            speed_x = 1;
            speed_y = 0;
            angle = 90;
            destrect.y = nodes[current_node].y + (nodes[current_node].h)*0.05;
        }
        else if(y_distance > 2)
        {
            speed_y = -1;
            speed_x = 0;
            angle = 0;
            destrect.x = nodes[current_node].x + (nodes[current_node].w)*0.05;

        }
        else if(y_distance < -2)
        {
            speed_y = 1;
            speed_x = 0;
            angle = 180;
            destrect.x = nodes[current_node].x + (nodes[current_node].w)*0.6;

        }
        else
        {
            cout << "some error here" << endl;
        }
        collision = false;
    }

}


