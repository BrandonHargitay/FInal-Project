//
// Created by Brandon Hargitay on 12/14/22.
//

#include "GameSquare.h"



GameSquare::GameSquare() {
    square.setSize(sf::Vector2f(200, 100));
    //square.setPosition(50,50);
    square.setFillColor({145,204,241});
    font.loadFromFile("Asteroids-Game/Fonts/Pixellari.ttf");

    sf::FloatRect squarePos = square.getGlobalBounds();
    gameTitle.setFont(font);
    gameTitle.setString("Game");
    gameTitle.setCharacterSize(32);
    gameTitle.setFillColor(sf::Color::White);
    gameTitle.setPosition(squarePos.left + 13, squarePos.top +25);

    appSummary.setFont(font);

}

void GameSquare::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(square);
    target.draw(gameTitle);
    target.draw(appSummary);
}

void GameSquare::getGlobalBounds() {
    square.getGlobalBounds();
}

void GameSquare::clicked(sf::RenderWindow &window) {
    if (MouseEvents::isHover(square, window)){
        square.setOutlineColor(sf::Color::White);
        square.setOutlineThickness(5);

        appSummary.setString(AppDetails::getAppSummary(app));
        appSummary.setFillColor(sf::Color::White);
        appSummary.setPosition(square.getGlobalBounds().left + square.getGlobalBounds().width + 10,square.getGlobalBounds().top + 35);
        if(MouseEvents::isClick(square, window)){
            runGame(app);
        }
    }else{
        square.setOutlineColor(sf::Color::Transparent);
        square.setOutlineThickness(0);
        appSummary.setPosition(-500,-500);
    }
}

void GameSquare::runGame(const AppsEnum& app) {
    switch (app) {
        case ASTEROID: {
            Asteroids_Game_Runner a;
            a.run();
            break;
        }
        case GREEN_CIRCLE: {
            Green_Circle_Runner g;
            g.run();
            break;
        }
        case PING_PONG: {
            Ping_Pong_Game_Runner p;
            p.run();
            break;
        }
        case POKER: {
            Poker_Analysis_Runner p;
            p.run();
            break;
        }
        case PLAYING_CARD: {
            Card_Runner c;
            c.run();
            break;
        }
        case TOP_HAT_GUY: {
            Top_Hat_Guy_Runner t;
            t.run();
            break;
        }
    }
}

void GameSquare::setEnum(AppsEnum a) {
    app = a;
}

void GameSquare::setPosition2(float x, float y) {
    square.setPosition(x,y);
    setPosition({x,y});
}

void GameSquare::setPosition(sf::Vector2f pos) {
    sf::Transformable::setPosition(pos);
    gameTitle.setPosition(pos.x + 12, pos.y + 25);
}

void GameSquare::setName(std::string name) {
    gameTitle.setString(name);
}






