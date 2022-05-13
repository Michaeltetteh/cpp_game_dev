//
// Created by mike on 13/05/2022.
//

#ifndef ARCHI_GAME_H
#define ARCHI_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    sf::RenderWindow _window;
    sf::CircleShape _player;

};

#endif //ARCHI_GAME_H
