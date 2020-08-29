// cards.h
// Version 1.1
// Definition of community chest and chance information

#ifndef PROBABLY_MONOPOLY_CARDS_H
#define PROBABLY_MONOPOLY_CARDS_H

#include <vector>
#include <unordered_set>
#include "CircularList.h"

std::vector <CardsEffect> communityChestVector {
        GO,
        OLD_KENT_ROAD,
        GOTO_JAIL,
        OUT_JAIL,
        NOTHING,NOTHING,NOTHING,NOTHING,NOTHING,NOTHING,
        NOTHING,NOTHING,NOTHING,NOTHING,NOTHING,NOTHING
};
std::vector <CardsEffect> chanceVector {
        GO,
        PALL_MALL,
        MARYLEBONE_STATION,
        TRAFALGAR_SQUARE,
        MAYFAIR,
        GOTO_JAIL,
        OUT_JAIL,
        NOTHING,NOTHING,NOTHING,NOTHING,
        NOTHING,NOTHING,NOTHING,NOTHING,
};
std::unordered_set <int> chancePosition({7, 22, 36});
std::unordered_set <int> communityChestPosition({2, 17, 33});

#endif //PROBABLY_MONOPOLY_CARDS_H
