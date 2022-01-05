//
// Created by dominic on 28.12.21.
//

#include "Bishop.hpp"

Bishop::Bishop(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition, 3) {
    if(isWhite) {
        this->icon = "\u265D";
    } else {
        this->icon = "\u2657";
    }
}

Bishop::~Bishop() {}

Bishop* Bishop::cloneFigure() {
    Bishop* clonedBishop = new Bishop(this->getName(), this->getIsWhite(), this->getHorizontalPosition(), this->getVerticalPosition());
    return clonedBishop;
}