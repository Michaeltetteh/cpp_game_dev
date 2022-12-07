
#include "Actor.h"
#include "../Game.h"
#include "../components/Component.h"
#include <algorithm>

Actor::Actor(Game* game)
    :mState(EActive)
    , mRecomputeWorldTransform(true)
    , mPosition(Vector2::Zero)
    , mScale(1.0f)
    , mRotation(0.0f)
    , mGame(game)
{
    mGame->AddActor(this);
}

Actor::~Actor()
{
    mGame->RemoveActor(this);
    // Need to delete components
    // Because ~Component calls RemoveComponent, need a different style loop
    while (!mComponents.empty())
    {
        delete mComponents.back();
    }
}

void Actor::Update(float deltaTime)
{
    if (mState == EActive)
    {
        ComputeWorldTransform();

        UpdateComponents(deltaTime);
        UpdateActor(deltaTime);

        ComputeWorldTransform();
    }
}

void Actor::UpdateComponents(float deltaTime)
{
    for (auto comp : mComponents)
    {
        comp->Update(deltaTime);
    }
}

void Actor::UpdateActor(float deltaTime){ std::ignore = deltaTime;}

void Actor::AddComponent(Component* component)
{
    // Find the insertion point in the sorted vector
    // (The first element with a order higher than me)
    int myOrder = component->GetUpdateOrder();
    auto iter = mComponents.begin();
    for (;
        iter != mComponents.end();
        ++iter)
    {
        if (myOrder < (*iter)->GetUpdateOrder())
        {
            break;
        }
    }

    // Inserts element before position of iterator
    mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component)
{
    auto iter = std::find(mComponents.begin(), mComponents.end(), component);
    if (iter != mComponents.end())
    {
        mComponents.erase(iter);
    }
}

void Actor::ProcessInput(const uint8_t *keyState)
{
    if(mState == State::EActive)
    {
        for(auto comp: mComponents)
            comp->ProcessInput(keyState);
        ActorInput(keyState);

    }
}

void Actor::ActorInput(const uint8_t *keyState)
{
    std::ignore =keyState;
}

void Actor::ComputeWorldTransform()
{
    if(mRecomputeWorldTransform)
    {
        mRecomputeWorldTransform = false;
        //order (scale * rotation * translation)
        mWorldTransform = Matrix4::CreateScale(mScale);
        mWorldTransform *= Matrix4::CreateRotationZ(mRotation);
        mWorldTransform *= Matrix4::CreateTranslation(Vector3(mPosition.x,mPosition.y,0.0f));

        for(auto component : mComponents)
            component->OnUpdateWorldTransform(); //inform components when actor world transform changes
    }
}