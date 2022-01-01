//
// Created by dominic on 25.12.21.
//

#include "Knight.hpp"

Knight::Knight(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
    if(isWhite) {
        this->icon = "\u2658";
    } else {
        this->icon = "\u265E";
    }
}

std::vector<Move*>* Knight::calcPseudoLegalMoves() {
    int figHorizontalPosition = this->getHorizontalPosition();
    int figVerticalPosition = this->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;

    //Züge nach rechts
    if (figHorizontalPosition+2 <= 8) {
        if (figVerticalPosition+1 <= 8) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+2, figVerticalPosition+1));
        }
        if (figVerticalPosition-1 >= 1) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+2, figVerticalPosition-1));
        }
    }

    //Züge nach links
    if (figHorizontalPosition-2 >= 1) {
        if (figVerticalPosition+1 <= 8) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-2, figVerticalPosition+1));
        }
        if (figVerticalPosition-1 >= 1) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-2, figVerticalPosition-1));
        }
    }

    //Züge nach oben
    if (figVerticalPosition+2 <= 8) {
        if (figHorizontalPosition+1 <= 8) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition+2));
        }
        if (figHorizontalPosition-1 >= 1) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition+2));
        }
    }

    //Züge nach unten
    if (figVerticalPosition-2 >= 1) {
        if (figHorizontalPosition+1 <= 8) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition-2));
        }
        if (figHorizontalPosition-1 >= 1) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition-2));
        }
    }

    return pseudoLegalMoves;
}