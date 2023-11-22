// CardDealer.h
#ifndef CARD_DEALER_H
#define CARD_DEALER_H

#include "Deck.h"
#include "Player.h"

class CardDealer {
public:
    CardDealer(Deck& deck, Player& player, AIPlayer& aiPlayer);

    void dealInitialCards();

    void dealFlop();

    void dealTurn();

    void dealRiver();

    void bettingRound(Player& currentPlayer);

    void displayCommunityCards() const;

    void clearCommunityCards();

    vector<Card*>& getCommunityCards();

private:
    Deck& deck;
    Player& player;
    AIPlayer& aiPlayer;
    vector<Card*> communityCards;
    bool endRound;

};

#endif // CARD_DEALER_H

