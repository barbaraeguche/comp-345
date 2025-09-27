//
//Part 4: Cards deck/hand
//CardsDriver.cpp
//

#include "Cards.h"

// Stub classes for Player and OrdersList (just so it compiles)
class Player {};
class OrdersList {};

void testCards() {
    std::cout << "\n=== Testing Cards, Deck, and Hand ===" << std::endl;

    Deck deck;
    std::cout << "Initial deck: " << deck << std::endl;
    deck.printDeck();

    Hand hand;
    std::cout << "Initial hand: " << hand << std::endl;

    // Draw 5 cards into hand
    std::cout << "\nDrawing 5 cards from deck..." << std::endl;
    for (int i = 0; i < 5; i++) {
        Card* c = deck.draw();
        if (c) {
            hand.addCard(c);
            std::cout << "Drew: " << *c << std::endl;
        }
    }

    std::cout << "\nHand after drawing: " << hand << std::endl;
    hand.printHand();

    // Simulate playing all cards
    Player* dummyPlayer = new Player();
    OrdersList* dummyOrders = new OrdersList();

    std::cout << "\nPlaying all cards..." << std::endl;
    hand.playAll(dummyPlayer, dummyOrders, &deck);

    std::cout << "\nHand after playing: " << hand << std::endl;
    hand.printHand();

    std::cout << "\nDeck after playing cards: " << deck << std::endl;
    deck.printDeck();

    delete dummyPlayer;
    delete dummyOrders;
}
