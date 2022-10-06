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
}

SpriteComponent::~SpriteComponent()
{
    mOwner->GetGame()->RemoveSprite(this);
}
