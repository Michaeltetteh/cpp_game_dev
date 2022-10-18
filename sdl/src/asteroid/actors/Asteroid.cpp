#include "Asteroid.h"
#include "../components/SpriteComponent.h"
#include "../Game.h"
#include "../components/MoveComponent.h"
#include "../utils/Random.h"
#include "../components/CircleComponent.h"

#define ZERO_VEC2  Vector2(0.0f, 0.0f)


Asteroid::Asteroid(Game *game)
        : Actor(game)
{
    Vector2 randPos = Random::GetVector(ZERO_VEC2,Vector2(1024.0f, 768.0f));
    SetPosition(randPos);
    SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

    //load sprite
    SpriteComponent *sc = new SpriteComponent(this);
    sc->SetTexture(game->GetTexture("Assets/Asteroid/Asteroid.png"));

    //movement
    MoveComponent *mc = new MoveComponent(this);
    mc->SetForwardSpeed(150.0f);

    //attach a circle component to asteroid
    mCircle = new CircleComponent(this);
    // mCircle->SetRadius(40.0f);
}

Asteroid::~Asteroid()
{

}