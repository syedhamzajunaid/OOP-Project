#pragma once
#include "GameObject.h"

//class GameObject;

class Students:public GameObject
{
private:
    int number ;

public:
    Students() {} ;
    Students(const char* path, Point* point, int num) ;
    ~Students() ;
    void Render() ;
};
