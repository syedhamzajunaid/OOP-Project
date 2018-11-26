#include "Timer.h"
#include "GameLoop.h"
#include "Word.h"
#include "string"
#include "iostream"
#include <math.h> 
using namespace std;

Timer::Timer()
{
	//Initialize the variables
	start_ticks = 0;
	paused = false;
	started = false;
}

void Timer::start()
{
	/*SDL event e: as soon as spacebar pressed
	timer starts.*/

	//Start the timer
	started = true;
	//Unpause the timer
	paused = false;
	// set the time_up
	time_up = false;
	start_ticks = 90;
}

void Timer::stop()
{
	//Stop the timer
	started = false;
	//Unpause the timer
	paused = false;
}

void Timer::pause()
{
	//If the timer is running and isn't already paused
	if ((started == true) && (paused == false))
	{
		//Pause the timer
		paused = true;
	}
}

void Timer::resume()
{
	//If the timer is paused
	if (paused == true)
	{
		//Unpause the timer
		paused = false;
	}
}

bool Timer::is_started()
{
	return started;
}
bool Timer::is_paused()
{
	return paused;
}
bool Timer::is_time_up()
{
	return time_up;
}
void Timer::Render(LTexture* font_spr)
{
	if (frame % 240 == 0 and started and !paused and start_ticks >1)
	{
		start_ticks -= 1;
		int min = start_ticks/(60);
		int sec = start_ticks % (60);

		string a = to_string(int(min));
		string b = to_string(sec);
		string c = "Time: 0" + a + " . " + b;

		cout << c << '\n';

		// Making 'Time 00:00'
		Word* t_val = new Word(c,font_spr,881,4);

		//t_val->Render(GameLoop::grenderer);
		// use word and character
		// Then render it on top right corner
		//SDL_RenderCopy(GameLoop::grenderer, map_texture, NULL, NULL);
	}
	else if (start_ticks <= 1)
	{
		time_up = true;
	}
	frame++;
}

