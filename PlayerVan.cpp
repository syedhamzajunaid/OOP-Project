#include "PlayerVan.h"
#include "SDL_Dimensions.h"
#include "SDL.h"


int Screen_Width = dimension::Screen_width();
int Screen_Height = dimension::Screen_height();

//---The constructor basically loads the texture of the object.
PlayerVan::PlayerVan(const char* path): Vehicles()
{
    type = 0;
	number_of_students = 0 ;
    objTexture = LTexture::LoadTexture(path);
    std::cout << "Player Van texture loaded." << std::endl ;

	srcrect.x = 1;
	srcrect.y = 54;
	srcrect.w = 28;
	srcrect.h = 19;

	pos.x = 0;
	pos.y = int(Screen_Height * (0.114));
	speed = 0 ;
	friction = 0.95f ;

	destrect.x = pos.x;
	destrect.y = pos.y;
	destrect.w = 20;
	destrect.h = 13;
	angle = 0;

	// FUEL BAR
	Fuel_bar = LTexture::LoadTexture("Assets/Bar.png");
	bar_animation[0] = { 10,1,285,17 };
	bar_animation[1] = { 10,29,285,17 };
	bar_animation[2] = { 10,57,285,17 };
	bar_animation[3] = { 10,85,285,17 };
	bar_animation[4] = { 10,114,285,17 };

	Fbar_dest = { int(Screen_Width*(0.527)),int(Screen_Height*(0.02)),int(Screen_Width*(0.271)),int(Screen_Height*(0.032)) };
 }

//---Destructor.
 PlayerVan::~PlayerVan()
 {
     std::cout << "Player Van destroyed." << std::endl ;
 }

//---Getter functions


void PlayerVan::SetFuel()
{
	// Normal motion
	if (distance_covered % 100==0)
	{
		distance_covered = 1;
		fuel -= 10;
	}
}

/*
float PlayerVan::GetTime()
{
    return time ;
}
*/
//---Setter functions

/*
void PlayerVan::SetTime(float new_time)
{
    time = new_time ;
}
*/
//---Inherited (Polymorphic) methods.
void PlayerVan::Render()
{
	SDL_RenderCopyEx(GameLoop::grenderer, objTexture, &srcrect, &destrect, angle, NULL, SDL_FLIP_NONE);

	if (alive)
	{
		if (fuel == 100)
		{
			SDL_RenderCopyEx(GameLoop::grenderer, Fuel_bar, &bar_animation[0], &Fbar_dest, 0, NULL, SDL_FLIP_NONE);
		}
		else if (fuel==80)
		{
			SDL_RenderCopyEx(GameLoop::grenderer, Fuel_bar, &bar_animation[1], &Fbar_dest, 0, NULL, SDL_FLIP_NONE);
		}
		else if (fuel == 60)
		{
			SDL_RenderCopyEx(GameLoop::grenderer, Fuel_bar, &bar_animation[2], &Fbar_dest, 0, NULL, SDL_FLIP_NONE);
		}
		else if (fuel == 40)
		{
			SDL_RenderCopyEx(GameLoop::grenderer, Fuel_bar, &bar_animation[3], &Fbar_dest, 0, NULL, SDL_FLIP_NONE);
		}
		else
		{
			SDL_RenderCopyEx(GameLoop::grenderer, Fuel_bar, &bar_animation[4], &Fbar_dest, 0, NULL, SDL_FLIP_NONE);
		}
	}
}

void PlayerVan::Update(SDL_Event e,SDL_Rect* blocks)
{
    this->Move(e,blocks) ;
}

bool PlayerVan::CheckCollision(SDL_Rect A, SDL_Rect B)
{
 //   std::cout << "Collision check." << std::endl;
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }
    //If none of the sides from A are outside B
    return true;
}


void PlayerVan::Move(SDL_Event e,SDL_Rect* blocks)
{
    if (e.type == SDL_KEYDOWN)
	{
			switch (e.key.keysym.sym)
			{
				case SDLK_LEFT:
					if(angle != 180)
					{
						angle = 180;
					}
					speed = -2 ;
					this->pos.x +=  speed;
					destrect.x = this->pos.x;
					distance_covered++;
					for(int i = 0; i < 40; i++)
					{
						if(GameLoop::CheckCollision(blocks[i], destrect))
						{
							collision = true;
							break;
						}
					}
					if(collision)
					{
					    speed = 2 ;
						this->pos.x += speed;
						destrect.x = this->pos.x;
						collision = false;

					}
					std :: cout << distance_covered << "  "<< fuel << std::endl ;
					break;

				case SDLK_RIGHT:
					if(angle != 0.0)
					{
						angle = 0.0;
					}
					speed = 2;
					this->pos.x += speed;
					destrect.x = this->pos.x;
					distance_covered++;
					for(int i = 0; i < 40; i++)
					{
						if(PlayerVan::CheckCollision(blocks[i], destrect))
						{
							collision = true;
							break;
						}
					}
					if(collision)
					{
					    speed = -2 ;
						this->pos.x += speed;
						destrect.x = this->pos.x;
						collision = false;

					}
					std :: cout << distance_covered << "  " << fuel << std::endl ;
					break ;

				case SDLK_UP:
					if(angle != -90)
					{
						angle = -90;
					}
					speed = -2 ;
					this->pos.y += speed;
					destrect.y = this->pos.y;
					distance_covered++;
					for(int i = 0; i < 40; i++)
					{
						if(PlayerVan::CheckCollision(blocks[i], destrect))
						{
							collision = true;
							break;
						}
					}
					if(collision)
					{
					    speed = 2;
						this->pos.y +=  speed;
						destrect.y = this->pos.y;
						collision = false;

					}
					std :: cout << distance_covered << "  " << fuel << std::endl ;
					break;
				case SDLK_DOWN:
					if(angle != 90)
					{
						angle = 90;
					}
					speed = 2 ;
					this->pos.y += speed;
					destrect.y = this->pos.y;
					distance_covered++;
					for(int i = 0; i < 40; i++)
					{
						if(PlayerVan::CheckCollision(blocks[i], destrect))
						{
							collision = true;
							break;
						}
					}
					if(collision)
					{
					    speed = -2 ;
						this->pos.y += speed;
						destrect.y = this->pos.y;
						collision = false;

					}
					std :: cout << distance_covered << "  " << fuel << std::endl ;
					break;

				default:
					break;
			}
	}
}
SDL_Rect PlayerVan::GetDestRect()
{
    return destrect;
}

void PlayerVan::PickUp(Students* student)
{
    student[number_of_students] = *student;
    number_of_students ++ ;
}

float PlayerVan::get_fuel()
{
    return fuel;
}

void PlayerVan::set_fuel(float new_fuel)
{
   fuel = new_fuel ;
}

int PlayerVan::get_speed()
{
    return speed;
}

void PlayerVan::set_speed(int new_speed)
{
    speed = new_speed ;
}
