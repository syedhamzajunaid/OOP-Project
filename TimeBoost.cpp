#include "Powerups.h"
#include "TimeBoost.h"
#include "LTexture.h"
#include "GameObject.h"


TimeBoost::TimeBoost(const char* path,int x, int y):Powerups()
{
    //float scale = 0.80
    type = 1 ;
    objTexture = LTexture::LoadTexture(path);
    std::cout << "TimeBoost loaded" << std::endl;
	pwrUp_animation[0] = {10,0,13,32};
	pwrUp_animation[1] = {35,0,27,32};
	pwrUp_animation[2] = {67,0,28,32};
	pwrUp_animation[3] = {100,0,27,31};
	pwrUp_animation[4] = {131,0,28,32};
	pwrUp_animation[5] = {165,0,24,32};
	pwrUp_animation[6] = {195,0,29,32};
	pwrUp_animation[7] = {230,0,23,31};
	//pwrUp_animation[8] = {530,0,28,42};

	this->pos.x = x ;
    this->pos.y = y ;

    destrect.x = this->pos.x;
    destrect.y = this->pos.y;
    destrect.w = 20;
    destrect.h = 20;
}

void TimeBoost::Render()
{
	if (frame%25 == 0)
	{
		if (i < 7)
		{
			SDL_RenderCopyEx(GameLoop::grenderer, objTexture, &pwrUp_animation[i], &destrect, angle, NULL, SDL_FLIP_NONE);
			i++;
			frame++;
		}
		else
		{
			SDL_RenderCopyEx(GameLoop::grenderer, objTexture, &pwrUp_animation[i], &destrect, angle, NULL, SDL_FLIP_NONE);
			i = 0;
			i++;
			frame++;
		}

	}

	else
	{
		SDL_RenderCopyEx(GameLoop::grenderer, objTexture, &pwrUp_animation[i], &destrect, angle, NULL, SDL_FLIP_NONE);
		frame++;
	}

}

void TimeBoost::PowerUp()
{
    GameLoop::timer.set_ticks(GameLoop::timer.get_ticks() + 10 );
}
