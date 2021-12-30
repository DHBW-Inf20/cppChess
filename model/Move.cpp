//
// Created by jannik on 30.12.21.
//

#include "Move.hpp"

Move::Move(int startPos, int endPos) {
    this->setStartPos(startPos);
    this->setEndPos(endPos);
}

void Move::setStartPos(int startPos) {
    this->startPos = startPos;
}

void Move::setEndPos(int endPos) {
    this->endPos = endPos;
}

int Move::getStartPos() {
    return this->startPos;
}

int Move::getEndPos() {
    return this->endPos;
}