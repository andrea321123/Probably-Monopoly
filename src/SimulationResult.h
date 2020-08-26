// SimulationResult.h
// Version 1.0
// POD containing results of the simulation

#include "Player.h"

struct SimulationResult {
    // contains the number of times that players have gone in the sqaure specified by the index
    unsigned long long int board[NUMBER_OF_SQUARES];

    // contains the number of times that dices returned the value specified by the index
    unsigned long long int dice[12+1];
};

#ifndef PROBABLY_MONOPOLY_SIMULATIONRESULT_H
#define PROBABLY_MONOPOLY_SIMULATIONRESULT_H

#endif //PROBABLY_MONOPOLY_SIMULATIONRESULT_H
