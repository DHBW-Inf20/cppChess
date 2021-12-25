//
// Created by dominic on 25.12.21.
//

#include "Figure.hpp"

void Figure::setPosition(std::string horizontal, int vertical) {
    this->horizontalPosition = horizontal;
    this->verticalPosition = vertical;
}

std::string Figure::getHorizontalPosition() {
    return this->horizontalPosition;
}

int Figure::getVerticalPosition() {
    return this->verticalPosition;
}

void Figure::setDelta(int delta1, int delta2, bool moveEndless) {
    this->delta1 = delta1;
    this->delta2 = delta2;
    this->moveEndless = moveEndless;
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