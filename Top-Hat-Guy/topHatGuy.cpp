//
// Created by Sherman Yan on 10/19/22.
//

#include "topHatGuy.h"

void topHatGuy::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    states.transform = getTransform();
    window.draw(shirt);
    window.draw(face);
    window.draw(top,states);
    window.draw(brim,states);

}


topHatGuy::topHatGuy() {

    sf::Color fill = sf::Color::White;

    top.setSize({60, 50});
    brim.setSize({90, 10});
    face.setRadius(30);

    shirt.setPointCount(3);
    shirt.setRadius(100);
    shirt.setPosition(420,500);
    shirt.setScale(0.7,0.7);

    sf::FloatRect facePos = face.getGlobalBounds();

    brim.setPosition(facePos.left-((brim.getGlobalBounds().width - facePos.width) /2), (facePos.top + (facePos.height/2)) - brim.getGlobalBounds().height -10 );
    top.setPosition(facePos.left, brim.getPosition().y - top.getSize().y);


    top.setFillColor(sf::Color::Blue);
    brim.setFillColor(sf::Color::Blue);
    face.setFillColor(fill);
    shirt.setFillColor(sf::Color::Green);

}

void topHatGuy::setPosition(sf::Vector2f pos) {

    sf::Transformable::setPosition(pos);
    face.setPosition(pos);
}

void topHatGuy::setPosition(float x, float y) {
    setPosition({x, y});
}
