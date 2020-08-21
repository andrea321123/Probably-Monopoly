// Dice.h
// Version 1.0
// Implements Monopoly dices

#ifndef PROBABLY_MONOPOLY_DICES_H
#define PROBABLY_MONOPOLY_DICES_H

#include <utility>
#include <string>

class Dice {
private:
    int maxValue;   // biggest number that can be generate (on a d6 it is 6)

public:
    Dice(int maxValue);
    int roll();     // returns a number from 1 to maxValue (included)
};

class MonopolyDices {
private:
    int maxValue = 6;
    Dice dice1, dice2;
    std::pair <int, int> lastRoll;   // last result of roll() function

public:
    MonopolyDices();

    unsigned long long int obtainedResults[12+1];   // store all the roll() results

    int roll();     // roll
    bool doubleRoll();  // checks if the last roll() call generated same number on the 2 dices
};

// functions

// test numberOfRolls rolls and returns the results as a std::string
std::string rollDistribution(unsigned long long int numberOfRolls);

#endif //PROBABLY_MONOPOLY_DICES_H
