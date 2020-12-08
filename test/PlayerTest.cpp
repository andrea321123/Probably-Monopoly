// PlayerTest.cpp
// Version 1.1
// Test of Player class

#include "catch.hpp"

#include "../src/Player.h"

TEST_CASE("Player movement test by steps", "[player]"){
    Player test;
    REQUIRE (test.position == 0);

    test.move(10);
    REQUIRE (test.position == 10);
    test.move(15);
    REQUIRE (test.position == 25);

    // test when player's position goes over 39
    test.move(25);
    REQUIRE (test.position == 10);

    REQUIRE (test.board[10] == 2);
    REQUIRE (test.board[1] == 0);
    REQUIRE (test.board[25] == 1);
}

TEST_CASE("Player movement test by CardsEffect", "[player]"){
    Player test;
    test.move(1);

    test.move(TRAFALGAR_SQUARE);
    REQUIRE (test.position == 13);
    test.move(1);
    REQUIRE (test.position == 14);
}