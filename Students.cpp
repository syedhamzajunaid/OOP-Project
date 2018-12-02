#include "Students.h"
#include <stdio.h>
#include <time.h>

Students::Students(const char* path, Point* point, int num) : GameObject()
{
    type = 6 ;
    this->number = num ;
    objTexture = LTexture::LoadTexture(path);

    this->pos = *point ;

    srcrect.h = 130 ;
    srcrect.w = 114;
    srcrect.x = 0;
    srcrect.y = 387;

    destrect.x = this->pos.x;
    destrect.y = this->pos.y;
    destrect.w = 20;
    destrect.h = 20;
}

Students::~Students()
{
    SDL_RenderCopyEx(GameLoop::grenderer, objTexture, &srcrect, &destrect, angle, NULL, SDL_FLIP_NONE);
   // delete objTexture ;

}

void Students::Render()
{
     SDL_RenderCopyEx(GameLoop::grenderer, objTexture, &srcrect, &destrect, angle, NULL, SDL_FLIP_NONE);
}
