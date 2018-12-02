#pragma once
#include"SDL.h"
#include "Obstacles.h"

class RoadBlock: public Obstacles
{
private:
    bool alive ;
public:
    RoadBlock(const char* path, int x, int y) ;
   ~RoadBlock() ;
    void Render();
};
