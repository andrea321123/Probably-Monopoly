// Board.cpp
// Version 1.1
//

#include "Board.h"
#include <iostream>
#include <thread>
#include "cards.h"

Board::Board(int playersNumber): chance(chanceVector), communityChest(communityChestVector) {
    Board::playersNumber = playersNumber;

    // init result
    for (int i = 0; i < NUMBER_OF_SQUARES; i++)
        result.board[i] = 0;
    for (int i = 0; i < 12+1; i++)
        result.dice[i] = 0;
}

SimulationResult Board::play(unsigned long long int turns) {
    std::thread threadArray[playersNumber];

    // we create numberOfPlayers threads running singlePlay
    for (int i = 0; i < playersNumber; i++)
        threadArray[i] = std::thread(&Board::singlePlay, this,  turns);

    // we join each thread
    for (int i = 0; i < playersNumber; i++)
        threadArray[i].join();

    return result;
}

void Board::singlePlay(unsigned long long turns) {
    return;
}