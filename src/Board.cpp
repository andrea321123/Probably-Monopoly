// Board.cpp
// Version 1.4
//

#include "Board.h"
#include <iostream>
#include <thread>
#include "cards.h"
#include "Dices.h"

// internal functions declaration
void drawCard(CircularList* deck, Player* player, bool* ownOutOfJail, bool* inJail);

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
        threadArray[i] = std::thread(&Board::singlePlay, this,  turns, &result);

    // we join each thread
    for (int i = 0; i < playersNumber; i++)
        threadArray[i].join();

    return result;
}

void Board::singlePlay(unsigned long long turns, SimulationResult* result) {
    Player player;
    MonopolyDices dices;

    int turnsInJail = 0;
    bool inJail = false;
    bool ownOutOfJail = false;

    for (int i = 0; i < turns; i++) {
        int doubleRollStreak = 0;

        // check if player is in jail
        if (inJail) {
            turnsInJail++;
            int diceValue = dices.roll();

            if (!dices.doubleRoll() || turnsInJail != 3) {
                inJail = false;
                continue;
            }
        }

        // normal turn
        do {
            doubleRollStreak++;
            int diceValue = dices.roll();

            // go to jail condition
            if (doubleRollStreak == 3 && dices.doubleRoll()) {
                player.move(JAIL);
                inJail = true;
                break;
            }

            // move the player and check if he goes in a special square
            player.move(diceValue);

            // if we went to square 30, go to jail
            if (player.position == 30) {
                player.move(JAIL);
                inJail = true;
                break;
            }

            // start of the critical section
            mutex.lock();
            // if he goes on chance square
            if (chancePosition.find(player.position) != chancePosition.end())
                drawCard(&chance, &player, &ownOutOfJail, &inJail);

            // if he goes on community chest square
            if (communityChestPosition.find(player.position) != communityChestPosition.end())
                drawCard(&communityChest, &player, &ownOutOfJail, &inJail);

            // we update simulation result
            result->board[player.position]++;
            result->dice[diceValue]++;

            mutex.unlock();     // end of the critical section
        }
        while(dices.doubleRoll() && !inJail);
    }
    return;
}

// internal functions
void drawCard(CircularList* deck, Player* player, bool* ownOutOfJail, bool* inJail) {
    CardsEffect card = deck->draw();
    if (card == OUT_JAIL)
        *ownOutOfJail = true;
    else if (card != NOTHING)
        player->move(card);

    if (card == GOTO_JAIL)
        *inJail = true;
}