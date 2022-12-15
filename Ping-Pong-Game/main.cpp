#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/ball.h"
#include "include/paddle.h"
#include "include/ScoreBoard.h"
#include <SFML/Audio.hpp>

int main()
{
    bool play = false;
    bool active = true;
    //Window
    sf::RenderWindow window({1280, 720, 32}, "Ping-Pong");

    //ScoreBoard
    ScoreBoard scoreBoard({570,50});
    scoreBoard.setScoreBoard();

    //Ball
    ball circle(15);
    circle.setPosition(630,350);
    circle.setVelocity({.1, -.13});

    //Left Paddle
    paddle paddleLeft(12,125);
    paddleLeft.setPosition(15,200);
    paddleLeft.setPaddle();

    //Right Paddle
    paddle paddleRight(12,120);
    paddleRight.setPosition(window.getSize().x - 25,100);
    paddleRight.setPaddle();

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && active){
            play = !play;
        }
        if(play){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                paddleRight.movePaddleUp(window.getSize());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                paddleRight.movePaddleDown(window.getSize());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                paddleLeft.movePaddleUp(window.getSize());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                paddleLeft.movePaddleDown(window.getSize());
            }
            // circle.bounce(window.getSize());
            active  = false;
            circle.bounce(window.getSize(), paddleLeft.getGlobalBounds(), paddleRight.getGlobalBounds());
        }
        window.clear(sf::Color::Black);
        scoreBoard.updateScoreBoard(window.getSize(), circle.getGlobalBounds());
        if(circle.getGlobalBounds().left + circle.getGlobalBounds().width >= window.getSize().x || circle.getGlobalBounds().left <= 0 ){
            circle.setPosition(630,350);
            play = !play;
            active  = !active;
        }
        window.draw(circle);
        window.draw(paddleLeft);
        window.draw(paddleRight);
        window.draw(scoreBoard);
        window.display();
    }
    return 0;
}