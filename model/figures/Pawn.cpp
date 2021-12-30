//
// Created by dominic on 28.12.21.
//

#include "Pawn.hpp"

Pawn::Pawn(std::string name, int horizontalPosition, int verticalPosition) : Figure (name, horizontalPosition, verticalPosition) {
    this->setDelta(1, 0, false, true);
}

std::vector<Move*>* Pawn::calcPseudoLegalMoves() {
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;
    return pseudoLegalMoves;
}