//
// Created by Brandon Hargitay on 12/14/22.
//

#include "Ping_Pong_Game_Runner.h"

void Ping_Pong_Game_Runner::run() {



        bool play = false;
        bool active = true;
        //Window
        sf::RenderWindow window({1280, 720, 32}, "Ping-Pong");

        //ScoreBoard2
        ScoreBoard scoreBoard2({570, 50});
        scoreBoard2.setScoreBoard2();

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
                if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)){
                    window.close();
                }
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
            scoreBoard2.updateScoreBoard(window.getSize(), circle.getGlobalBounds());
            if(circle.getGlobalBounds().left + circle.getGlobalBounds().width >= window.getSize().x || circle.getGlobalBounds().left <= 0 ){
                circle.setPosition(630,350);
                play = !play;
                active  = !active;
            }
            window.draw(circle);
            window.draw(paddleLeft);
            window.draw(paddleRight);
            window.draw(scoreBoard2);
            window.display();
        }
}
