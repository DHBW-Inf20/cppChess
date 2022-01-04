//
// Created by dominic on 28.12.21.
//

#include "Pawn.hpp"

Pawn::Pawn(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition, 1) {
    if(isWhite) {
        this->icon = "\u265F";
    } else {
        this->icon = "\u2659";
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
