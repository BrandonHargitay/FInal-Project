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


//cmake_minimum_required(VERSION 3.23)
//project(Final_Project)
//
//set(CMAKE_CXX_STANDARD 14)
//
//add_executable(Final_Project Asteroids_Game_Runner-Game/Asteroids_Game_Runner-Game-Runner.cpp CreateWindow.cpp CreateWindow.h Asteroids_Game_Runner-Game/Asteroids_Game_Runner-Game-Runner.h main.cpp Asteroids_Game_Runner-Game/Texture.h Asteroids_Game_Runner-Game/Texture.cpp
//        Asteroids_Game_Runner-Game/Enums/textureEnum.h Asteroids_Game_Runner-Game/Rocket.cpp Asteroids_Game_Runner-Game/Rocket.h Asteroids_Game_Runner-Game/Asteroids_Game_Runner.cpp Asteroids_Game_Runner-Game/Asteroids_Game_Runner.h Asteroids_Game_Runner-Game/Bullet.cpp
//        Asteroids_Game_Runner-Game/Bullet.h Asteroids_Game_Runner-Game/ScoreBoard2.cpp Asteroids_Game_Runner-Game/ScoreBoard2.h Asteroids_Game_Runner-Game/Fonts.h Asteroids_Game_Runner-Game/Fonts.cpp Asteroids_Game_Runner-Game/Enums/fontsEnum.h
//        Asteroids_Game_Runner-Game/Heart.cpp Asteroids_Game_Runner-Game/Health.h Asteroids_Game_Runner-Game/states.h Asteroids_Game_Runner-Game/states.cpp Asteroids_Game_Runner-Game/Enums/statesEnum.h Asteroids_Game_Runner-Game/Health.cpp
//        Asteroids_Game_Runner-Game/Health.h Asteroids_Game_Runner-Game/ScoreBoard2.h Asteroids_Game_Runner-Game/ScoreBoard2.cpp Asteroids_Game_Runner-Game/SpaceshipGun.cpp Asteroids_Game_Runner-Game/SpaceshipGun.h)
//
//
//target_link_libraries(Final_Project sfml-graphics sfml-audio)
//find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

