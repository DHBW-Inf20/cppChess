//
// Created by dominic on 28.12.21.
//

#include "Rook.hpp"

Rook::Rook(std::string name, int position) : Figure(name, position) {
    this->setDelta(1, 0, true, false);
}