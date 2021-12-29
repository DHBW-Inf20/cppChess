//
// Created by dominic on 28.12.21.
//

#include "Pawn.hpp"

Pawn::Pawn(std::string name, int position) {
    this->setName(name);
    this->setPosition(position);
    this->setDelta(1, 0, false, true);
}