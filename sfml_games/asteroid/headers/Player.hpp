#ifndef ARCHI_PLAYER_HPP
#define ARCHI_PLAYER_HPP


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
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
        _ship.setPosition(std::forward<Args>(args)...);
    }

    void update(sf::Time deltaTime);
    void processEvents();

    enum PlayerInputs{UP,LEFT,RIGHT};
    static void setDefaultInputs();
    const sf::Vector2f &getPosition() const;

private:

    virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const override;

    sf::Sprite  _ship;
    sf::Vector2f        _velocity;
    bool _isMoving;
    int _rotation;

    static ActionMap<int> _playerInputs;
};

#endif //ARCHI_PLAYER_HPP
