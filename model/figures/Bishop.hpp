//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_RUNNER_H
#define YETANOTHERCHESSGAME_RUNNER_H

#include "../Figure.hpp"

class Bishop : public Figure {
    public:
        Bishop(std::string name, bool isWhite, int horizontalPosition, int verticalPosition);
        ~Bishop() override;
        Bishop* cloneFigure() override;
};


#endif //YETANOTHERCHESSGAME_RUNNER_H
