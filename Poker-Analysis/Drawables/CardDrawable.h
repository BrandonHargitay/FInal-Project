//
// Created by Brandon Hargitay on 10/25/22.
//

#ifndef POKER_CARDDRAWABLE_H
#define POKER_CARDDRAWABLE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../Deck.h"
#include "../RankENum.h"
#include "../SuitENum.h"

class CardDrawable : public sf::Drawable, sf::Transformable{
private:
    sf::RectangleShape background;
    sf::Text rank;
    sf::Text rank2;
    sf::Sprite suit;
    sf::Vector2f cardPosition;
    sf::Texture texture;
    static sf::Texture heart;
    static sf::Texture diamonds;
    static sf::Texture clubs;
    static sf::Texture spades;
    static sf::Font font;
    SuitENum _suit;
    RankENum _rank;
    void setupRank();
    void setupSuit();
public:
    CardDrawable();
    CardDrawable(SuitENum suit, RankENum rank);
    void setupBackground();
    void init();
    std::string rankToString() const;
    std::string suitToString()const;
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


#endif //POKER_CARDDRAWABLE_H
