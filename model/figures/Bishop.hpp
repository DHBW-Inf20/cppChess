//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_RUNNER_H
#define YETANOTHERCHESSGAME_RUNNER_H

#include "../Figure.hpp"

class Bishop : public Figure {
    public:
        Bishop(std::string name, int horizontalPosition, int verticalPosition);
};


#endif //YETANOTHERCHESSGAME_RUNNER_H
