#ifndef ARCHI_PLAYER_HPP
#define ARCHI_PLAYER_HPP


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "ActionTarget.hpp"
#include "Entity.hpp"
#include "../headers/Collision.hpp"

class Player : public Entity, public asteroid::ActionTarget<int>
{
public:
    Player(const Player&) =delete;
    Player &operator=(const Player&) = delete;
    Player(World &world);

    virtual bool isCollide(const Entity &other) const;
    virtual void update(sf::Time deltaTime);
    void shoot();
    void goToHyperspace();
    virtual void onDestroy();

    void processEvents();


private:
    bool _isMoving;
    int _rotation;
    sf::Time _timeSinceLastShoot;

};

#endif