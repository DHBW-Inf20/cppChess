//
// Created by dominic on 28.12.21.
//

#include "Bishop.hpp"
#include "../Move.hpp"

Bishop::Bishop(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
    if(isWhite) {
        this->icon = "\u2657";
    } else {
        this->icon = "\u265D";
    }
}

Bishop::~Bishop() {}