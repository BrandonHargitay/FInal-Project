//
// Created by Brandon Hargitay on 11/6/22.
//

#include "Card.h"

Card::Card(SuitENum suit, RankENum rank) : suit(suit), rank(rank) {}

Card::Card() : Card(SPADES, ACE) {}

std::string Card::rankToString() const {
    switch (rank) {
        case ACE: return  "Ace";
        case KING: return  "King";
        case QUEEN: return  "Queen";
        case JACK: return  "Jack";
        case TEN: return  "Ten";
        case NINE: return  "Nine";
        case EIGHT: return  "Eight";
        case SEVEN: return  "Seven";
        case SIX: return  "Six";
        case FIVE: return  "Five";
        case FOUR: return  "Four";
        case THREE: return  "Three";
        case TWO: return  "Two";
    }
}

std::string Card::suitToString() const {
    switch (suit) {
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
        case SPADES: return "Spades";
    }
}
std::ostream& operator<<(std::ostream& out, const Card& card){
    out << "\n" << card.rankToString() << " of " << card.suitToString();
    return out;
}

bool operator>(const Card &c1, const Card &c2) {
    return c1.rank > c2.rank;
}

bool operator<(const Card &c1, const Card &c2) {
    return c1.rank < c2.rank;
}
bool operator==(const Card &c1, const Card &c2) {
    return c1.rank == c2.rank;
}
bool operator==(const Card &c1, const int &n ) {
    return c1.rank == n;
}
bool operator==( const int &n, const Card &c1){
    return c1.rank == n;
}
int operator+(const Card &c1, const int &n){
    return c1.rank + n;
}
int operator+(const int &n,const Card &c1){
    return c1.rank + n;
}

SuitENum Card::getSuit() {
    return suit;
}

RankENum Card::getRank() {
    return rank;
}

