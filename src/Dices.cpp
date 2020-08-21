// Dice.cpp
// Version 1.0
//

#include "Dices.h"

#include <cstdlib>
#include <ctime>

Dice::Dice(int maxValue) {
    Dice::maxValue = maxValue;
    std::srand(unsigned(std::time(0)));     // generating seed for random generation
}

int Dice::roll() {
    return 1+ rand() % maxValue;
}

MonopolyDices::MonopolyDices(): dice1(maxValue), dice2(maxValue) {
    lastRoll.first = 0;
    lastRoll.second = 0;

    for (int i = 0; i < 13; i++)
        obtainedResults[i] = 0;
}

int MonopolyDices::roll() {
    lastRoll.first = dice1.roll();
    lastRoll.second = dice2.roll();

    int ret = lastRoll.first + lastRoll.second;
    obtainedResults[ret]++;     // update obtainedResults
    return ret;
}

bool MonopolyDices::doubleRoll() {
    return lastRoll.first == lastRoll.second;
}

std::string rollDistribution(unsigned long long int numberOfRolls) {
    MonopolyDices test;

    // we first roll the dices numberOfRolls times
    for (unsigned long long int i = 0; i < numberOfRolls; i++)
        test.roll();

    // then we return the results as a std::string
    std::string ret = "";
    for (int i = 2; i < 13; i++)
        ret += std::to_string(i) + ": " + std::to_string(test.obtainedResults[i]) + "\n";

    return ret;
}