#ifndef AISTATE_H
#define AISTATE_H

class AIState
{

public:
    AIState(class AIComponent *owner)
        :mOwner(owner)
        {}
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void Update(float deltaTime) = 0;

    virtual const char* GetName() const = 0;
protected:
    class AIComponent *mOwner;
};



class AIPatrol: public AIState
{
public:
    AIPatrol(class AIComponent *owner)
        :AIState(owner)
        {}

    void OnEnter() override;
    void OnExit() override;
    void Update(float deltaTime) override;

    const char *GetName() const override
    {
        return "Patrol";
    }
};


class AIDeath: public AIState
{
public:
    AIDeath(class AIComponent *owner)
        :AIState(owner)
        {}

    void OnEnter() override;
    void OnExit() override;
    void Update(float deltaTime) override;

    const char *GetName() const override
    {
        return "Death";
    }
};

class AIAttack: public AIState
{
public:
    AIAttack(class AIComponent *owner)
        :AIState(owner)
        {}

    void OnEnter() override;
    void OnExit() override;
    void Update(float deltaTime) override;

    const char *GetName() const override
    {
        return "Attack";
    }
};

#endif

