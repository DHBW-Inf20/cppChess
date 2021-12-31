//
// Created by dominic on 28.12.21.
//

#include "Pawn.hpp"

Pawn::Pawn(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
    
}

std::vector<Move*>* Pawn::calcPseudoLegalMoves() {
    int figHorizontalPosition = this->getHorizontalPosition();
    int figVerticalPosition = this->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;

    if (this->getIsWhite()) {
        //normaler Zug: eins vorwärts
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition+1));

        //noch nicht gezogen: zwei vorwärts
        if (figVerticalPosition == 2) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition+2));
        }
    } else {    //this->getIsWhite() == false
        //normaler Zug: eins vorwärts
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition-1));

        //noch nicht gezogen: zwei vorwärts
        if (figVerticalPosition == 7) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition-2));
        }
    }

    return pseudoLegalMoves;
}
