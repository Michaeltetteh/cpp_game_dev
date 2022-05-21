#ifndef ARCHI_ACTIONTARGET_HPP
#define ARCHI_ACTIONTARGET_HPP

#include <SFML/Window/Event.hpp>
#include <functional>
#include <list>
#include <utility>
#include "Action.hpp"
#include "ActionMap.hpp"
#include <iostream>

namespace book
{
    template<typename T=int>
    class ActionTarget
    {
    public:
        ActionTarget<T>(const ActionTarget<T>&) = delete;
        ActionTarget<T> &operator=(const ActionTarget<T> &) = delete;


        using FuncType = std::function<void(const sf::Event&)>;
        ActionTarget<T>(const ActionMap<T> &map);

        void processEvents() const;
        bool processEvent(const sf::Event &event) const;

        void bind(const T &key,const FuncType &callback);
        void unbind(const T &key);

    private:
        std::list<std::pair<T,FuncType >> _eventsRealTime;
        std::list<std::pair<T,FuncType>> _eventsPoll;

        const ActionMap<T> & _actionMap;

    };

}

#include "ActionTarget.tpl"

#endif //ARCHI_ACTIONTARGET_HPP
