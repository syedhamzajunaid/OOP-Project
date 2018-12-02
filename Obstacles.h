#pragma once
#include "GameObject.h"
#include "SDL.h"

class Obstacles: public GameObject
{
protected:
    int strength ;
public:
    Obstacles():GameObject() {} ;
    ~Obstacles() {};
    virtual void Render() = 0 ;
    //virtual void Update() = 0 ;
};
