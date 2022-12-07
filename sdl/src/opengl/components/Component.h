#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdint>

class Component
{
public:
    // Constructor
    // (the lower the update order, the earlier the component updates)
    Component(class Actor* owner, int updateOrder = 100);
    // Destructor
    virtual ~Component();
    // Update this component by delta time
    virtual void Update(float deltaTime);

    int GetUpdateOrder() const { return mUpdateOrder; }

    virtual void ProcessInput(const uint8_t *keyState);

    //called when world transform changes
    virtual void OnUpdateWorldTransform(){}

protected:
    // Owning actor
    class Actor* mOwner;
    // Update order of component
    int mUpdateOrder;
};

#endif