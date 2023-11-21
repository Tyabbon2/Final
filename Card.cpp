// Card.cpp
#include "Card.h"
#include <iostream>

using namespace std;

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

//function to display card number and suit
void Card::display() const {
    cout << getRankString() << " of " << getSuitString();
}

int Card::getRank() const {
    return rank;
}

//Function to get the suit 
string Card::getSuitString() const {
    switch (suit) {
    case HEARTS:   return "Hearts";
    case DIAMONDS: return "Diamonds";
    case CLUBS:    return "Clubs";
    case SPADES:   return "Spades";
    default:       return "Unknown";
    }
}


string Card::getRankString() const {
    switch (rank) {
    case ACE:   return "A";
    case JACK:  return "J";
    case QUEEN: return "Q";
    case KING:  return "K";
    default:    return to_string(rank);
    }
}