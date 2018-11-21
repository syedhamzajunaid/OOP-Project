#pragma once
#include "GameObject.h"

class Vehicles: public GameObject
{
protected:
    int speed_x, speed_y ;
    float friction ;
    double angle ;
public:
    Vehicles() {};
    ~Vehicles()
    {
        std::cout << "Vehicle destroyed." << std::endl ;
    } ;
    virtual void Render() = 0 ;
    virtual void Move() = 0 ;
    virtual void Update() = 0 ;
};