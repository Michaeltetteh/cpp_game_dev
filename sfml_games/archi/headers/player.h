#ifndef ARCHI_PLAYER_H
#define ARCHI_PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
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
    bool isMoving;
    int rotation;

private:
    virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const override;
    sf::RectangleShape  _shape;
    sf::Vector2f        _velocity;
};

#endif //ARCHI_PLAYER_H
