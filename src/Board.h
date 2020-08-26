// Board.h
// Version 1.0
// Implements the whole board with all the players

#ifndef PROBABLY_MONOPOLY_BOARD_H
#define PROBABLY_MONOPOLY_BOARD_H

#include "SimulationResult.h"

class Board {
private:
    int playersNumber;  // number of players that play the simulation

public:
    Board(int playersNumber);

    // play the simulation for turns (parameter) turns
    SimulationResult play(unsigned long long int turns);
};


#endif //PROBABLY_MONOPOLY_BOARD_H
