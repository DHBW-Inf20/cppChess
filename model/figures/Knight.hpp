//
// Created by dominic on 25.12.21.
//

#ifndef YETANOTHERCHESSGAME_HORSE_H
#define YETANOTHERCHESSGAME_HORSE_H

#include "../Figure.hpp"

class Knight : public Figure {
    public:
        Knight(std::string name, bool isWhite, int horizontalPosition, int verticalPosition);
        ~Knight() override;
};

#endif //YETANOTHERCHESSGAME_HORSE_H
