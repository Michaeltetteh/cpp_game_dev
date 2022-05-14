#ifndef ARCHI_PLAYER_HPP
#define ARCHI_PLAYER_HPP


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "ActionTarget.hpp"

class Player : public sf::Drawable, public book::ActionTarget<int>
{
public:
    Player(const Player&) =delete;
    Player &operator=(const Player&) = delete;
    Player();

    template<typename ...Args>
    void setPosition(Args&& ...args)
    {
        _shape.setPosition(std::forward<Args>(args)...);
    }

    void update(sf::Time deltaTime);
    void processEvents();

    enum PlayerInputs{UP,LEFT,RIGHT};
    static void setDefaultInputs();

private:

    virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const override;
    sf::RectangleShape  _shape;
    sf::Vector2f        _velocity;
    bool _isMoving;
    int _rotation;

    static ActionMap<int> _playerInputs;
};

#endif //ARCHI_PLAYER_HPP
