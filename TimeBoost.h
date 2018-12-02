#pragma once
#include "Powerups.h"

class TimeBoost: public Powerups
{
private:
    // for animation
  int frame = 0;
  int i = 0;
  SDL_Rect pwrUp_animation[8];
public:
  TimeBoost(const char* path,int x, int y) ;
  ~TimeBoost() ;
  void PowerUp() ;
  void Render();
};
