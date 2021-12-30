//
// Created by dominic on 28.12.21.
//

#include "Bishop.hpp"
#include "../Move.hpp"

Bishop::Bishop(std::string name, int horizontalPosition, int verticalPosition) : Figure (name, horizontalPosition, verticalPosition) {
    this->setDelta(1,1, true, false);
}

std::vector<Move*>* Bishop::calcPseudoLegalMoves() {
    int figHorizontalPosition = this->getHorizontalPosition();
    int figVerticalPosition = this->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;

    //Züge nach rechts oben
    int calcHorizontalPosition = figHorizontalPosition;
    int calcVerticalPosition = figVerticalPosition;
    while ((calcHorizontalPosition+1 <= 8) && (calcVerticalPosition+1 <=8)) {
        calcHorizontalPosition++;
        calcVerticalPosition++;
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, calcVerticalPosition));
    }

    //Züge nach links oben
    calcHorizontalPosition = figHorizontalPosition;
    calcVerticalPosition = figVerticalPosition;
    while ((calcHorizontalPosition-1 >= 1) && (calcVerticalPosition+1 <=8)) {
        calcHorizontalPosition--;
        calcVerticalPosition++;
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, calcVerticalPosition));
    }

    //Züge nach rechts unten
    calcHorizontalPosition = figHorizontalPosition;
    calcVerticalPosition = figVerticalPosition;
    while ((calcHorizontalPosition+1 <= 8) && (calcVerticalPosition-1 >= 1)) {
        calcHorizontalPosition++;
        calcVerticalPosition--;
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, calcVerticalPosition));
    }

    //Züge nach links unten
    calcHorizontalPosition = figHorizontalPosition;
    calcVerticalPosition = figVerticalPosition;
    while ((calcHorizontalPosition-1 >= 1) && (calcVerticalPosition-1 >= 1)) {
        calcHorizontalPosition--;
        calcVerticalPosition--;
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, calcVerticalPosition));
    }

    return pseudoLegalMoves;
}