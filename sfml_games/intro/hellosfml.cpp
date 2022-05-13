#include <SFML/Graphics.hpp>
#include<iostream>

bool direction = true;
const float rThresh = 150;

void update_circle(float x,sf::CircleShape &circle,sf::Color color)
{
    circle.setRadius(circle.getRadius()+x);
    circle.setFillColor(color);
//    circle.setPosition(10*x, 20*x);
}

int main(int argc,char* argv[]) {
    sf::RenderWindow window(sf::VideoMode(400,
                                          400),"01_Introduction");
    window.setFramerateLimit(60);
    //create a circle
    sf::CircleShape circle(5);
    update_circle(5,circle,sf::Color::Red);

    //game loop
    while (window.isOpen()) {
        //manage the events
        sf::Event event;
        while(window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) ||
                (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape))
                window.close(); //close the window
        }
        window.clear(); //clear the windows to black
        if(circle.getRadius() <= rThresh && direction)
            update_circle(0.5,circle,sf::Color::Red);
        else if(circle.getRadius() != 0)
        {
            direction = false;
            update_circle(-0.5,circle,sf::Color::Green);
        }
        else
            direction = true;

//        std::cout<<circle.getRadius()<<"\n";
        window.draw(circle); //draw the circle
        window.display(); //display the result on screen
    }
    return 0;
}