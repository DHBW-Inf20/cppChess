//
// Created by dominic on 28.12.21.
//

#include "King.hpp"

King::King(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
    if(isWhite) {
        this->icon = "\u265A";
    } else {
        this->icon = "\u2654";
    }
    this->moveCounter = 0;
}

King::~King() {}

void King::incrementMoveCounter() {
    this->moveCounter++;
}

int King::getMoveCounter() {
    return this->moveCounter;
}