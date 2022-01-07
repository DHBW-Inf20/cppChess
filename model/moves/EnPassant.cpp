//
// Created by jannik on 07.01.22.
//

#include "EnPassant.hpp"
#include "../../helper/Converter.hpp"

EnPassant::EnPassant(Pawn* figure, Pawn* capturedFigure, int endVerticalPosition) : Move(figure, capturedFigure->getHorizontalPosition(), endVerticalPosition) {
    this->setCapturedPawn(capturedFigure);
}

EnPassant::~EnPassant() {}

void EnPassant::setCapturedPawn(Pawn* figure) {
    this->capturedPawn = figure;
}

Pawn* EnPassant::getCapturedPawn() {
    return this->capturedPawn;
}

Pawn* EnPassant::getPawn() {
    if (Pawn* pawn = dynamic_cast<Pawn*>(this->getFigure())) {
        return pawn;
    }
    return nullptr;
}

void EnPassant::execute() {
    this->getFigure()->setHorizontalPosition(this->getEndHorizontalPosition());
    this->getFigure()->setVerticalPosition(this->getEndVerticalPosition());
    this->getCapturedPawn()->setNotCaptured(false);
    this->getPawn()->incrementMoveCounter();
}

std::string EnPassant::getAsString() {
    std::string outputString = this->getFigure()->getName() + " from " + convertPos(this->getStartVerticalPosition(), 
        this->getStartHorizontalPosition()) + " takes " + this->getCapturedPawn()->getName() + " on "
        + convertPos(this->getEndVerticalPosition(), this->getEndHorizontalPosition()) + " en passant!";
    return outputString;
}