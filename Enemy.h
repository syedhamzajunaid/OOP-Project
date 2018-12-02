#ifndef ENEMY_H
#define ENEMY_H
#include "GameLoop.h"
#include "Map.h"

class Enemy
{
protected:
    int speed_x, speed_y = 0 ;
    int xpos , ypos;
    float friction ;
    double angle;
    SDL_Texture* enemy_texture;
    SDL_Rect srcrect, destrect;
    int current_node = -1;
    int next_node = -1;
    int previous_node = -2;
    bool collision;
    bool present;

public:
    Enemy();
    Enemy(const char* spritesheet, int x, int y, int ang);
    ~Enemy()
    {
        SDL_DestroyTexture(enemy_texture);
        enemy_texture = NULL;
        std::cout << "Vehicle destroyed." << std::endl ;
    } ;
    void Render();
    //void Move(SDL_Event e,SDL_Rect* blocks);
    void Update(SDL_Rect* nodes, int adjacency_matrix[71][71]);
    bool check_collision(SDL_Rect B, SDL_Rect A);
};

#endif // ENEMY_H
