// CircularListTest.cpp
// Version 1.0
// Test of CircularList struct

#include "catch.hpp"

#include <vector>
#include <iostream>
#include "../src/CircularList.h"

TEST_CASE("Drawn cards test", "[circular_list]"){
    std::vector <CardsEffect> vector = {MAYFAIR, TRAFALGAR_SQUARE, NOTHING, MARYLEBONE_STATION, GO, NOTHING, NOTHING};
    CircularList test(vector);

    for (int i = 0; i < vector.size() -1; i++)
        test.draw();

    REQUIRE (test.drawnCards == 6);
    test.draw();    // then cards will be shuffled
    REQUIRE (test.drawnCards == 0);
}

TEST_CASE("Go to jail test", "[circular_list]"){
    std::vector <CardsEffect> vector = {MAYFAIR, TRAFALGAR_SQUARE, NOTHING, OUT_JAIL, MARYLEBONE_STATION};
    CircularList test(vector);

    for (unsigned int i = 0; i < vector.size(); i++)
        test.draw();

    REQUIRE (test.jailInDeck == false);
    REQUIRE (test.drawnCards == 0);

    for (unsigned int i = 0; i < vector.size() -1; i++)      // now deck contains one card less
        test.draw();

    REQUIRE (test.drawnCards == 0);

    // we push jail card in the deck
    test.pushJailCard();

    for (unsigned int i = 0; i < vector.size() -1; i++)
        test.draw();

    for (unsigned int i = 0; i < vector.size(); i++)
        test.draw();
    REQUIRE (test.drawnCards == 0);
}