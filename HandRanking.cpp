// HandRanking.cpp
#include "HandRanking.h"
#include <algorithm>

HandRank HandRanking::rankHand(const std::vector<Card*>& hand, const std::vector<Card*>& communityCards) {
    std::vector<Card*> allCards = hand;
    allCards.insert(allCards.end(), communityCards.begin(), communityCards.end());

    // Sort cards by rank
    std::sort(allCards.begin(), allCards.end(), [](const Card* a, const Card* b) {
        return a->getRank() < b->getRank();
        });

    if (isFlush(allCards) && isStraight(allCards)) {
        return evaluateStraightFlush(allCards);
    }
    else if (evaluateFourOfAKind(allCards) == HandRank::FourOfAKind) {
        return HandRank::FourOfAKind;
    }
    else if (evaluateFullHouse(allCards) == HandRank::FullHouse) {
        return HandRank::FullHouse;
    }
    else if (isFlush(allCards)) {
        return evaluateFlush(allCards);
    }
    else if (isStraight(allCards)) {
        return evaluateStraight(allCards);
    }
    else if (evaluateThreeOfAKind(allCards) == HandRank::ThreeOfAKind) {
        return HandRank::ThreeOfAKind;
    }
    else if (evaluateTwoPair(allCards) == HandRank::TwoPair) {
        return HandRank::TwoPair;
    }
    else if (evaluateOnePair(allCards) == HandRank::OnePair) {
        return HandRank::OnePair;
    }
    else {
        return evaluateHighCard(allCards);
    }
}

bool HandRanking::isFlush(const std::vector<Card*>& allCards) {
    // Check if all cards have the same suit
    Card::Suit firstSuit = allCards[0]->getSuit();
    return std::all_of(allCards.begin() + 1, allCards.end(), [firstSuit](const Card* card) {
        return card->getSuit() == firstSuit;
        });
}

bool HandRanking::isStraight(const std::vector<Card*>& allCards) {
    // Check if all cards form a straight
    for (size_t i = 1; i < allCards.size(); ++i) {
        if (allCards[i]->getRank() != allCards[i - 1]->getRank() + 1) {
            return false;
        }
    }
    return true;
}

HandRank HandRanking::evaluateStraightFlush(const std::vector<Card*>& allCards) {
    // Check if it's a royal flush
    if (allCards.back()->getRank() == Card::Rank::ACE && allCards.front()->getRank() == Card::Rank::TEN) {
        return HandRank::RoyalFlush;
    }
    return HandRank::StraightFlush;
}

HandRank HandRanking::evaluateFourOfAKind(const std::vector<Card*>& allCards) {
    // Check for four of a kind
    for (size_t i = 0; i <= allCards.size() - 4; ++i) {
        if (allCards[i]->getRank() == allCards[i + 1]->getRank() &&
            allCards[i]->getRank() == allCards[i + 2]->getRank() &&
            allCards[i]->getRank() == allCards[i + 3]->getRank()) {
            return HandRank::FourOfAKind;
        }
    }
    return HandRank::HighCard;
}

HandRank HandRanking::evaluateFullHouse(const std::vector<Card*>& allCards) {
    // Check for full house
    if ((allCards[0]->getRank() == allCards[1]->getRank() && allCards[2]->getRank() == allCards[3]->getRank() &&
        allCards[2]->getRank() == allCards[4]->getRank()) ||
        (allCards[0]->getRank() == allCards[1]->getRank() && allCards[0]->getRank() == allCards[2]->getRank() &&
            allCards[3]->getRank() == allCards[4]->getRank())) {
        return HandRank::FullHouse;
    }
    return HandRank::Flush;  // Not a full house, check for flush
}

HandRank HandRanking::evaluateFlush(const std::vector<Card*>& allCards) {
    return HandRank::Flush;
}

HandRank HandRanking::evaluateStraight(const std::vector<Card*>& allCards) {
    return HandRank::Straight;
}

HandRank HandRanking::evaluateThreeOfAKind(const std::vector<Card*>& allCards) {
    // Check for three of a kind
    for (size_t i = 0; i <= allCards.size() - 3; ++i) {
        if (allCards[i]->getRank() == allCards[i + 1]->getRank() && allCards[i]->getRank() == allCards[i + 2]->getRank()) {
            return HandRank::ThreeOfAKind;
        }
    }
    return HandRank::TwoPair;  // Not three of a kind, check for two pairs
}

HandRank HandRanking::evaluateTwoPair(const std::vector<Card*>& allCards) {
    // Check for two pairs
    if ((allCards[0]->getRank() == allCards[1]->getRank() && allCards[2]->getRank() == allCards[3]->getRank()) ||
        (allCards[0]->getRank() == allCards[1]->getRank() && allCards[3]->getRank() == allCards[4]->getRank()) ||
        (allCards[1]->getRank() == allCards[2]->getRank() && allCards[3]->getRank() == allCards[4]->getRank())) {
        return HandRank::TwoPair;
    }
    return HandRank::OnePair;  // Not two pairs, check for one pair
}

HandRank HandRanking::evaluateOnePair(const std::vector<Card*>& allCards) {
    // Check for one pair
    for (size_t i = 0; i <= allCards.size() - 2; ++i) {
        if (allCards[i]->getRank() == allCards[i + 1]->getRank()) {
            return HandRank::OnePair;
        }
    }
    return HandRank::HighCard;  // Not one pair, evaluate high card
}

HandRank HandRanking::evaluateHighCard(const std::vector<Card*>& allCards) {
    return HandRank::HighCard;
}
