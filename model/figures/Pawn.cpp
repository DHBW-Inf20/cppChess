//
// Created by dominic on 28.12.21.
//

#include "Pawn.hpp"

Pawn::Pawn(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
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
