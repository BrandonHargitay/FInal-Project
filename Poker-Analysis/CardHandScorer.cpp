//
// Created by Brandon Hargitay on 11/7/22.
//

#include "CardHandScorer.h"



void CardHandScorer::sort(CardHand &hand) {
    std::sort(hand.getHand().begin(), hand.getHand().end());
}

PokerScore CardHandScorer::handScore(CardHand hand) {
    PokerScore s;
    hand.sort();

    if(PokerScore::isHighCard(hand) == 1) s.addScore(PokerScore::HIGH_CARD);
    if(PokerScore::isOnePair(hand) == 1) s.addScore(PokerScore::ONE_PAIR);
    if(PokerScore::isTwoPair(hand) == 1) s.addScore(PokerScore::TWO_PAIR);
    if(PokerScore::isThreeofKind(hand) == 1) s.addScore(PokerScore::THREE_OK_A_KIND);
    if(PokerScore::isStraight(hand) == 1) s.addScore(PokerScore::STRAIGHT);
    if(PokerScore::isFlush(hand) == 1) s.addScore(PokerScore::FLUSH);
    if(PokerScore::isFullHouse(hand) == 1) s.addScore(PokerScore::FULL_HOUSE);
    if(PokerScore::isFourOfKind(hand) == 1) s.addScore(PokerScore::FOUR_OF_A_KIND);
    if(PokerScore::isStraightFLush(hand) == 1) s.addScore(PokerScore::STRAIGHT_FLUSH);
    if(PokerScore::isRoyalFlush(hand) == 1) s.addScore(PokerScore::ROYAL_FLUSH);

    return s;
}
