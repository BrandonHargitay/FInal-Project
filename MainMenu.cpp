//
// Created by Brandon Hargitay on 12/14/22.
//

#include "MainMenu.h"

MainMenu::MainMenu() {

    asteroid.setEnum(ASTEROID);
    greenCircle.setEnum((GREEN_CIRCLE));
    pingPong.setEnum(PING_PONG);
    poker.setEnum(POKER);
    playingCard.setEnum(PLAYING_CARD);
    topHatGuy.setEnum(TOP_HAT_GUY);

    greenCircle.setPosition2(10,10);
    topHatGuy.setPosition2(10,140);
    playingCard.setPosition2(10,270);
    pingPong.setPosition2(10,400);
    poker.setPosition2(10, 530);
    asteroid.setPosition2(10,660);






    asteroid.setName("Asteroid");
    greenCircle.setName("Circle");
    pingPong.setName("Pong");
    poker.setName("Poker");
    playingCard.setName("Card");
    topHatGuy.setName("Top Hat Guy");
}
void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(asteroid);
    target.draw(greenCircle);
    target.draw(pingPong);
    target.draw(poker);
    target.draw(playingCard);
    target.draw(topHatGuy);
}



void MainMenu::click(sf::RenderWindow &window) {
    asteroid.clicked(window);
    greenCircle.clicked(window);
    pingPong.clicked(window);
    poker.clicked(window);
    playingCard.clicked(window);
    topHatGuy.clicked(window);
}



