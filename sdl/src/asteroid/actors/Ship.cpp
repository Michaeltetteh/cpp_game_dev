#include "Ship.h"
//#include "../components/AnimSpriteComponent.h"
#include "../Game.h"
#include "../components/SpriteComponent.h"
#include "../components/InputComponent.h"


Ship::Ship(Game* game)
    :Actor(game)
{

    // Create a sprite component
    SpriteComponent* sc = new SpriteComponent(this, 150);
    sc->SetTexture(game->GetTexture("Assets/Asteroid/Ship.png"));

    // Create an input component and set keys/speed
    InputComponent* ic = new InputComponent(this);
    ic->SetForwardKey(SDL_SCANCODE_W);
    ic->SetBackKey(SDL_SCANCODE_S);
    ic->SetClockWiseKey(SDL_SCANCODE_A);
    ic->SetCounterClockWiseKey(SDL_SCANCODE_D);
    ic->SetMaxForwardSpeed(300.0f);
    ic->SetMaxAngularSpeed(Math::TwoPi);
}

void Ship::UpdateActor(float deltaTime)
{
    std::ignore =deltaTime;
}

void Ship::ActorInput(const uint8_t* keyState)
{
    std::ignore =keyState;
}