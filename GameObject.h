#pragma once
#include "GameLoop.h"
#include "Point.h"

class GameObject
{
    public:
        GameObject();
       // GameObject();
        ~GameObject();
        //static PlayerVan* playervan;
        virtual void Update(SDL_Event e, SDL_Rect* blocks);
        virtual void Render();
        Point GetPosition(){return pos;};
        void SetPosition(Point position) {this->pos = position;};
        void angle_setter(double angle){this->angle = angle;}
        bool check_collision(SDL_Rect A, SDL_Rect B);
		bool is_present() { return present;}
		int GetType(){return type;};
        virtual void PowerUp() {};
        float GetFuel() ;
        SDL_Rect GetDestRect();
        void  SetFuel(float new_fuel) ;
        float GetTime() ;
        virtual void PickUp(GameObject* student) {} ;

    //static PlayerVan* GetPlayer() ;
        void SetTime(float new_time) ;
//		SDL_Rect GetDestRect();

    protected:
		Point pos;
		int type;
        double angle;
        SDL_Texture* objTexture;
        SDL_Rect srcrect, destrect;
        bool collision;
		bool present;

};


