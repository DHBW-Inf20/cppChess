//
// Created by dominic on 28.12.21.
//

#include "Opponent.hpp"

Opponent::Opponent(int line) {
    this->firstRook = new Rook();
    this->firstRook->setPosition("A", line);
    this->secondRook = new Rook();
    this->secondRook->setPosition("H", line)
}