//
// Created by Brandon Hargitay on 12/14/22.
//

#include "Green_Circle_Runner.h"

void Green_Circle_Runner::run() {
//test
    sf::RenderWindow window(sf::VideoMode(1180, 1080), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(50, 50);
    shape.setPosition(window.getSize().x/2, window.getSize().y/2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)){
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
