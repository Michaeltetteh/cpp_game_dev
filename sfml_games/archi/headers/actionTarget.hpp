#ifndef ARCHI_ACTIONTARGET_HPP
#define ARCHI_ACTIONTARGET_HPP

#include <SFML/Window/Event.hpp>
#include <functional>
#include <list>
#include <utility>
#include "action.hpp"

class ActionTarget
{
public:
    using FuncType = std::function<void(const sf::Event&)>;
    ActionTarget();

    void processEvents() const;
    bool processEvent(const sf::Event &event) const;

    void bind(const Action &action,const FuncType &callback);
    void unbind(const Action &action);

private:
    std::list<std::pair<Action,FuncType >> _eventsRealTime;
    std::list<std::pair<Action,FuncType>> _eventsPoll;

};


#endif //ARCHI_ACTIONTARGET_HPP
