//
// Created by Brandon Hargitay on 12/13/22.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Asteroids_Game_Runner.h"
#include "Ping_Pong_Game_Runner.h"
#include "Top_Hat_Guy_Runner.h"
int main()
{
    //test
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Asteroids_Game_Runner Asteroid;
    Ping_Pong_Game_Runner ping;
    Top_Hat_Guy_Runner topHat;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)){
                Asteroid.run();
                std::cout << "A";
            }
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num1)){
                ping.run();
                std::cout << "P";
            }
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2)){
                topHat.run();
                std::cout << "P";
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}


