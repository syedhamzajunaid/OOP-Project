#include "Rubble.h"

#include "RoadBlock.h"

Rubble::Rubble(const char* path, int x, int y) : Obstacles()
{
    //float scale = 0.80
    type = 5 ;
    strength = 5 ;
    objTexture = LTexture::LoadTexture(path);
    //powerup = {241,1981,66,62} ;
    this->pos.x = x ;
    this->pos.y = y ;

    srcrect.h = 32 ;
    srcrect.w = 44;
    srcrect.x = 200;
    srcrect.y = 440;

    destrect.x = this->pos.x;
    destrect.y = this->pos.y;
    destrect.w = 20;
    destrect.h = 20;
}

Rubble::~Rubble()
{
    alive = false ;
    std::cout << "Roadblock destroyed." << std::endl ;
}

void Rubble::Render()
{
    SDL_RenderCopyEx(GameLoop::grenderer, objTexture, &srcrect, &destrect, angle, NULL, SDL_FLIP_NONE);
}
