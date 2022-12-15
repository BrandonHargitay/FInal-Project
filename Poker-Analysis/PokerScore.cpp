//
// Created by Brandon Hargitay on 11/8/22.
//

#include <array>
#include "PokerScore.h"

static std::array<int, 10> scores;
bool PokerScore::isRoyalFlush(CardHand hand) {
    //check if its a flush
    if(!isFlush(hand)) return false;
    //check for A-10-J-Q-K
    if(((hand.getNextCard(0) == RankENum::ACE) && (hand.getNextCard(1) == RankENum::TEN))
       &&((hand.getNextCard(2) == RankENum::JACK) && ((hand.getNextCard(3) == RankENum::QUEEN))
          && (hand.getNextCard(4) == RankENum::KING))) return true;
    return false;
}

bool PokerScore::isStraightFLush(CardHand hand) {
    if(isFlush(hand) && isStraight(hand)){
        return true;
    }
    return false;
}

bool PokerScore::isFourOfKind(CardHand hand) {

    int count = 0;
    for (int i = 0; i < 2; i++)
        if (!(hand.getNextCard(i) == hand.getNextCard(i+3))){
            count++;
        }
    if(count == 1 ) return true;

    return false;

}

bool PokerScore::isFullHouse(CardHand hand) {
    if((hand.getNextCard(0) == hand.getNextCard(1))
       && (hand.getNextCard(1) == hand.getNextCard(2))){
        if(hand.getNextCard(3) == hand.getNextCard(4)){
            return true;
        }
    }else if(hand.getNextCard(0) == hand.getNextCard(1)){
        if((hand.getNextCard(2) == hand.getNextCard(3))
           && (hand.getNextCard(3) == hand.getNextCard(4))){
            return true;
        }
    }else{
        return false;
    }
    return false;
    //if (first thre cards are the same)
        //if (last two cards are the same)
    //else if(first two cards are the same)
        //if(last three cards are the same)
}

bool PokerScore::isFlush(CardHand hand) {
    SuitENum suit = hand.getNextCard(0).getSuit();
    int count = 0;
    for (int i = 1; i < hand.getSize() ; i++){
        if(suit == hand.getNextCard(i).getSuit() ){
            count++;
            if(count == 4) return true;
        }
    }
    return false;

}

bool PokerScore::isStraight(CardHand hand) {
    int count = 0;

    //check for A-10-J-Q-K
    if(((hand.getNextCard(0) == RankENum::ACE) && (hand.getNextCard(1) == RankENum::TEN))
    &&((hand.getNextCard(2) == RankENum::JACK) && ((hand.getNextCard(3) == RankENum::QUEEN))
    && (hand.getNextCard(4) == RankENum::KING))) return true;

    //check combinations that go all the way down to A-2-3-4-5
    for (int i = 0; i < hand.getSize() - 1; i++){
        if(hand.getNextCard(i) + 1 == hand.getNextCard(i+1)){
            count++;
        }
        if(count == 4) return true;
    }
    return false;
}

bool PokerScore::isThreeofKind(CardHand hand) {
    for(int i = 0; i < 3; i++){
        if((hand.getNextCard(i) == hand.getNextCard(i+1))
        && (hand.getNextCard(i+1) == hand.getNextCard(i+2))){
            return true;
        }
    }
    return false;
}
//checl if hand has two pair eg. A A 2 2 J
bool PokerScore::isTwoPair(CardHand hand) {
    int count = 0;
    for (int i = 0; i < hand.getSize() - 1; i++) {
        if(hand.getNextCard(i) == hand.getNextCard(i+1)){
            count++;
            i++;
            if(count == 2) return true;
        }
    }
    return false;
}

//check if hand has a pair ex. A A 4 8 9
bool PokerScore::isOnePair(CardHand hand) {
    for(int i = 0; i < hand.getSize() - 1; i++){
        if(hand.getNextCard(i) == hand.getNextCard(i+1)){
            return true;
        }
    }
    return false;
}

//checks if hand has a high card
bool PokerScore::isHighCard(CardHand hand) {
    if(hand.getSize() > 0 ){
        return true;
    }
    return false;
}

void PokerScore::addScore(Scores score) {
    if(score == HIGH_CARD ) scores[0] = scores[0] + 1;
    if(score == ONE_PAIR ) scores[1] = scores[1] + 1;
    if(score == TWO_PAIR ) scores[2] = scores[2] + 1;
    if(score == THREE_OK_A_KIND ) scores[3] = scores[3] + 1;
    if(score == STRAIGHT ) scores[4] = scores[4] + 1;
    if(score == FLUSH ) scores[5] = scores[5] + 1;
    if(score == FULL_HOUSE ) scores[6] = scores[6] + 1;
    if(score == FOUR_OF_A_KIND ) scores[7] = scores[7] + 1;
    if(score == STRAIGHT_FLUSH ) scores[8] = scores[8] + 1;
    if(score == ROYAL_FLUSH ) scores[9] = scores[9] + 1;
}

std::ostream& operator<<(std::ostream& out, const PokerScore& s){

    out << "High: " << scores[0] << "\n";
    out << "One Pair: " << scores[1] << "\n";
    out << "Two Pair: " << scores[2] << "\n";
    out << "Three Kind: " << scores[3] << "\n";
    out << "Straight: " << scores[4] << "\n";
    out << "Flush: " << scores[5] << "\n";
    out << "Full House: " << scores[6] << "\n";
    out << "Four of a kind: " << scores[7] << "\n";
    out << "Straight Flush: " << scores[8] << "\n";
    out << "Royal Flush: " << scores[9] << "\n";

    return out;
}

std::array<int, 10> PokerScore::getScores() {
    return scores;
}
