#pragma once
#include "GameObject.h"

class Vehicles: public GameObject
{
protected:
    int speed_x, speed_y ; // variables to control the motion of the vehicle.
    float friction ; // variable to smoothen the animation.
    double angle ;
public:
    //---Construtor and Destructor.
    Vehicles() {};
    ~Vehicles()
    {
        std::cout << "Vehicle destroyed." << std::endl ;
    } ;
    //---Pure Virtual Functions.
    virtual void Render() = 0 ;
    virtual void Move() = 0 ;
    virtual void Update() = 0 ;
};
