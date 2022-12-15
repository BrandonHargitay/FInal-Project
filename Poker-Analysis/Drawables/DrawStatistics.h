//
// Created by Brandon Hargitay on 11/11/22.
//

#ifndef POKER_DRAWSTATISTICS_H
#define POKER_DRAWSTATISTICS_H
#include <SFML/Graphics.hpp>
#include <array>

class DrawStatistics : public sf::Text{
public:
    void displayStatistics();
    DrawStatistics(double n);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    sf::Font font;
    sf::Text title;
    sf::Text statistics;
    double numberOfHands;
    std::array<std::string,10> scoresToString;
    void convertScoresToStrings();
    void init();
    void displayTitle();

};


#endif //POKER_DRAWSTATISTICS_H
