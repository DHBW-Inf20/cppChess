//
// Created by dominic on 28.12.21.
//

#include "Queen.hpp"

Queen::Queen(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition, 9) {
    if(isWhite) {
        this->icon = "\u265B";
    } else {
        this->icon = "\u2655";
    }
}

Queen::~Queen() {}

Queen* Queen::cloneFigure() {
    Queen* clonedQueen = new Queen(this->getName(), this->getIsWhite(), this->getHorizontalPosition(), this->getVerticalPosition());
    return clonedQueen;
}