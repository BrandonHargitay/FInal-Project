//
// Created by Brandon Hargitay on 11/6/22.
//

#ifndef POKER_DECK_H
#define POKER_DECK_H

#include "RankENum.h"
#include "SuitENum.h"
#include "Card.h"
#include <iostream>

class Deck {
public:
    Card dealCard(); // returns the next card in the deck
    Card getCardAt(int index);// gets the Card at the given index
    void shuffle(); // puts cards in random order
    void fillDeck();
    void init();
    Deck(); // this is the constructor
private:

    Card deck[52];// this is your final deck of cards
    const int SUIT_MAX = 4; //number of suits
    const int RANK_MAX = 13; //number of ranks
    const int DECK_SIZE = 52;// this is the size of your deck
    bool empty(); //returns true if deck has no cards
    int cardIndex; //marks the index of the next card in the deck
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console
};

#endif //POKER_DECK_H
