//
// Created by jannik on 30.12.21.
//

#include "Move.hpp"

Move::Move(int startHorizontalPosition, int startVerticalPosition, int endHorizontalPosition, int endVerticalPosition) {
    this->setStartHorizontalPosition(startHorizontalPosition);
    this->setStartVerticalPosition(startVerticalPosition);
    this->setEndHorizontalPosition(endHorizontalPosition);
    this->setEndVerticalPosition(endVerticalPosition);
}

void Move::setStartHorizontalPosition(int startHorizontalPosition) {
    this->startHorizontalPosition = startHorizontalPosition;
}

void Move::setStartVerticalPosition(int startVerticalPosition) {
    this->startVerticalPosition = startVerticalPosition;
}

void Move::setEndHorizontalPosition(int endHorizontalPosition) {
    this->endHorizontalPosition = endHorizontalPosition;
}

void Move::setEndVerticalPosition(int endVerticalPosition) {
    this->endVerticalPosition = endVerticalPosition;
}

int Move::getStartHorizontalPosition() {
    return this->startHorizontalPosition;
}

int Move::getStartVerticalPosition() {
    return this->startVerticalPosition;
}

int Move::getEndHorizontalPosition() {
    return this->endHorizontalPosition;
}

int Move::getEndVerticalPosition() {
    return this->endVerticalPosition;
}