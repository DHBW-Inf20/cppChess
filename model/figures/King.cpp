//
// Created by dominic on 28.12.21.
//

#include "King.hpp"

King::King(std::string name, int horizontalPosition, int verticalPosition) : Figure (name, horizontalPosition, verticalPosition) {
    this->setDelta(-1,-1, false, false);
}

std::vector<Move*>* King::calcPseudoLegalMoves() {
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;
    return pseudoLegalMoves;
}