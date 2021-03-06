//
// Created by dominic on 28.12.21.
//

#include "King.hpp"

King::King(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition, -1) {
    if(isWhite) {
        this->icon = "\u2654";
    } else {
        this->icon = "\u265A";
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

King* King::cloneFigure() {
    King* clonedKing = new King(this->getName(), this->getIsWhite(), this->getHorizontalPosition(), this->getVerticalPosition());
    return clonedKing;
}