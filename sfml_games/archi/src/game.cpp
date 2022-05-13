//
// Created by mike on 13/05/2022.
//

#include "../headers/game.h"
#include <iostream>

Game::Game()
    :_window(sf::VideoMode(800,600),"Archi"),
     _player(20)
     {
//        _window.setFramerateLimit(120);
        _player.setFillColor(sf::Color::Blue);
        _player.setPosition(10,20);

     }

void Game::run(bool animate,int fps)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.0f/fps);

    while(_window.isOpen())
    {
        processEvents();
        bool repaint = false;
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            repaint = true;
            if(!animate)
                update(TimePerFrame);
            else
                do_animation(TimePerFrame);
        }

        if(repaint)
            render();
    }
}

void Game::update_player(float x, sf::Color color)
{
    _player.setRadius(_player.getRadius() + x);
    _player.setFillColor(color);
}

void Game::do_animation(sf::Time deltaTime)
{
    if(_player.getRadius() <= rThresh && direction)
        update_player(0.5f,sf::Color::Blue);
    else if(_player.getRadius() != 0)
    {
        direction = false;
        update_player(-0.5f,sf::Color::Green);
    }
    else
        direction = true;
//    std::cout<<_player.getRadius()<<"\n";
}

void Game::processEvents()
{
    sf::Event event;
    while(_window.pollEvent(event))
    {
        if((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed)
            && event.key.code == sf::Keyboard::Escape)
            _window.close();
    }
}

void Game::update(sf::Time deltaTime) {}

void Game::render()
{
    _window.clear();
    _window.draw(_player);
    _window.display();
}

