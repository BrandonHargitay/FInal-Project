//
// Created by Brandon Hargitay on 11/6/22.
//

#include "Deck.h"

Card Deck::dealCard() {
    return deck[cardIndex++];
}

Card Deck::getCardAt(int index) {
    return deck[index];
}

Deck::Deck() : cardIndex(0){
    init();
}

void Deck::shuffle() {

    for (int i = 0; i < DECK_SIZE; i++) {
        int idx = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[idx];
        deck[idx] = temp;
    }
}

bool Deck::empty() {
    return false;
}

void Deck::fillDeck() {

    int index = 0;
    for (int i = 0; i < SUIT_MAX; i++) {
        for (int j = 0; j < RANK_MAX; j++) {
            //assigns card to deck by casting i into a SuiteEnum and j into a RankEnum
            deck[index] = Card(static_cast<SuitENum>(i), static_cast<RankENum>(j+1));
            index++;
        }

    }
}

void Deck::init() {
    fillDeck();
    shuffle();
}

std::ostream& operator<<(std::ostream& out, const Deck& deck){
    for (int i = 0; i < deck.DECK_SIZE ; i++) {
        out << "\n" << i + 1 << ": " << deck.deck[i].rankToString() << " of " << deck.deck[i].suitToString();
    }
    return out;
}