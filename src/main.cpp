#include <iostream>
#include <vector>
#include "CircularList.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector <int> a = {2,4,6,8,10};
    CircularList va(a);

    Node* tmp = va.firstCard;
    for (auto i = a.begin(); i != a.end(); i++) {
        std::cout << tmp->value << " ";
        tmp = tmp->link;
    }
    std::cout<<std::endl;
    for(int j = 0; j < 10; j++) {
        va.shuffle();
        tmp = va.firstCard;
        for (auto i = a.begin(); i != a.end(); i++) {
            std::cout << tmp->value << " ";
            tmp = tmp->link;
        }
        std::cout << "\n";
    }

    for (int i = 0; i < 10; i++)
        std::cout << va.draw() << " ";
    return 0;
}
