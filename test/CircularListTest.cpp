// CircularListTest.cpp
// Version 1.0
// Test of CircularList struct

#include "catch.hpp"

#include <vector>
#include "../src/CircularList.h"

TEST_CASE("Drawn cards test", "[circular_list]"){
    std::vector <int> vector = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
    CircularList test(vector);

    for (int i = 0; i < vector.size() -1; i++)
        test.draw();

    REQUIRE (test.drawnCards == 9);
    test.draw();    // then cards will be shuffled
    REQUIRE (test.drawnCards == 0);
}