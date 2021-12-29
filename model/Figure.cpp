//
// Created by dominic on 25.12.21.
//

#include "Figure.hpp"

void Figure::setPosition(int position) {
    this->position = position;
}

int Figure::getPosition() {
    return this->position;
}

void Figure::setDelta(int delta1, int delta2, bool moveEndless, bool moveOnlyForward) {
    this->delta1 = delta1;
    this->delta2 = delta2;
    this->moveEndless = moveEndless;
    this->moveOnlyForward = moveOnlyForward;
}

int Figure::getDelta1() {
    return this->delta1;
}

int Figure::getDelta2() {
    return this->delta2;
}

bool Figure::isMoveEndless() {
    return this->moveEndless;
}

bool Figure::isMoveOnlyForward() {
    return this->moveOnlyForward;
}