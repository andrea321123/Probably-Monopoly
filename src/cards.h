// cards.h
// Version 1.0
// Definition of communityChestVector and chanceVector

#ifndef PROBABLY_MONOPOLY_CARDS_H
#define PROBABLY_MONOPOLY_CARDS_H

#include <vector>
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

#endif //PROBABLY_MONOPOLY_CARDS_H
