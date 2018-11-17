#include "GameObject.h"



GameObject::GameObject(const char* spritesheet)
{
    objTexture = LTexture::LoadTexture(spritesheet);
}

GameObject::~GameObject()
{}

void GameObject::Update()
{
    xpos = ypos = 0;

    srcrect.h = srcrect.w = 100;
    srcrect.x = srcrect.y = 0;

    destrect.x = xpos;
    destrect.y = ypos;
    destrect.w = srcrect.w;
    destrect.h = srcrect.h;
}

void GameObject::Render()
{
    SDL_RenderCopy(GameLoop::grenderer, objTexture, NULL, &destrect);
}
