//
// Created by Brandon Hargitay on 11/7/22.
//

#ifndef POKER_CARDHANDSCORER_H
#define POKER_CARDHANDSCORER_H
#include <iostream>
#include <algorithm>
#include "CardHand.h"
#include "PokerScore.h"


class CardHandScorer {
public:
    static PokerScore handScore(CardHand hand);
    static void displayScored(const PokerScore& score);
    void sort(CardHand &hand);
private:

};


#endif //POKER_CARDHANDSCORER_H
