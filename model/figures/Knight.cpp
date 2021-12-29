//
// Created by dominic on 25.12.21.
//

#include "Knight.hpp"

Knight::Knight(std::string name, int position) {
    this->setName(name);
    this->setPosition(position);
    this->setDelta(1, 2, false, false);
}