//
// Created by mike on 13/05/2022.
//

#include "../headers/game.h"


Game::Game()
    :_window(sf::VideoMode(800,600),"Archi"),
     _player(150)
     {
        _player.setFillColor(sf::Color::Blue);
        _player.setPosition(10,20);
     }

void Game::run()
{
    while(_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}


