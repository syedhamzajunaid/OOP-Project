#pragma once
#include "GameObject.h"

//class GameObject ;

class Vehicles: public GameObject
{
protected:
    int speed  ;
    int xpos , ypos ;
    float friction ;
public:
    Vehicles();
    ~Vehicles();
    virtual void Render() = 0 ;
    virtual void Move(SDL_Event e,SDL_Rect* blocks) = 0  ;
    virtual void Update(SDL_Event e,SDL_Rect*blocks) = 0  ;
};
