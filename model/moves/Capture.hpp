//
// Created by jannik on 03.01.22.
//

#ifndef YETANOTHERCHESSGAME_CAPTURE_H
#define YETANOTHERCHESSGAME_CAPTURE_H

#include "Move.hpp"

class Capture : public Move {

    private:
        Figure* capturedFigure;
        void setCapturedFigure(Figure* figure);

    public:
        Capture(Figure* figure, Figure* capturedFigure);
        Figure* getCapturedFigure();
        std::string getAsString() override;
        void execute() override;
};

#endif //YETANOTHERCHESSGAME_CAPTURE_H