//
// Created by dominic on 25.12.21.
//

#include "Knight.hpp"

Knight::Knight() {
    this->moveOnlyForward = false;
    this->moveEndless = false;
    this->setDelta(1, 2, false, false);
}