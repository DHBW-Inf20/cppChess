//
// Created by dominic on 28.12.21.
//

#include "Pawn.hpp"

Pawn::Pawn(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition, 1) {
    if(isWhite) {
        this->icon = "\u2659";
    } else {
        this->icon = "\u265F";
    }

    this->moveCounter = 0;
}

Pawn::~Pawn() {}

void Pawn::incrementMoveCounter() {
    this->moveCounter++;
}

int Pawn::getMoveCounter() {
    return this->moveCounter;
}

Pawn* Pawn::cloneFigure() {
    Pawn* clonedPawn = new Pawn(this->getName(), this->getIsWhite(), this->getHorizontalPosition(), this->getVerticalPosition());
    return clonedPawn;
}