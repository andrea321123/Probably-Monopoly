// CircularList.h
// Version 1.0
// Implements a circular list used for chance and community chest cards

#ifndef PROBABLY_MONOPOLY_CIRCULARLIST_H
#define PROBABLY_MONOPOLY_CIRCULARLIST_H

#include <vector>

// struct declarations
struct Node {
    int value;
    Node *link;
};

struct CircularList {
    // some cards can move the player to a certain square
    // the int value shows the square where the player would be moved (-1 otherwise)
    std::vector <int> cardValues;
    Node* firstCard;     // link to the first card
    int drawnCards;     // cards already drawn

    // constructor
    CircularList(std::vector <int> cardValues);

    // shuffles the cards deck
    void shuffle();

    // returns the first card of the deck and puts it on the bottom of the deck.
    // it eventually shuffle the deck
    int draw();
};

#endif //PROBABLY_MONOPOLY_CIRCULARLIST_H
