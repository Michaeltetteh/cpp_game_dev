#include "Ship.h"
//#include "../components/AnimSpriteComponent.h"
#include "../Game.h"
#include "../components/SpriteComponent.h"
#include "../components/InputComponent.h"
#include "Laser.h"
#include "../components/CircleComponent.h"
#include "Asteroid.h"


Ship::Ship(Game* game)
    :Actor(game),
     mLaserCooldown(0.0f)
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

    mShipCircle = new CircleComponent(this);
    mShipCircle->SetRadius(40.0f);

}

void Ship::UpdateActor(float deltaTime)
{
    mLaserCooldown -= deltaTime;
    for (auto ast : GetGame()->GetAsteroids())
    {
        if (Intersects(*mShipCircle, *(ast->GetCircle())))
        {
            // SetState(EDead);
            ast->SetState(EDead);
        }
    }
}

void Ship::ActorInput(const uint8_t* keyState)
{
    if (keyState[SDL_SCANCODE_SPACE] && mLaserCooldown <= 0.0f)
    {
        // Create a laser and set its position/rotation to mine
        Laser* laser = new Laser(GetGame());
        laser->SetPosition(GetPosition());
        laser->SetRotation(GetRotation());

        // Reset laser cooldown (half second)
        mLaserCooldown = 0.5f;
    }
}
