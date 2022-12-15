//
// Created by Brandon Hargitay on 11/6/22.
//

#ifndef POKER_CARDHAND_H
#define POKER_CARDHAND_H
#include "Deck.h"
#include <vector>

class CardHand {
public:
    CardHand();
    void addCard(Card card);
    Card getNextCard(int cardIndex) const;
    int getSize();
    std::vector<Card> getHand();
    void sort();
private:
    std::vector<Card> hand; //array of players Cards
    int cardIndex;
    friend std::ostream& operator<<(std::ostream& out, const CardHand& hand);

};



#endif //POKER_CARDHAND_H
