// SimulationResult.h
// Version 1.1
// POD containing results of the simulation

#include "Player.h"
#include <string>
#include "squareToName.h"

struct SimulationResult {
    // contains the number of times that players have gone in the sqaure specified by the index
    unsigned long long int board[NUMBER_OF_SQUARES];

    // contains the number of times that dices returned the value specified by the index
    unsigned long long int dice[12+1];

    std::string toString() {
        std::string ret = "";

        for (int i = 0; i < NUMBER_OF_SQUARES; i++) {
            // for correct text formatting
            std::string spaces = "";
            for (int j = 0; j < longestNameSize - squareToName[i].size(); j++)
                spaces += " ";

            ret += squareToName[i] + ": " + spaces + std::to_string(board[i]) + " times\n";
        }
        ret += "\n";
        for (int i = 2; i < 12+1; i++)
            ret += std::to_string(i) + ": " + std::to_string(dice[i]) + " times\n";

        return ret;
    }
};

#ifndef PROBABLY_MONOPOLY_SIMULATIONRESULT_H
#define PROBABLY_MONOPOLY_SIMULATIONRESULT_H

#endif //PROBABLY_MONOPOLY_SIMULATIONRESULT_H
