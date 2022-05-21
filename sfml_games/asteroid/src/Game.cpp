#include "../headers/Game.hpp"
#include <iostream>
#include <SFML/Window/Event.hpp>


Game::Game(int x, int y)
    :_window(sf::VideoMode(x,y),"Asteroid"),
    _x{x},_y{y}
    {
        _player.setPosition(100,100);
    }


void Game::run_vts(bool animate)
{
    sf::Clock clock;
    while (_window.isOpen())
    {
        processEvents();
//        if(!animate)
        update(clock.restart());
//        else
//            do_animation(clock.restart());
        render();
    }
}

void Game::run_mts(bool animate,int minimum_frame_per_second)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.0f/minimum_frame_per_second);

    while (_window.isOpen())
    {
        processEvents();
        timeSinceLastUpdate = clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
//            animate ? do_animation(TimePerFrame) :update(TimePerFrame);
        }
        update(timeSinceLastUpdate);
//        animate ? do_animation(timeSinceLastUpdate) :update(timeSinceLastUpdate);
        render();
    }
}

void Game::run_fts(bool animate,int fps)
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
            update(TimePerFrame);
//            !animate ?update(TimePerFrame) :do_animation(TimePerFrame);
        }
        if(repaint)
            render();
    }
}

//void Game::update_player(float x, sf::Color color)
//{
//    _player.setRadius(_player.getRadius() + x);
//    _player.setFillColor(color);
//}

//void Game::do_animation(sf::Time deltaTime)
//{
//    if(_player.getRadius() <= rThresh && direction)
//        update_player(0.5f,sf::Color::Blue);
//    else if(_player.getRadius() != 0)
//    {
//        direction = false;
//        update_player(-0.5f,sf::Color::Green);
//    }
//    else
//        direction = true;
//   std::cout<<_player.getRadius()<<"\n";
//    std::cout<<deltaTime.asSeconds()<<"\n";
//}

void Game::processEvents()
{
    sf::Event event;
    while(_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            _window.close();
        else if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
                _window.close();
        }
    }
    _player.processEvents();
}

void Game::update(sf::Time deltaTime)
{
    _player.update(deltaTime);
    sf::Vector2f player_pos = _player.getPosition();
    if(player_pos.x < 0)
    {
        player_pos.x = _x;
        player_pos.y = _y - player_pos.y;
    }
    else if(player_pos.x > _x)
    {
        player_pos.x = 0;
        player_pos.y = _y - player_pos.y;
    }
    if(player_pos.y < 0)
        player_pos.y = _y;
    else if(player_pos.y > _y)
        player_pos.y = 0;

    _player.setPosition(player_pos);
}

void Game::render()
{
    _window.clear();
    _window.draw(_player);
    _window.display();
}

