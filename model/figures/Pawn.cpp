//
// Created by dominic on 28.12.21.
//

#include "Pawn.hpp"

Pawn::Pawn(std::string name, int position) : Figure (name, position) {
    this->setDelta(1, 0, false, true);
}