#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Component.h"
#include <SDL.h>

// #define DBG

class SpriteComponent : public Component
{
public:
    SpriteComponent(class Actor *owner, int drawOrder = 100);
    ~SpriteComponent();

    virtual void Draw(SDL_Renderer *renderer);
    virtual void SetTexture(SDL_Texture *);   

    int GetDrawOrder() const { return mDrawOrder;}
    int GetTextureWidth() const { return mTexWidth;}
    int GetTextureHeight() const { return mTexHeight;}

private:
    SDL_Texture *mTexture;
    int mDrawOrder; //draw order for painter's algorithm
    int mTexWidth;
    int mTexHeight;

#ifdef DBG
    void DrawCollider(SDL_Renderer *surface, int n_cx, int n_cy, int radius, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
#endif

};

#endif