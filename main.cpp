//
// Created by dominic on 17.12.21.
//

#include <iostream>
#include "model/Player.hpp"
#include "model/ChessField.hpp"

int main () {
    
    /*//move calculation test...
    Player* firstPlayer = new Player(true);
    Player* secondPlayer = new Player(false);
    //Figure* figure = firstPlayer->getUncapturedFigures()->at(0);
    MoveController* moveController = new MoveController(firstPlayer, secondPlayer);
    //std::vector<Move*>* allMoves = moveController->getPseudoLegalMoves(figure);
    std::vector<Move*>* allMoves = moveController->getPseudoLegalMovesForAll(firstPlayer->getUncapturedFigures());
    if (allMoves->size() > 0) {
        for (int i = 0; i < allMoves->size(); i++) {
            Move* m = allMoves->at(i);
            std::cout << m->getAsString() << std::endl;
        }
    } else {
        std::cout << "Diese Figur hat keine Zuege!" << std::endl;
    }

    delete(firstPlayer);
    delete(secondPlayer);
    delete(moveController);*/

    Player* firstPlayer = new Player(true);
    Player* secondPlayer = new Player(false);
    ChessField* chessField = new ChessField(firstPlayer, secondPlayer);
    chessField->repaint();

    while (true) {
        chessField->move();
        chessField->repaint();
    }

    delete(chessField);
    return 0;
}