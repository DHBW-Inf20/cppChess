//
// Created by dominic on 17.12.21.
//

#include <iostream>
#include "model/Player.hpp"
#include "model/Figure.hpp"
#include "model/Move.hpp"


int main () {
    //just a random test...
    Player* firstPlayer = new Player(false);
    std::vector<Figure*>* uncapturedFigures = firstPlayer->getUncapturedFigures();
    std::cout << uncapturedFigures->size();
    Figure* firstFigure = uncapturedFigures->at(3);
    std::vector<Move*>* allMoves = firstFigure->calcPseudoLegalMoves();
    for (int i = 0; i < allMoves->size(); i++) {
        Move* m = allMoves->at(i);
        std::cout << m->getAsString() << std::endl;
    }
    return 0;
}