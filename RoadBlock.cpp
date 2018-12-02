#include "RoadBlock.h"

RoadBlock::RoadBlock(const char* path, int x, int y) : Obstacles()
{
    //float scale = 0.80
    type = 4 ;
    strength = 10 ;
   // angle = 30 ;
    objTexture = LTexture::LoadTexture(path);
    this->pos.x = x ;
    this->pos.y = y ;

    srcrect.h = 37 ;
    srcrect.w = 32;
    srcrect.x = 30;
    srcrect.y = 190;

    destrect.x = this->pos.x;
    destrect.y = this->pos.y;
    destrect.w = 20;
    destrect.h = 20;
}

RoadBlock::~RoadBlock()
{
    if (alive == false)
    {

    std::cout << "Roadblock destroyed." << std::endl ;
    }
}

void RoadBlock::Render()
{
    SDL_RenderCopyEx(GameLoop::grenderer, objTexture, &srcrect, &destrect, angle, NULL, SDL_FLIP_NONE);
}
