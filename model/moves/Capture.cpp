//
// Created by jannik on 03.01.22.
//

#include "Capture.hpp"

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