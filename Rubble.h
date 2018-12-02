#pragma once
#include"LTexture.h"
#include "SDL.h"
#include "Obstacles.h"

class Rubble: public Obstacles
{
private:
    bool alive ;
 public:
    Rubble(const char* path, int x, int y);
    ~Rubble() ;
    void Render();
};
