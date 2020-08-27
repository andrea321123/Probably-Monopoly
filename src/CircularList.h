// CircularList.h
// Version 1.3
// Implements a circular list used for chance and community chest cards

#ifndef PROBABLY_MONOPOLY_CIRCULARLIST_H
#define PROBABLY_MONOPOLY_CIRCULARLIST_H

#include <vector>
#include <random>
#include <string>

// enum declarations
enum CardsEffect {        // where the cards could move the player
    NOTHING,
    GOTO_JAIL,
    OUT_JAIL,
    GO,
    OLD_KENT_ROAD,
    PALL_MALL,
    MARYLEBONE_STATION,
    TRAFALGAR_SQUARE,
    MAYFAIR,
    THREE_STEPS_BEHIND
};

// struct declarations
struct Node {
    CardsEffect value;
    Node *link;
};

struct CircularList {
    // seed for random generation
    std::random_device rd;
    std::mt19937* g;

    std::vector <CardsEffect> cardValues;   // some cards can move the player to a certain square
    Node* firstCard;    // link to the first card
    int drawnCards;     // cards already drawn
    bool jailInDeck;  // true if the go to jail card is still in the deck

    // constructor
    CircularList(std::vector <CardsEffect> cardValues);

    // shuffles the cards deck
    void shuffle();

    // returns the first card of the deck and puts it on the bottom of the deck.
    // it eventually shuffle the deck
    CardsEffect draw();

    // push the go to jail card in the deck (after it's used)
    void pushJailCard();

    // returns the size of the list
    int size();

    // returns a string with the values of the cards
    std::string toString();
};

#endif //PROBABLY_MONOPOLY_CIRCULARLIST_H
