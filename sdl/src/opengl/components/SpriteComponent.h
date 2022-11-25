#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Component.h"
#include <SDL.h>


class SpriteComponent : public Component
{
public:
    SpriteComponent(class Actor *owner, int drawOrder = 100);
    ~SpriteComponent();

    //virtual void Draw(SDL_Renderer *renderer);
    virtual void Draw(class Shader *shader);
    virtual void SetTexture(SDL_Texture *);

    int GetDrawOrder() const { return mDrawOrder;}
    int GetTextureWidth() const { return mTexWidth;}
    int GetTextureHeight() const { return mTexHeight;}

private:
    SDL_Texture *mTexture;
    int mDrawOrder; //draw order for painter's algorithm
    int mTexWidth;
    int mTexHeight;


};

#endif