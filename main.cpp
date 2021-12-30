//
// Created by dominic on 17.12.21.
//

#include <iostream>
#include "model/Player.hpp"
#include "model/Figure.hpp"
#include "model/Move.hpp"


int main () {
    //just a random test...
    Player* whitePlayer = new Player(true);
    std::vector<Figure*>* uncapturedFigures = whitePlayer->getUncapturedFigures();
    Figure* firstBishop = uncapturedFigures->at(2);
    std::vector<Move*>* allMoves = firstBishop->calcPseudoLegalMoves();
    for (int i = 0; i < allMoves->size(); i++) {
        Move* m = allMoves->at(i);
        std::cout << m->getAsString() << std::endl;
    }
    return 0;
}