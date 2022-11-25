#include "BGSpriteComponent.h"
#include "../actors/Actor.h"
#include "../Shader.h"



BGSpriteComponent::BGSpriteComponent(Actor *owner, int drawOrder)
    :SpriteComponent(owner,drawOrder)
    ,mScrollSpeed(0.0f)
    {}


void BGSpriteComponent::SetBGTextures(const VEC_TEX_PTR &textures)
{
    int count = 0;
    for(auto tex : textures)
    {
        BGTexture temp;

        temp.mTexture = tex;
        //Each texture is screen width in offset
        temp.mOffSet.x = count * mScreenSize.x;
        temp.mOffSet.y = 0;

        mBGTextures.emplace_back(temp);
        count++;
    }
}


void BGSpriteComponent::Update(float deltaTime)
{
    SpriteComponent::Update(deltaTime);

    for(auto &bg : mBGTextures)
    {
        //Update the x offset
        bg.mOffSet.x += mScrollSpeed * deltaTime;
        // If this is completely off the screen, reset offset to
        // the right of the last bg texture 
        if(bg.mOffSet.x < -mScreenSize.x)
        {
            bg.mOffSet.x = (mBGTextures.size() - 1) * mScreenSize.x - 1;
        }
    }
}

void BGSpriteComponent::Draw(Shader *shader)
{
    std::ignore = shader;
//    for (auto& bg : mBGTextures)
//    {
//        SDL_Rect r;
//        // Assume screen size dimensions
//        r.w = static_cast<int>(mScreenSize.x);
//        r.h = static_cast<int>(mScreenSize.y);
//        // Center the rectangle around the position of the owner
//        r.x = static_cast<int>(mOwner->GetPosition().x - r.w / 2 + bg.mOffSet.x);
//        r.y = static_cast<int>(mOwner->GetPosition().y - r.h / 2 + bg.mOffSet.y);
//
//        // Draw this background
//        SDL_RenderCopy(renderer,
//            bg.mTexture,
//            nullptr,
//            &r
//        );
//    }
}