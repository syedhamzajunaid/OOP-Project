#include "Powerups.h"
#include "SpeedBoost.h"
#include "LTexture.h"
#include "GameObject.h"



SpeedBoost::SpeedBoost(const char* path,int x, int y):Powerups()
{
    //float scale = 0.80
    type = 3 ;
    objTexture = LTexture::LoadTexture(path);
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

void SpeedBoost::Render()
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

void SpeedBoost::PowerUp(PlayerVan* player)
{
    std::cout << "SpeedBoost power-up." << std::endl ;
    std::cout << "Speed before power-up: " << player->get_speed() << std::endl ;
    player->set_speed(player->get_speed() + 2);
    std::cout <<< "Speed after power-up: " << player->get_speed() << std::endl ;
}
