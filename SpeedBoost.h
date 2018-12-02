#pragma once
#include "Powerups.h"
#include "PlayerVan.h"

class SpeedBoost:public Powerups
{
private:
    int frame = 0;
  int i = 0;
  SDL_Rect pwrUp_animation[8];
public:
    SpeedBoost(const char* path,int x, int y) ;
    ~SpeedBoost();
    void Render();
    void PowerUp(PlayerVan* player);
};
