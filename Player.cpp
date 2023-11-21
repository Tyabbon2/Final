// Player.cpp
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const string& name, int initialBalance) : name(name), balance(initialBalance), bet(0) {}

void Player::addCard(Card* card) {
    hand.push_back(card);
}

void Player::displayHand(bool showAll) const {
    cout << name << "'s hand: ";
    for (const Card* card : hand) {
        if (showAll) {
            card->display();
        }
        else {
            cout << "Hidden "; // Display "Hidden" for AI player's cards
        }
        cout << "  ";
    }
    cout << endl;
}

void Player::placeBet() {
    cout << name << ", your current balance is $" << balance << ". Enter your bet: $";
    cin >> bet;
    while (bet < 0 || bet > balance) {
        cout << "Invalid bet. Enter a bet between 0 and $" << balance << ": $";
        cin >> bet;
    }
    balance -= bet;
}

int Player::getHandStrength() const {
    int strength = 0;
    for (const Card* card : hand) {
        strength += card->getRank();
    }
    return strength;
}

void Player::collectWinnings(int winnings) {
    balance += winnings;
}

const string& Player::getName() const {
    return name;
}

int Player::getBalance() const {
    return balance;
}

int Player::getBet() const {
    return bet;
}

void Player::resetBalance(int initialBalance) {
    balance = initialBalance;
}

void Player::clearHand() {
    hand.clear();
}


//AI Player

AIPlayer::AIPlayer(const string& name, int initialBalance) : Player(name, initialBalance) {

}

