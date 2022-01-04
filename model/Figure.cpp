//
// Created by dominic on 25.12.21.
//

#include "Figure.hpp"

Figure::Figure(std::string name, bool isWhite, int horizontalPosition, int verticalPosition, int value) {
    this->setName(name);
    this->setIsWhite(isWhite);
    this->setHorizontalPosition(horizontalPosition);
    this->setVerticalPosition(verticalPosition);
    this->setNotCaptured(true);
    this->setValue(value);
}

void Figure::setName(std::string name) {
    this->name = name;
}

void Figure::setIsWhite(bool isWhite) {
    this->isWhite = isWhite;
}

void Figure::setHorizontalPosition(int horizontalPosition) {
    this->horizontalPosition = horizontalPosition;
}

void Figure::setVerticalPosition(int verticalPosition) {
    this->verticalPosition = verticalPosition;
}

void Figure::setNotCaptured(bool notCaptured) {
    this->notCaptured = notCaptured;
}

void Figure::setValue(int value) {
    this->value = value;
}

std::string Figure::getName() {
    return this->name;
}

bool Figure::getIsWhite() {
    return this->isWhite;
}

int Figure::getHorizontalPosition() {
    return this->horizontalPosition;
}

int Figure::getVerticalPosition() {
    return this->verticalPosition;
}

bool Figure::getNotCaptured() {
    return this->notCaptured;
}

int Figure::getValue() {
    return this->value;
}

std::string Figure::returnIcon(bool showIcon) {
    if(showIcon) {
        return this->icon;
    } else {
        return this->name;
    }
}
