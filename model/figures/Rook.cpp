//
// Created by dominic on 28.12.21.
//

#include "Rook.hpp"

Rook::Rook(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition, 5) {
    if(isWhite) {
        this->icon = "\u265C";
    } else {
        this->icon = "\u2656";
    }
}

Rook::~Rook() {}

void Rook::incrementMoveCounter() {
    this->moveCounter++;
}

int Rook::getMoveCounter() {
    return this->moveCounter;
}

Rook* Rook::cloneFigure() {
    Rook* clonedRook = new Rook(this->getName(), this->getIsWhite(), this->getHorizontalPosition(), this->getVerticalPosition());
    return clonedRook;
}