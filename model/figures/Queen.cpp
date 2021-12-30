//
// Created by dominic on 28.12.21.
//

#include "Queen.hpp"

Queen::Queen(std::string name, int position) : Figure (name, position) {
    this->setDelta(-1,-1, true, false);
}