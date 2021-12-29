//
// Created by dominic on 28.12.21.
//

#include "Rook.hpp"

Rook::Rook(std::string name, int position) {
    this->setName(name);
    this->setPosition(position);
    this->setDelta(1, 0, true, false);
}