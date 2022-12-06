#include "SpriteComponent.h"
#include "../actors/Actor.h"
#include "../Game.h"
#include "../Shader.h"


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
    // SDL_QueryTexture(mTexture,nullptr, nullptr, &mTexWidth, &mTexHeight);
}


void SpriteComponent::Draw(Shader *shader)
{
   //Scale the quad by the width/height of texture
    Matrix4 scaleMat = Matrix4::CreateScale(
            static_cast<float>(mTexWidth),
            static_cast<float>(mTexHeight),
            1.0f);
    Matrix4 world = scaleMat * mOwner->GetWorldTransform();
    shader->SetMatrixUniform("uWorldTransform",world);
    glDrawElements(
            GL_TRIANGLES,       // Type of polygon/primitive to draw
            6,                  // Number of indices in index buffer
            GL_UNSIGNED_INT,    // Type of each index
            nullptr             // null
    );



}

SpriteComponent::~SpriteComponent()
{
    mOwner->GetGame()->RemoveSprite(this);
}
