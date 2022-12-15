//
// Created by Brandon Hargitay on 10/25/22.
//

#ifndef PLAYINGCARD_CARD_H
#define PLAYINGCARD_CARD_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "RankENum.h"
#include "SuitENum.h"

class Card : public sf::Drawable, sf::Transformable{
private:
    sf::RectangleShape background;
    sf::Text rank;
    sf::Text rank2;
    sf::Sprite suit;
    sf::Vector2f cardPosition;
    static sf::Texture texture;
    static sf::Font font;
    SuitENum _suit;
    RankENum _rank;
    std::string rankToString();
    std::string suitToString();


    void setupRank();
    void setupSuit();
public:
    Card();
    Card(SuitENum suit, RankENum rank);
    void setupBackground();
    void init();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setFillColor(const sf::Color& color);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);
    void setCardPosition(sf::Vector2f position);
    void setOrigin(float x, float y);
    const sf::Vector2f getOrigin() const;
    const sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds();
    void setPosition(sf::Vector2f position);
};


#endif //PLAYINGCARD_CARD_H
