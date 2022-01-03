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

    this->setCanCastle(true);
}

King::~King() {}

void King::setCanCastle(bool canCastle) {
    this->canCastle = canCastle;
}

bool King::getCanCastle() {
    return this->canCastle;
}