//
// Created by dominic on 28.12.21.
//

#include "Queen.hpp"

Queen::Queen(std::string name, int horizontalPosition, int verticalPosition) : Figure (name, horizontalPosition, verticalPosition) {
    this->setDelta(-1,-1, true, false);
}

std::vector<Move*>* Queen::calcPseudoLegalMoves() {
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;
    return pseudoLegalMoves;
}