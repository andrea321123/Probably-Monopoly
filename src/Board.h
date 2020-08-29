// Board.h
// Version 1.2
// Implements the whole board with all the players

#ifndef PROBABLY_MONOPOLY_BOARD_H
#define PROBABLY_MONOPOLY_BOARD_H

#include "SimulationResult.h"

#include <mutex>
#include "CircularList.h"

const int JAIL = 10;

class Board {
private:
    int playersNumber;  // number of players that play the simulation
    SimulationResult result;    // results of the simulation
    CircularList communityChest, chance;
    std::mutex mutex;


    void singlePlay(unsigned long long int turns, SimulationResult* results);

public:
    Board(int playersNumber);

    // play the simulation for turns (parameter) turns
    SimulationResult play(unsigned long long int turns);
};


#endif //PROBABLY_MONOPOLY_BOARD_H
