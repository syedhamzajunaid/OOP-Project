#pragma once

class Vehicles: public GameObject
{
protected:
    int speed_x, speed_y ;
    float friction ;
    double angle ;
    SDL_Rect vehicle ;
public:
    Vehicles() {};
    ~Vehicles()
    {
        std::cout << "Vehicle destroyed." << std::endl ;
    } ;
    virtual void Render() = 0 ;
    virtual void Move() = 0 ;
};
