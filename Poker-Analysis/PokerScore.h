//
// Created by Brandon Hargitay on 11/8/22.
//

#ifndef POKER_POKERSCORE_H
#define POKER_POKERSCORE_H
#include "CardHand.h"
#include <vector>

class PokerScore {
public:
    enum Scores{

        ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

        STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

        FOUR_OF_A_KIND, //four cards of the same ranking

        FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

        FLUSH, //five cards of the same suit

        STRAIGHT, //five cards in consecutive ranking

        THREE_OK_A_KIND, //three cards of the same rank

        TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

        ONE_PAIR, //two cards of the same rank

        HIGH_CARD //highest card in the player’s hand

    };
    static bool isRoyalFlush(CardHand hand);
    static bool isStraightFLush(CardHand hand);
    static bool isFourOfKind(CardHand hand);
    static bool isFullHouse(CardHand hand);
    static bool isFlush(CardHand hand);
    static bool isStraight(CardHand hand);
    static bool isThreeofKind(CardHand hand);
    static bool isTwoPair(CardHand hand);
    static bool isOnePair(CardHand hand);
    static bool isHighCard(CardHand hand);
    static void addScore(Scores score);
    static std::array<int,10> getScores();
    void operator+=(const Scores& score);
    friend bool operator==(const PokerScore& p, Scores score);
    friend std::ostream& operator<<(std::ostream& out, const PokerScore& s);
private:

};


#endif //POKER_POKERSCORE_H
