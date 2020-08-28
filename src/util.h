// util.h
// Version 1.2
//

#ifndef PROBABLY_MONOPOLY_UTIL_H
#define PROBABLY_MONOPOLY_UTIL_H

#include <unordered_map>
#include "CircularList.h"

std::unordered_map <CardsEffect, int> cardToPosition = {
        {GO, 0},
        {GOTO_JAIL, 10},
        {OLD_KENT_ROAD, 19},
        {PALL_MALL, 24},
        {MARYLEBONE_STATION, 5},
        {TRAFALGAR_SQUARE, 13},
        {MAYFAIR, 39}
};

#endif //PROBABLY_MONOPOLY_UTIL_H
