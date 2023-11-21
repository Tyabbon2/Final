// Deck.cpp
#include "Deck.h"
#include "CardDealer.h"
#include <algorithm>
#include <iostream>

using namespace std;

Deck::Deck() {
    initializeDeck();
    shuffleDeck();
}

Deck::~Deck() {
    // Release memory for cards
    for (Card* card : cards) {
        delete card;
    }
}

Card* Deck::drawCard() {
    if (cards.empty()) {
        cerr << "No more cards in the deck! Reinitializing and shuffling." << endl;
        initializeDeck();
        shuffleDeck();
    }

    Card* drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}

void Deck::initializeDeck() {
    // Clear any existing cards
    cards.clear();

    // Add 52 playing cards to the deck
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 1; rank <= 13; ++rank) {
            Card* newCard = new Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
            cards.push_back(newCard);
        }
    }
}

//Function to shuffle the deck
void Deck::shuffleDeck() {
    random_shuffle(cards.begin(), cards.end());
}

//Function to show the cards that have been dealt
void Deck::displayCommunityCards() const {
    for (const Card* card : cards) {
        card->display();
        cout << " ";
    }
}

void Deck::clearCommunityCards() {
    communityCards.clear();
}

