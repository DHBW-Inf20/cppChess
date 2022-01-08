//
// Created by jannik on 03.01.22.
//

#include "Castle.hpp"

Castle::Castle(King* king, Rook* rook, bool isShort) : Move(king, -1, king->getVerticalPosition()) {
    this->isShort = isShort;
    this->rook = rook;
    this->setRookEndVerticalPosition(rook->getVerticalPosition());
    if (isShort) {
        this->setEndHorizontalPosition(7);
        this->setRookEndHorizontalPosition(6);
    } else {
        this->setEndHorizontalPosition(3);
        this->setRookEndHorizontalPosition(4);
    }
}

Castle::~Castle() {}

King* Castle::getKing() {
    return dynamic_cast<King*>(this->getFigure());
}

Rook* Castle::getRook() {
    return this->rook;
}

bool Castle::getIsShort() {
    return this->isShort;
}

void Castle::setRookEndHorizontalPosition(int pos) {
    this->rookEndHorizontalPosition = pos;
}

void Castle::setRookEndVerticalPosition(int pos) {
    this->rookEndVerticalPosition = pos;
}

int Castle::getRookEndHorizontalPosition() {
    return this->rookEndHorizontalPosition;
}

int Castle::getRookEndVerticalPosition() {
    return this->rookEndVerticalPosition;
}

void Castle::execute() {
    this->getKing()->setHorizontalPosition(this->getEndHorizontalPosition());
    this->getKing()->setVerticalPosition(this->getEndVerticalPosition());
    this->getKing()->incrementMoveCounter();

    this->getRook()->setHorizontalPosition(this->getRookEndHorizontalPosition());
    this->getRook()->setVerticalPosition(this->getRookEndVerticalPosition());
    this->getRook()->incrementMoveCounter();
}

std::string Castle::getAsString() {
    std::string outputString = "";
    bool isWhite = this->getKing()->getIsWhite();
    if (isWhite) {
        outputString += "White ";
    } else {
        outputString += "Black ";
    }
    outputString += " castles ";
    if (this->isShort) {
        outputString += "short!";
    } else {
        outputString += "long!";
    }
    return outputString;
}