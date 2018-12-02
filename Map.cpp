#include "SDL_Dimensions.h"
#include "Map.h"
#include "LTexture.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include <vector>


Map::Map(const char* spritesheet)
{
	map_texture = LTexture::LoadTexture(spritesheet);

	/*for width: (width of rect/width of map) * width of map
	keep modular values of x,y,w,h!
*/
	int w = dimension::Screen_width();
	int h = dimension::Screen_height();

	blocks[0] = { 0,0,int(w*(0.15)),int(h*(0.11)) };
	blocks[1] = { int(w*(0.19)),0,int(w*(0.098)),int(h*(0.11)) };
	blocks[2] = { int(w*(0.324)),0, int(w*(0.163)),int(h*(0.11)) };
	blocks[3] = { int(w*(0.527)),0, int(w*(0.125)),int(h*(0.11)) };
	blocks[4] = { int(w*(0.688)),0,int(w*(0.099)),int(h*(0.11)) };
	blocks[5] = { int(w*(0.825)),0,int(w*(0.71)),int(h*(0.25)) };
	blocks[6] = { 0,int(h*(0.149)),int(w*(0.074)),int(h*(0.087)) };
	blocks[7] = { int(w*(0.114)),int(h*(0.149)),int(w*(0.196)),int(h*(0.088)) };
	blocks[8] = { int(w*(0.35)),int(h*(0.149)),int(w*(0.124)),int(h*(0.248)) };
	blocks[9] = { int(w*(0.512)),int(h*(0.149)),int(w*(0.274)),int(h*(0.099)) };
	blocks[10] = { int(w*(0.825)),int(h*(0.287)),int(w*(0.137)),int(h*(0.111)) };
	blocks[11] = { int(w*(0.036)),int(h*(0.274)),int(w*(0.113)),int(h*(0.089)) };
	blocks[12] = { int(w*(0.187)),int(h*(0.27)),int(w*(0.124)),int(h*(0.164)) };
	blocks[13] = { int(w*(0.35)),int(h*(0.436)),int(w*(0.123)),int(h*(0.138)) };
	blocks[14] = { int(w*(0.474)),int(h*(0.539)),int(w*(0.124)),int(h*(0.035)) };
	blocks[15] = { int(w*(0.512)),int(h*(0.397)),int(w*(0.088)),int(h*(0.101)) };
	blocks[16] = { int(w*(0.512)),int(h*(0.289)),int(w*(0.074)),int(h*(0.074)) };
	blocks[17] = { int(w*(0.625)),int(h*(0.287)),int(w*(0.076)),int(h*(0.075)) };
	blocks[18] = { int(w*(0.737)),int(h*(0.287)),int(w*(0.05)),int(h*(0.075)) };
	blocks[19] = { int(w*(0.637)),int(h*(0.399)),int(w*(0.149)),int(h*(0.097)) };
	blocks[20] = { int(w*(0.825)),int(h*(0.436)),int(w*(0.175)),int(h*(0.152)) };
	blocks[21] = { int(w*(0.037)),int(h*(0.398)),int(w*(0.149)),int(h*(0.037)) };
	blocks[22] = { int(w*(0.636)),int(h*(0.536)),int(w*(0.149)),int(h*(0.088)) };
	blocks[23] = { int(w*(0.037)),int(h*(0.475)),int(w*(0.274)),int(h*(0.187)) };
	blocks[24] = { int(w*(0.349)),int(h*(0.612)),int(w*(0.249)),int(h*(0.087)) };
	blocks[25] = { int(w*(0.638)),int(h*(0.661)),int(w*(0.149)),int(h*(0.136)) };
	blocks[26] = { int(w*(0.824)),int(h*(0.623)),int(w*(0.139)),int(h*(0.053)) };
	blocks[27] = { int(w*(0.823)),int(h*(0.709)),int(w*(0.139)),int(h*(0.089)) };
	blocks[28] = { 0,int(h*(0.697)),int(w*(0.084)),int(h*(0.177)) };
	blocks[29] = { int(w*(0.086)),int(h*(0.811)),int(w*(0.037)),int(h*(0.063)) };
	blocks[30] = { int(w*(0.125)),int(h*(0.700)),int(w*(0.05)),int(h*(0.072)) };
	blocks[31] = { int(w*(0.211)),int(h*(0.699)),int(w*(0.099)),int(h*(0.075)) };
	blocks[32] = { int(w*(0.348)),int(h*(0.736)),int(w*(0.25)),int(h*(0.0625)) };
	blocks[33] = { int(w*(0.488)),int(h*(0.837)),int(w*(0.298)),int(h*(0.049)) };
	blocks[34] = { int(w*(0.160)),int(h*(0.812)),int(w*(0.15)),int(h*(0.061)) };
	blocks[35] = { int(w*(0.038)),int(h*(0.911)),int(w*(0.086)),int(h*(0.050)) };
	blocks[36] = { int(w*(0.163)),int(h*(0.911)),int(w*(0.148)),int(h*(0.05)) };
	blocks[37] = { int(w*(0.349)),int(h*(0.837)),int(w*(0.101)),int(h*(0.126)) };
	blocks[38] = { int(w*(0.487)),int(h*(0.92)),int(w*(0.076)),int(h*(0.075)) };
	blocks[39] = { int(w*(0.6)),int(h*(0.92)),int(w*(0.188)),int(h*(0.075)) };
	blocks[40] = { int(w*(0.825)),int(h*(0.837)),int(w*(0.138)),int(h*(0.126)) };
}

Map::~Map()
{}

void Map::Update()
{
	pos.x = pos.y = 0;
}

void Map::Render()
{
	SDL_RenderCopy(GameLoop::grenderer, map_texture, NULL, NULL);
	//std::cout << "Map rendered" << std::endl;

	//for debugging, show these rects on map
	/*for(int i = 0; i < 41; i++)
	{
	SDL_SetRenderDrawColor(GameLoop::grenderer, 244,255,255,255);
	SDL_RenderFillRect(GameLoop::grenderer, &(blocks[i]));
	}*/
}


//---Function to randomly place objects on the screen.
bool Map::PlaceObjects(int x, int y)
{
    SDL_Rect rendering_position =  {x, y, 20, 20};
    //vector<Point>locations ;
    for(int i = 0; i < 41; i++)
    {
        if((GameLoop::CheckCollision(rendering_position, blocks[i])))
            return false;
    }
    return true;
}
