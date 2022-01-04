//
// Created by jannik on 03.01.22.
//

#include "Capture.hpp"
#include "../figures/Pawn.hpp"
#include "../figures/King.hpp"
#include "../figures/Rook.hpp"


Capture::Capture(Figure* figure, Figure* capturedFigure) : Move(figure, capturedFigure->getHorizontalPosition(), capturedFigure->getVerticalPosition()) {
    this->setCapturedFigure(capturedFigure);
}

Capture::~Capture() {}

void Capture::setCapturedFigure(Figure* figure) {
    this->capturedFigure = figure;
}

Figure* Capture::getCapturedFigure() {
    return this->capturedFigure;
}

std::string Capture::getAsString() {
    std::string outputString = "Figure from (" + std::to_string(this->getStartHorizontalPosition()) 
        + "," + std::to_string(this->getStartVerticalPosition()) + ") captures on " + this->getCapturedFigure()->getName()
        + " (" + std::to_string(this->getEndHorizontalPosition()) + "," + std::to_string(this->getEndVerticalPosition()) + ")";
    return outputString;
}

void Capture::execute() {
    this->getFigure()->setHorizontalPosition(this->getEndHorizontalPosition());
    this->getFigure()->setVerticalPosition(this->getEndVerticalPosition());
    this->getCapturedFigure()->setNotCaptured(false);
    if (Pawn* pawn = dynamic_cast<Pawn*>(this->getFigure())) {
        pawn->incrementMoveCounter();
    } else if (King* king = dynamic_cast<King*>(this->getFigure())) {
        king->incrementMoveCounter();
    } else if (Rook* rook = dynamic_cast<Rook*>(this->getFigure())) {
        rook->incrementMoveCounter();
    }
}