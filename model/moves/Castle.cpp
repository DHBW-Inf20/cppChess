//
// Created by jannik on 03.01.22.
//

#include "Castle.hpp"

Castle::Castle(King* king, int kingEndHorizontalPosition, int kingEndVerticalPosition, Rook* rook, int rookEndHorizontalPosition, int rookEndVerticalPosition) : Move(king, kingEndHorizontalPosition, kingEndVerticalPosition) {
    this->setRook(rook);
    this->setRookStartHorizontalPosition(rook->getHorizontalPosition());
    this->setRookStartVerticalPosition(rook->getVerticalPosition());
    this->setRookEndHorizontalPosition(rookEndHorizontalPosition);
    this->setRookEndVerticalPosition(rookEndVerticalPosition);
}

Castle::~Castle() {}

void Castle::setRook(Rook* rook) {
    this->rook = rook;
}

void Castle::setRookStartHorizontalPosition(int rookStartHorizontalPosition) {
    this->rookStartHorizontalPosition = rookStartHorizontalPosition;
}

void Castle::setRookStartVerticalPosition(int rookStartVerticalPosition) {
    this->rookStartVerticalPosition = rookStartVerticalPosition;
}

void Castle::setRookEndHorizontalPosition(int rookEndHorizontalPosition) {
    this->rookEndHorizontalPosition = rookEndHorizontalPosition;
}

void Castle::setRookEndVerticalPosition(int rookEndVerticalPosition) {
    this->rookEndVerticalPosition = rookEndVerticalPosition;
}

Rook* Castle::getRook() {
    return this->rook;
}

int Castle::getRookStartHorizontalPosition() {
    return this->rookStartHorizontalPosition;
}

int Castle::getRookStartVerticalPosition() {
    return this->rookStartVerticalPosition;
}

int Castle::getRookEndHorizontalPosition() {
    return this->rookEndHorizontalPosition;
}

int Castle::getRookEndVerticalPosition() {
    return this->rookEndVerticalPosition;
}