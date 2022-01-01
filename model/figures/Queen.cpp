//
// Created by dominic on 28.12.21.
//

#include "Queen.hpp"

Queen::Queen(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
    if(isWhite) {
        this->icon = "\u2655";
    } else {
        this->icon = "\u265B";
    }
}

std::vector<Move*>* Queen::calcPseudoLegalMoves() {
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

    //Züge nach rechts oben
    calcHorizontalPosition = figHorizontalPosition;
    calcVerticalPosition = figVerticalPosition;
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