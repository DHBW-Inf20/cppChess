//
// Created by jannik on 30.12.21.
//

#include "Move.hpp"
#include <string>
#include <iostream>

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

std::string Move::getAsString() {
    std::string outputString = "Startposition: ";
    outputString += std::to_string(this->getStartHorizontalPosition());
    outputString += ",";
    outputString += std::to_string(this->getStartVerticalPosition());
    outputString += "; Endposition: ";
    outputString += std::to_string(this->getEndHorizontalPosition());
    outputString += ",";
    outputString += std::to_string(this->getEndVerticalPosition());
    return outputString;
}