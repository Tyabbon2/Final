// Card.h
#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
public:
    enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

    Card(Suit suit, Rank rank);

    void display() const;

    int getRank() const;

    Suit getSuit() const;



private:
    Suit suit;
    Rank rank;

    string getSuitString() const;
    string getRankString() const;
};

#endif // CARD_H
