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
    void run_vts(bool animate=false); //using variable time steps
    void run_fts(bool animate=false,int fps=60); //using fixed time steps
    void run_mts(bool animate=false,int minimum_frame_per_second=60); //using minimum time steps

    void do_animation(sf::Time deltaTime);

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    sf::RenderWindow _window;
    sf::CircleShape _player;

    //for do_animations
    bool direction = true;
    const float rThresh = 150;
    void update_player(float x,sf::Color color);
};

#endif //ARCHI_GAME_H
