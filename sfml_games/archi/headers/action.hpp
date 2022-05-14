
#ifndef ARCHI_ACTION_HPP
#define ARCHI_ACTION_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

class Action
{
public:
    enum Type
    {
        RealTime    = 1,
        Pressed     = 1<<1,
        Released    = 1<<2
    };

    Action(const sf::Keyboard::Key &key, int type=Type::RealTime|Type::Pressed);
    Action(const sf::Mouse::Button &button,int type=Type::RealTime|Type::Pressed);

    bool test() const;
    Action &operator==(const sf::Event &event) const;
    Action &operator==(const Action &other) const;

private:
    friend class ActionTarget;
    sf::Event _event;
    int _type;
};

#endif //ARCHI_ACTION_HPP
