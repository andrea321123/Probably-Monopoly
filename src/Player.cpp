// Player.cpp
// Version 1.1
//

#include "Player.h"
#include "util.h"

Player::Player() {
    // members initialization
    position = 0;
    for (int i = 0; i < NUMBER_OF_SQUARES; i++)
        board[i] = 0;
}

int Player::move(int steps) {
    position = (position + steps) % NUMBER_OF_SQUARES;
    board[position]++;
    return position;
}

int Player::move(CardsEffect square) {
    if (square == THREE_STEPS_BEHIND) {
        return move(-3);
    }

    position = cardToPosition[square];
    board[position]++;
    return position;
}