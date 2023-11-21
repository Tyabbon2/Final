// Deck.h
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

using namespace std;

class Deck {
public:
    Deck();

    ~Deck();

    Card* drawCard();

    void shuffleDeck(); // Make shuffleDeck public

    void displayCommunityCards() const;

    void clearCommunityCards();


private:
    vector<Card*> cards;
    vector<Card*> communityCards;

    void initializeDeck();
};

#endif // DECK_H
