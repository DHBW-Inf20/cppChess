//
// Created by dominic on 17.12.21.
//

#include <iostream>
#include "model/Player.hpp"


int main () {
    //just a random test...
    Player* whitePlayer = new Player(true);
    std::vector<Figure*>* uncapturedFigures = whitePlayer->getUncapturedFigures();
    Figure* firstBishop = uncapturedFigures->at(2);
}