#pragma once
#include "Vehicles.h"
#include "Students.h"

class Vehicles ;

class PlayerVan: public Vehicles
{
private:
	int fuel = 100;
	int distance_covered = 1;
	bool alive=true;
	int number_of_students;
    Students* students = new Students[capacity]  ;
    float friction ;
    int capacity = 5 ;

public:
    PlayerVan(const char* path) ;
    ~PlayerVan();
    SDL_Rect GetDestRect();
    int GetCapacity() ;
    void PickUp(Students* student);
    void SetFuel();
   // float GetTime() ;
    //void SetTime(float new_time) ;
    void Move(SDL_Event e, SDL_Rect* blocks) ;
    void Render() ;
    void Update(SDL_Event e,SDL_Rect* blocks);
    bool CheckCollision(SDL_Rect A, SDL_Rect B) ;

	// For fuel
	SDL_Texture* Fuel_bar;
	SDL_Rect bar_animation[5];
	SDL_Rect Fbar_dest;
    float get_fuel() ;
    void  set_fuel(float new_fuel) ;
    int get_speed()  ;
    void set_speed(int new_speed);
} ;
