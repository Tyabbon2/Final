// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>
#include <vector>

using namespace std;

class Player {
public:
    Player(const string& name, int initialBalance);

    void addCard(Card* card);

    void displayHand(bool showAll) const; // Add parameter to control card visibility

    void placeBet();

    int getHandStrength() const;

    void collectWinnings(int winnings);

    void collectDebt(int winnings);

    const string& getName() const;

    int getBalance() const;

    int getBet() const;

    void resetBalance(int initialBalance);

    void clearHand();



private:
    string name;
    int balance;
    int bet;
    vector<Card*> hand;
};

//Player_H

//AI Player

class AIPlayer : public Player {
public:
    AIPlayer(const std::string& name, int initialBalance);

};

#endif // PLAYER_H
