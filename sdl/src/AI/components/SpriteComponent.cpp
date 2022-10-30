#include "SpriteComponent.h"
#include "../actors/Actor.h"
#include "../Game.h"


SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
    :Component(owner)
    ,mTexture(nullptr)
    ,mDrawOrder(drawOrder)
    ,mTexWidth(0)
    ,mTexHeight(0)
{
    mOwner->GetGame()->AddSprite(this);
}

void SpriteComponent::SetTexture(SDL_Texture *texture)
{
    mTexture = texture;
    //gets with and height of a texture
    SDL_QueryTexture(mTexture,nullptr, nullptr, &mTexWidth, &mTexHeight);
}


void SpriteComponent::Draw(SDL_Renderer *renderer)
{
    if(mTexture)
    {
        SDL_Rect r;
        //Scale the width/height by owner's scale
        r.w = static_cast<int>(mTexWidth * mOwner->GetScale());
        r.h = static_cast<int>(mTexHeight * mOwner->GetScale());
        // Center the rectangle around the position of the owner 
        r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2); 
        r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2);

        SDL_RenderCopyEx(renderer, mTexture, nullptr, &r, -Math::ToDegrees(mOwner->GetRotation()),nullptr, SDL_FLIP_NONE);
    }
#ifdef DBG
    DrawCollider(renderer, mOwner->GetPosition().x, mOwner->GetPosition().y,40, 0x00, 0x00, 0xFF, 0xFF);
#endif

}

SpriteComponent::~SpriteComponent()
{
    mOwner->GetGame()->RemoveSprite(this);
}

#ifdef DBG
void set_pixel(SDL_Renderer *rend, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
 {
     SDL_SetRenderDrawColor(rend, r,g,b,a);
     SDL_RenderDrawPoint(rend, x, y);
 }

 void SpriteComponent::DrawCollider(SDL_Renderer *surface, int n_cx, int n_cy, int radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
 {

     double error = (double)-radius;
     double x = (double)radius - 0.5;
     double y = (double)0.5;
     double cx = n_cx - 0.5;
     double cy = n_cy - 0.5;

     while (x >= y)
     {
         set_pixel(surface, (int)(cx + x), (int)(cy + y), r, g, b, a);
         set_pixel(surface, (int)(cx + y), (int)(cy + x), r, g, b, a);

         if (x != 0)
         {
             set_pixel(surface, (int)(cx - x), (int)(cy + y), r, g, b, a);
             set_pixel(surface, (int)(cx + y), (int)(cy - x), r, g, b, a);
         }

         if (y != 0)
         {
             set_pixel(surface, (int)(cx + x), (int)(cy - y), r, g, b, a);
             set_pixel(surface, (int)(cx - y), (int)(cy + x), r, g, b, a);
         }

         if (x != 0 && y != 0)
         {
             set_pixel(surface, (int)(cx - x), (int)(cy - y), r, g, b, a);
             set_pixel(surface, (int)(cx - y), (int)(cy - x), r, g, b, a);
         }

         error += y;
         ++y;
         error += y;

         if (error >= 0)
         {
             --x;
             error -= x;
             error -= x;
         }

     }
 }
#endif