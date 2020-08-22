// CircularList.cpp
// Version 1.1
//

#include "CircularList.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>

// private functions
int randomGeneration(int i) {
    return std::rand()%i;
}

CircularList::CircularList(std::vector <CardsEffect> cardValues) {
    // generating seed for random generation
    std::srand(unsigned(std::time(0)));

    // variables initialization
    CircularList::cardValues = cardValues;
    firstCard = new Node;
    drawnCards = 0;
    jailInDeck = true;      // if card go out of jail is in the deck

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
        if (*i == OUT_JAIL && !jailInDeck)
            continue;

        tmp->value = *i;
        tmp = tmp->link;
    }
}

CardsEffect CircularList::draw() {
    CardsEffect ret = firstCard->value;

    // if player pick exit from jail card, we must remove it from the deck
    if (ret == OUT_JAIL) {
        jailInDeck = false;
        Node* tmp = firstCard;
        while(tmp->link->value != OUT_JAIL)      // we go to the card before the jail card
            tmp = tmp->link;
        tmp->link = tmp->link->link;
        drawnCards--;
    }

    // first element must become last element
    firstCard = firstCard->link;

    int cardsInDeck = cardValues.size();
    if (!jailInDeck)
        cardsInDeck--;

    if(++drawnCards == cardsInDeck) {        // check if the cards are finished
        shuffle();
        drawnCards = 0;
    }

    return ret;
}

void CircularList::pushJailCard() {
    if (jailInDeck)
        return;

    // we create the new card
    Node* jailCard;
    jailCard->value = OUT_JAIL;

    // we reach the last card
    Node* tmp = firstCard;
    for (int i = 0; i < cardValues.size() -2; i++)
        tmp = tmp->link;

    // we put out of jail after the last card
    tmp->link = jailCard;
    jailCard->link = firstCard;
    jailInDeck = true;
    drawnCards++;   // since out of jail is considered already used
}