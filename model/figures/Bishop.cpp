//
// Created by dominic on 28.12.21.
//

#include "Bishop.hpp"

Bishop::Bishop(std::string name, int position) {
    this->setName(name);
    this->setPosition(position);
    this->setDelta(1,1, true, false);
}