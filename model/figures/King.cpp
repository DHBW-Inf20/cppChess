//
// Created by dominic on 28.12.21.
//

#include "King.hpp"

King::King(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
    if(isWhite) {
        this->icon = "\u2654";
    } else {
        this->icon = "\u265A";
    }

    this->setCanCastle(true);
}

King::~King() {}

void King::setCanCastle(bool canCastle) {
    this->canCastle = canCastle;
}

bool King::getCanCastle() {
    return this->canCastle;
}

/*std::vector<Move*>* King::calcPseudoLegalMoves() {
    int figHorizontalPosition = this->getHorizontalPosition();
    int figVerticalPosition = this->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;

    //rechts
    if (figHorizontalPosition+1 <= 8) {
        //rechts oben
        if (figVerticalPosition+1 <= 8) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition+1));
        }
        //rechts mittig
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition));
        //rechts unten
        if (figVerticalPosition-1 >= 1) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition-1));
        }
    }

    //links
    if (figHorizontalPosition-1 >= 1) {
        //links oben
        if (figVerticalPosition+1 <= 8) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition+1));
        }
        //links mittig
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition));
        //links unten
        if (figVerticalPosition-1 >= 1) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition-1));
        }
    }

    //oben
    if (figVerticalPosition+1 <= 8) {
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition+1));
    }

    //unten
    if (figVerticalPosition-1 >= 1) {
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition-1));
    }

    return pseudoLegalMoves;
}*/