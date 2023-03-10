//
// Created by Jessie Mejia on 10/10/22.
//

#ifndef UNTITLED_BALL_H
#define UNTITLED_BALL_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class ball : public sf::CircleShape
{
    private:
        sf::Vector2f velocity;
        sf::SoundBuffer buffer;
        sf::Sound sound;
    public:
        ball(float radius);
        void bounce(const sf::Vector2u& windowSize,sf::FloatRect leftPaddle, sf::FloatRect rightPaddle);
        void setVelocity(sf::Vector2f velocity);
        void changeColor();
};


#endif //UNTITLED_BALL_H
