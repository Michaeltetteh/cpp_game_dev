#ifndef ANIM_SPRITE_COMPONENT_H
#define ANIM_SPRITE_COMPONENT_H

#include <vector>
#include <SDL.h>
#include "SpriteComponent.h"

typedef  std::vector<SDL_Texture*> VEC_TEX_PTR;

class AnimSpriteComponent : public SpriteComponent
{
public:
    AnimSpriteComponent(class Actor *owner, int drawOrder = 100);
    
    void Update(float deltaTime) override;
    void SetAnimTextures(const VEC_TEX_PTR &textures);

    float GetAnimFPS() const { return mAnimFPS;}
    void SetAnimFPS(float fps) { mAnimFPS = fps;}

private:
    std::vector<SDL_Texture *> mAnimTextures;
    float mCurrFrame; //current frame displayed
    float mAnimFPS; //animation frame rate

};

#endif
