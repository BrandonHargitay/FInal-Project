#include <SFML/Graphics.hpp>
#include "Asteroids_Game_Runner.h"
#include "Rocket.h"
#include "Asteroids.h"
#include "SpaceshipGun.h"

#include "Health.h"
#include "ScoreBoard2.h"

void Asteroids_Game_Runner::run() {

    std::cout << "Test";
    srand((unsigned int)time(NULL));
    sf::RenderWindow window2(sf::VideoMode(1080, 1920), "test");
    sf::Sprite background;
    background.setTexture(Texture::getTexture(BACKGROUND));
    //background.setScale(23,23);

    float xScale = static_cast<float>(window2.getSize().x) / background.getTexture()->getSize().x;
    float yScale = static_cast<float>(window2.getSize().y) / background.getTexture()->getSize().y;
    background.setScale(xScale, yScale);

    Rocket Rocket;
    Asteroids Asteroid;
    SpaceshipGun Gun;
    sf::Clock clock;
    Health health;
    ScoreBoard2 score({800, 10});
    score.setScoreBoard();

    while (window2.isOpen())
    {
        sf::Event event;
        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window2.close();
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)){
                window2.close();
            }
            Gun.fire(window2, event, Rocket.getPosition(), Rocket.getRotation() );

        }

        if(clock.getElapsedTime().asSeconds() >= 1.0f){
            Asteroid.createAsteroid();
            clock.restart();
        }

        window2.clear();
        window2.draw(background);
        Asteroid.update(window2);
        score.updateScoreBoard(Gun.getScore());
        Rocket.move(window2, event);
        health.update(Gun.update(window2, Asteroid.getVector(), Rocket.getGlobalBounds()));
        window2.draw(Rocket);
        window2.draw(Asteroid);
        window2.draw(Gun);
        window2.draw(health);
        window2.draw(score);
        window2.draw(score);
        window2.display();
    }

}
