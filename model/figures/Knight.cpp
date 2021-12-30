//
// Created by dominic on 25.12.21.
//

#include "Knight.hpp"

Knight::Knight(std::string name, int horizontalPosition, int verticalPosition) : Figure (name, horizontalPosition, verticalPosition) {
    this->setDelta(1, 2, false, false);
}

std::vector<Move*>* Knight::calcPseudoLegalMoves() {
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;
    return pseudoLegalMoves;
}