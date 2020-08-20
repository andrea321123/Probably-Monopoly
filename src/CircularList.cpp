// CircularList.cpp
// Version 1.0
//

#include "CircularList.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>

// private functions
int randomGeneration(int i) {
    return std::rand()%i;
}

CircularList::CircularList(std::vector <int> cardValues) {
    // generating seed for random generation
    std::srand(unsigned(std::time(0)));

    // variables initialization
    CircularList::cardValues = cardValues;
    firstCard = new Node;
    drawnCards = 0;

    // nodes initialization
    Node* tail = firstCard;
    tail->value = cardValues[0];
    for (auto i = cardValues.begin() +1; i != cardValues.end(); i++) {
        Node* tmp = new Node;
        tmp->value = *i;
        tail->link = tmp;
        tail = tail->link;
    }
    tail->link = firstCard;     // because the list is circular

    shuffle();
}

void CircularList::shuffle() {
    std::random_shuffle(cardValues.begin(), cardValues.end(), randomGeneration);      // we first shuffle the deck

    // then we copy the shuffled vector into the list
    Node* tmp = firstCard;
    for (auto i = cardValues.begin(); i != cardValues.end(); i++) {
        tmp->value = *i;
        tmp = tmp->link;
    }
}

int CircularList::draw() {
    int ret = firstCard->value;

    // first element must become last element
    firstCard = firstCard->link;

    if(++drawnCards == cardValues.size()) {        // check if the cards are finished
        shuffle();
        drawnCards = 0;
    }

    return ret;
}