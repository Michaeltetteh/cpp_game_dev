#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include "Math/Math.h"


class Actor
{
public:
    enum State
    {
        EActive,
        EPaused,
        EDead
    };

    Actor(class Game* game);
    virtual ~Actor();

    // Update function called from Game (not overridable)
    void Update(float deltaTime);
    // Updates all the components attached to the actor (not overridable)
    void UpdateComponents(float deltaTime);
    // Any actor-specific update code (overridable)
    virtual void UpdateActor(float deltaTime);

    // Getters/setters
    const Vector2& GetPosition() const { return mPosition; }
    void SetPosition(const Vector2& pos) { mPosition = pos; mRecomputeWorldTransform= true;}
    float GetScale() const { return mScale; }
    void SetScale(float scale) { mScale = scale; mRecomputeWorldTransform = true; }
    float GetRotation() const { return mRotation; }
    void SetRotation(float rotation) { mRotation = rotation; mRecomputeWorldTransform = true; }

    State GetState() const { return mState; }
    void SetState(State state) { mState = state; }

    class Game* GetGame() { return mGame; }

    Vector2 GetForward() const { return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation)); }

    // Add/remove components
    void AddComponent(class Component* component);
    void RemoveComponent(class Component* component);

    void ProcessInput(const uint8_t *keyState);
    virtual void ActorInput(const uint8_t *keyState);

    void ComputeWorldTransform();
    const Matrix4& GetWorldTransform(){ return mWorldTransform;}

private:
    // Actor's state
    State mState;

    // Transform
    Matrix4 mWorldTransform;
    bool mRecomputeWorldTransform;
    Vector2 mPosition;
    float mScale;
    float mRotation;

    std::vector<class Component*> mComponents;
    class Game* mGame;
};

#endif