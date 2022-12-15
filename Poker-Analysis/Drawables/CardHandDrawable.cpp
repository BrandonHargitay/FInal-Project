//
// Created by Brandon Hargitay on 11/10/22.
//

#include "CardHandDrawable.h"

CardHandDrawable::CardHandDrawable() {

}

void CardHandDrawable::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    states.transform = getTransform();
    for(CardDrawable c : drawableHand){
        window.draw(c);
    }
}

void CardHandDrawable::position() {
//        drawableHand[0].getGlobalBounds().left + drawableHand[0].getGlobalBounds().width;

        drawableHand[0].setPosition({460.f,200.f});
        drawableHand[1].setPosition({660,200.f});
        drawableHand[2].setPosition({860.f,200.f});
        drawableHand[3].setPosition({1060.f,200.f});
        drawableHand[4].setPosition({1260.f,200.f});
}

void CardHandDrawable::addCard(CardDrawable card) {
    drawableHand.push_back(card);
}

std::ostream& operator<<(std::ostream& out, const CardHandDrawable& card){

    for (int i = 0; i < 5; i++){
        out << "\n" << card.drawableHand[i].rankToString() << " of " << card.drawableHand[i].suitToString();
    }
    return out;
}

void CardHandDrawable::setPosition(sf::Vector2f pos) {
    //Transformable::setPosition(pos);
}
