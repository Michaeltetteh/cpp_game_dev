#ifndef ARCHI_GAME_HPP
#define ARCHI_GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "Player.hpp"
namespace asteroid
{

    class Game
    {
    public:
        Game(const Game &) = delete;
        Game &operator=(const Game &) = delete;

        Game(int x=800,int y=600);
        void run(int minimum_frame_per_second=60); //using minimum time steps

        void initLevel();

    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

        void reset();

        sf::RenderWindow _window;
        World _world;

        sf::Time   _nextSaucer;
        sf::Text   _txt;
    };

}
#endif
