//
// Created by jannik on 30.12.21.
//

#include "Move.hpp"
#include "../figures/Pawn.hpp"
#include "../figures/King.hpp"
#include "../figures/Rook.hpp"
#include "../../helper/Converter.hpp"
#include <string>

Move::Move(Figure* figure, int endHorizontalPosition, int endVerticalPosition) {
    this->setFigure(figure);
    this->setStartHorizontalPosition(figure->getHorizontalPosition());
    this->setStartVerticalPosition(figure->getVerticalPosition());
    this->setEndHorizontalPosition(endHorizontalPosition);
    this->setEndVerticalPosition(endVerticalPosition);
}

void Move::setFigure(Figure* figure) {
    this->figure = figure;
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

Figure* Move::getFigure() {
    return this->figure;
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
    std::string outputString = this->getFigure()->getName() + " from " + convertPos(this->getStartVerticalPosition(), this->getStartHorizontalPosition())
        + " moves to " + convertPos(this->getEndVerticalPosition(), this->getEndHorizontalPosition()) + "!";
    return outputString;
}

void Move::execute() {
    this->getFigure()->setHorizontalPosition(this->getEndHorizontalPosition());
    this->getFigure()->setVerticalPosition(this->getEndVerticalPosition());
    if (Pawn* pawn = dynamic_cast<Pawn*>(this->getFigure())) {
        pawn->incrementMoveCounter();
    } else if (King* king = dynamic_cast<King*>(this->getFigure())) {
        king->incrementMoveCounter();
    } else if (Rook* rook = dynamic_cast<Rook*>(this->getFigure())) {
        rook->incrementMoveCounter();
    }
}