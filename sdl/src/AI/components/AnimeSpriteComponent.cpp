#include "AnimSpriteComponent.h"


AnimSpriteComponent::AnimSpriteComponent(Actor *owner, int drawOrder)
    :SpriteComponent(owner,drawOrder)
    , mCurrFrame(0.0f)
    , mAnimFPS(24.0f)
    {}


void AnimSpriteComponent::SetAnimTextures(const VEC_TEX_PTR &textures)
{
    mAnimTextures = textures;
    if(mAnimTextures.size() > 0)
    {
        //set active texture to first frame
        mCurrFrame = 0.0f;
        SetTexture(mAnimTextures[0]);
    }
}


void AnimSpriteComponent::Update(float deltaTime)
{
    SpriteComponent::Update(deltaTime);
    
    if(mAnimTextures.size() > 0)
    {
        mCurrFrame = mAnimFPS * deltaTime;
        //Wrap current frame if needed
        while(mCurrFrame >= mAnimTextures.size())
        {
            mCurrFrame -= mAnimTextures.size();
        }
        //set the current texture
        SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
    }
}