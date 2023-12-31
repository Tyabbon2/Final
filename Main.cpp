// main.cpp
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "CardDealer.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "HandRanking.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        // Buy-in
        int buyIn;
        cout << "Welcome to Texas Hold'em!\nEnter your buy-in amount (max $100): $";
        cin >> buyIn;

        // Validate buy-in amount
        if (buyIn <= 0 || buyIn > 100) {
            cout << "Invalid buy-in amount. Exiting the game." << endl;
            return 1;
        }

        // Create players, deck, and card dealer
        Player player1("Player 1", buyIn);
        AIPlayer aiPlayer("AI Player", buyIn);
        Deck deck;
        CardDealer cardDealer(deck, player1, aiPlayer);

        while (true) {
            // Reset player and AI player hands
            player1.clearHand();
            aiPlayer.clearHand();

            // Deal initial cards and start the round
            cardDealer.clearCommunityCards();
            cardDealer.dealInitialCards();
            cardDealer.bettingRound(player1);

            // Deal flop
            cardDealer.dealFlop();
            cardDealer.bettingRound(player1);

            // Deal turn
            cardDealer.dealTurn();
            cardDealer.bettingRound(player1);

            // Deal river
            cardDealer.dealRiver();
            cardDealer.bettingRound(player1);

            cout << endl;
            player1.displayHand(true);
            aiPlayer.displayHand(true);
            cout << endl;

            // Evaluate hands

            HandRank player1Ranking = HandRanking::rankHand(player1.getHand(), cardDealer.getCommunityCards());
            HandRank aiPlayerRanking = HandRanking::rankHand(aiPlayer.getHand(), cardDealer.getCommunityCards());

            Player* winner = (player1Ranking > aiPlayerRanking) ? &player1 : &aiPlayer;
            Player* loser = (winner == &player1) ? &aiPlayer : &player1;

            int totalBet = player1.getBet() + aiPlayer.getBet();
            int winnings = 2 * totalBet;
            winner->collectWinnings(winnings);
            loser->collectDebt(totalBet); // Adjust balance for the loser

            cout << winner->getName() << " wins $" << winnings << "!" << endl;

            cout << player1.getName() << "'s balance: $" << player1.getBalance() << endl;
            cout << aiPlayer.getName() << "'s balance: $" << aiPlayer.getBalance() << endl;

            // Ask if players want to play again
            cout << "Do you want to play again? (y/n): ";
            char choice;
            cin >> choice;

            if (choice != 'y' && choice != 'Y') {
                cout << "Thanks!" << endl;
                return 1; // Exit the inner loop, ending the game
            }
            else {
                // Reset player balances and clear community cards for a new round
                player1.resetBalance(buyIn);
                aiPlayer.resetBalance(buyIn);
                cardDealer.clearCommunityCards(); // Clear community cards
                deck.shuffleDeck(); // Shuffle the deck for the new round
            }
        }
    }

    return 0;
}
