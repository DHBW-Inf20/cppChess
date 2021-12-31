//
// Created by dominic on 28.12.21.
//

#include "Queen.hpp"

Queen::Queen(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
    
}

std::vector<Move*>* Queen::calcPseudoLegalMoves() {
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;
    return pseudoLegalMoves;
}