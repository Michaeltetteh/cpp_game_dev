#ifndef ARCHI_PLAYER_HPP
#define ARCHI_PLAYER_HPP


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

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
    void processEvents();

private:

    virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const override;
    sf::RectangleShape  _shape;
    sf::Vector2f        _velocity;
    bool isMoving;
    int rotation;
};

#endif //ARCHI_PLAYER_HPP
