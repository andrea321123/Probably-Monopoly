// main.cpp
// Version 1.1
//

#include <iostream>
#include "Board.h"

const int MIN_ARGUMENTS = 2;    // minimum number of arguments needed

int main(int argc, char *argv[]) {
    if (argc -1 < MIN_ARGUMENTS)
        return 0;

    // assign arguments to variables
    int players = atoi(argv[1]);
    int turns = atoi(argv[2]);

    Board board(players);
    SimulationResult result = board.play(turns);

    std::cout << result.toString();
    return 0;
}
