#ifndef BGSPRITECOMPONENT_H
#define BGSPRITECOMPONENT_H

#include "SpriteComponent.h"
#include <SDL2/SDL.h>
#include "Math/Math.h"

#include <vector>

typedef  std::vector<SDL_Texture*> VEC_TEX_PTR;

class BGSpriteComponent : public SpriteComponent
{
public:
    //Set draw order to default to lower (so it's in the background)
    BGSpriteComponent(class Actor *owner, int drawOrder = 10);

    void Update(float deltaTime) override;
    void Draw(SDL_Renderer *rendered) override;

    void SetBGTextures(const VEC_TEX_PTR &textures);
    void SetScreenSize(const Vector2 & size) { mScreenSize = size;}
    void SetScrollSpeed(float speed) { mScrollSpeed = speed;}

    float GetScrollSpeed() const { return mScrollSpeed;}

private:
    //Struct to encapsulate each BG image and its offset
    struct BGTexture
    {
        SDL_Texture *mTexture;
        Vector2 mOffSet;
    };

    std::vector<BGTexture> mBGTextures; 
    Vector2 mScreenSize;
    float mScrollSpeed;

};

#endif