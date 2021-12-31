//
// Created by dominic on 28.12.21.
//

#include "Rook.hpp"

Rook::Rook(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {

}

std::vector<Move*>* Rook::calcPseudoLegalMoves() {
    int figHorizontalPosition = this->getHorizontalPosition();
    int figVerticalPosition = this->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;

    //Züge nach rechts
    int calcHorizontalPosition = figHorizontalPosition;
    while ((calcHorizontalPosition+1) <= 8) {
        calcHorizontalPosition++;
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, figVerticalPosition));
    }

    //Züge nach links
    calcHorizontalPosition = figHorizontalPosition;
    while ((calcHorizontalPosition-1) >= 1) {
        calcHorizontalPosition--;
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, figVerticalPosition));
    }

    //Züge nach oben
    int calcVerticalPosition = figVerticalPosition;
    while ((calcVerticalPosition+1) <= 8) {
        calcVerticalPosition++;
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, calcVerticalPosition));
    }

     //Züge nach unten
    calcVerticalPosition = figVerticalPosition;
    while ((calcVerticalPosition-1) >= 1) {
        calcVerticalPosition--;
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, calcVerticalPosition));
    }

    return pseudoLegalMoves;
}