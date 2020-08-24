// Player.h
// Version 1.0
// Implements a Monopoly player

#ifndef PROBABLY_MONOPOLY_PLAYER_H
#define PROBABLY_MONOPOLY_PLAYER_H

#include "CircularList.h"

const int NUMBER_OF_SQUARES = 40;

class Player {
public:
    unsigned long long int board[NUMBER_OF_SQUARES];
    int position;   // position of the player on the board

    Player();

    // returns the new player position
    int move(int steps);    // moves the player of n steps

    // returns the new player position
    int move(CardsEffect square);  // moves the player to square
};


#endif //PROBABLY_MONOPOLY_PLAYER_H
