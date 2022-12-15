//
// Created by Brandon Hargitay on 11/10/22.
//

#ifndef POKER_CARDHANDDRAWABLE_H
#define POKER_CARDHANDDRAWABLE_H
#include "CardDrawable.h"
#include "../CardHand.h"
#include <vector>

class CardHandDrawable : public sf::Drawable{
public:
    CardHandDrawable();
    void addCard(CardDrawable card);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void position();
    void setPosition(sf::Vector2f pos);
private:
    std::vector<CardDrawable> drawableHand;
    friend std::ostream& operator<<(std::ostream& out, const CardHandDrawable& card);
};


#endif //POKER_CARDHANDDRAWABLE_H
