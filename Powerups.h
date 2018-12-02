#pragma once
#include "GameObject.h"

class Powerups:public GameObject
{
protected:
    int strength;
    bool alive;
    SDL_Rect powerup ;
    //int type = 1 ;
public:
    Powerups(): GameObject() {} ;
    ~Powerups() {};
    virtual void Render() = 0;
};
