// CardDealer.cpp
#include "CardDealer.h"
#include <iostream>

using namespace std;

CardDealer::CardDealer(Deck& deck, Player& player, AIPlayer& aiPlayer)
    : deck(deck), player(player), aiPlayer(aiPlayer), endRound(false) {}

void CardDealer::dealInitialCards() {
    // Shuffle deck and deal two cards to each player
    deck.shuffleDeck();

    player.clearHand();  // Clear player's hand
    player.addCard(deck.drawCard());
    player.addCard(deck.drawCard());

    aiPlayer.clearHand();  // Clear AI player's hand
    aiPlayer.addCard(deck.drawCard());
    aiPlayer.addCard(deck.drawCard());

    // Display initial cards for the player
    player.displayHand(true);
}

void CardDealer::dealFlop() {
    if (endRound) return;

    cout << "\nDealing the flop..." << endl;
    deck.drawCard(); // Burn a card

    communityCards.push_back(deck.drawCard());
    communityCards.push_back(deck.drawCard());
    communityCards.push_back(deck.drawCard());

    // Display community cards after dealing the flop
    displayCommunityCards();
}

void CardDealer::dealTurn() {
    if (endRound) return;

    cout << "\nDealing the turn..." << endl;
    deck.drawCard(); // Burn a card
    communityCards.push_back(deck.drawCard());

    // Display community cards after dealing the turn
    displayCommunityCards();
}

void CardDealer::dealRiver() {
    if (endRound) return;

    cout << "\nDealing the river..." << endl;
    deck.drawCard(); // Burn a card
    communityCards.push_back(deck.drawCard());

    // Display community cards after dealing the river
    displayCommunityCards();

}

void CardDealer::bettingRound(Player& currentPlayer) {
    char choice;
    cout << currentPlayer.getName() << ", do you want to check (c), bet (b), or fold (f)? ";
    cin >> choice;

    if (choice == 'b' || choice == 'B') {
        currentPlayer.placeBet();
    }
    else if (choice == 'f' || choice == 'F') {
        cout << currentPlayer.getName() << " folds. You lose your bet of $" << currentPlayer.getBet() << endl;
        // Deduct the bet from the player's balance
        currentPlayer.collectWinnings(-currentPlayer.getBet());
        return;
    }


}

void CardDealer::displayCommunityCards() const {
    cout << "Community cards: ";
    for (const Card* card : communityCards) {
        card->display();
        cout << " ";
    }
    cout << endl;
}

//clear the cards
void CardDealer::clearCommunityCards() {
    communityCards.clear();
}