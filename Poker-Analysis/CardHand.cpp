//
// Created by Brandon Hargitay on 11/6/22.
//

#include "CardHand.h"

CardHand::CardHand() : cardIndex(0) {}

void CardHand::addCard(Card card) {
    hand.push_back(card);
}

Card CardHand::getNextCard(int cardIndex )const  {
    return hand[cardIndex];
}

std::vector<Card> CardHand::getHand()  {
    return hand;
}

std::ostream& operator<<(std::ostream& out, const CardHand& hand){
    //std::sort(temp.getHand().begin(), temp.getHand().end());
    for (int i = 0; i < 5; i++) {
        out << "\nHAND: " << hand.hand[i].rankToString() << " of " << hand.getNextCard(i).suitToString();
    }
    out << "\n";
    return out;
}

int CardHand::getSize() {
    return hand.size();
}

void CardHand::sort() {
    std::sort(hand.begin(), hand.end());
}