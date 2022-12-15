//
// Created by Brandon Hargitay on 12/14/22.
//

#ifndef FINAL_PROJECT_GAMESQUARE_H
#define FINAL_PROJECT_GAMESQUARE_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "AppsEnum.h"
#include "Asteroids_Game_Runner.h"
#include "Ping_Pong_Game_Runner.h"
#include "Top_Hat_Guy_Runner.h"
#include "Poker_Analysis_Runner.h"
#include "Card_Runner.h"
#include "Green_Circle_Runner.h"
#include "AppDetails.h"

class GameSquare : public sf::Drawable, public sf::Transformable{
public:
    GameSquare();
    void getGlobalBounds();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void clicked(sf::RenderWindow &window);
    void runGame(const AppsEnum& app);
    void setEnum( AppsEnum a);
    void setPosition(sf::Vector2f pos);
    void setPosition2(float x, float y);
    void setName(std::string name);
private:
    sf::Text gameTitle;
    sf::Text appSummary;
    sf::RectangleShape square;
    sf::Font font;
    AppsEnum app;
};


#endif //FINAL_PROJECT_GAMESQUARE_H
