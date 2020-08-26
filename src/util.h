// util.h
// Version 1.1
//

#ifndef PROBABLY_MONOPOLY_UTIL_H
#define PROBABLY_MONOPOLY_UTIL_H

#include <unordered_map>
#include <unordered_set>
#include "CircularList.h"

std::unordered_map <CardsEffect, int> cardToPosition = {
        {GO, 0},
        {GOTO_JAIL, 30},
        {OLD_KENT_ROAD, 19},
        {PALL_MALL, 24},
        {MARYLEBONE_STATION, 5},
        {TRAFALGAR_SQUARE, 13},
        {MAYFAIR, 39}
};

std::unordered_set <int> chancePosition({7, 22, 36});
std::unordered_set <int> communityChestPosition({2, 17, 33});

#endif //PROBABLY_MONOPOLY_UTIL_H
