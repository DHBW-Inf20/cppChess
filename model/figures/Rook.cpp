//
// Created by dominic on 28.12.21.
//

#include "Rook.hpp"

Rook::Rook(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
    if(isWhite) {
        this->icon = "\u2656";
    } else {
        this->icon = "\u265C";
    }
}

Rook::~Rook() {}

void Rook::incrementMoveCounter() {
    this->moveCounter++;
}

int Rook::getMoveCounter() {
    return this->moveCounter;
}