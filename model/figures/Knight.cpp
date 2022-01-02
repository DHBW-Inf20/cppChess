//
// Created by dominic on 25.12.21.
//

#include "Knight.hpp"

Knight::Knight(std::string name, bool isWhite, int horizontalPosition, int verticalPosition) : Figure (name, isWhite, horizontalPosition, verticalPosition) {
    if(isWhite) {
        this->icon = "\u2658";
    } else {
        this->icon = "\u265E";
    }
}

Knight::~Knight() {}