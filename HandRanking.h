// HandRanking.h
#ifndef HANDRANKING_H
#define HANDRANKING_H

#include <vector>
#include "Card.h"

enum class HandRank {
    HighCard,
    OnePair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush
};

class HandRanking {
public:
    static HandRank rankHand(const std::vector<Card*>& hand, const std::vector<Card*>& communityCards);

private:
    static bool isFlush(const std::vector<Card*>& allCards);
    static bool isStraight(const std::vector<Card*>& allCards);
    static HandRank evaluateStraightFlush(const std::vector<Card*>& allCards);
    static HandRank evaluateFourOfAKind(const std::vector<Card*>& allCards);
    static HandRank evaluateFullHouse(const std::vector<Card*>& allCards);
    static HandRank evaluateFlush(const std::vector<Card*>& allCards);
    static HandRank evaluateStraight(const std::vector<Card*>& allCards);
    static HandRank evaluateThreeOfAKind(const std::vector<Card*>& allCards);
    static HandRank evaluateTwoPair(const std::vector<Card*>& allCards);
    static HandRank evaluateOnePair(const std::vector<Card*>& allCards);
    static HandRank evaluateHighCard(const std::vector<Card*>& allCards);
};

#endif // HANDRANKING_H
