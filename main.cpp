//
// Created by dominic on 17.12.21.
//

#include <iostream>
#include "model/Player.hpp"
#include "model/Figure.hpp"
#include "model/Move.hpp"
#include "model/ChessField.hpp"

int main () {
    //just a random test...

//    std::vector<Figure*>* uncapturedFigures = firstPlayer->getUncapturedFigures();
//    std::cout << uncapturedFigures->size();
//    Figure* firstFigure = uncapturedFigures->at(3);
//    std::vector<Move*>* allMoves = firstFigure->calcPseudoLegalMoves();
//    for (int i = 0; i < allMoves->size(); i++) {
//        Move* m = allMoves->at(i);
//        std::cout << m->getAsString() << std::endl;
//    }

    Player* firstPlayer = new Player(true);
    Player* secondPlayer = new Player(false);

    ChessField* chessField = new ChessField(firstPlayer, secondPlayer);
    chessField->repaint();

    while (true) {
        chessField->move();
        chessField->repaint();
    }
    return 0;
}