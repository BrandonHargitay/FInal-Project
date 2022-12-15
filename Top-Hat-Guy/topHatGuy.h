//
// Created by Sherman Yan on 10/19/22.
//

#ifndef CS003A_TOPHATGUY_H
#define CS003A_TOPHATGUY_H
#include <SFML/Graphics.hpp>

class topHatGuy: public sf::Drawable, public sf::Transformable{
private:
    sf::RectangleShape top, brim;
    sf::CircleShape shirt;
    sf::CircleShape face;

public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    topHatGuy();
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);


};


#endif //CS003A_TOPHATGUY_H
