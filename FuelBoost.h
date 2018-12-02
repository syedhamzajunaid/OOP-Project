#pragma once
#include "Powerups.h"
//#include "PlayerVan.h"

class FuelBoost: public Powerups
{
private:
    // for animation
  int frame = 0;
  int i = 0;
  SDL_Rect pwrUp_animation[8];
public:
    FuelBoost(const char* path,int x, int y) ;
    ~FuelBoost() ;
    void PowerUp() ;
    void Render();
};

