#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"

class Timer
{
private:
	//The clock time when the timer started
	int start_ticks;
	int frame = 0;
	LTexture* font;

	//The timer status
	bool paused;
	bool started;
	bool time_up;

public:

	Timer();
	void Render(LTexture* font_spr);
	void start();
	void stop();
	void pause();
	void resume();
	bool is_started();
	bool is_paused();
	bool is_time_up();
};