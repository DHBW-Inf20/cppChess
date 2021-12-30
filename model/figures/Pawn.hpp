//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_FARMER_H
#define YETANOTHERCHESSGAME_FARMER_H

#include "../Figure.hpp"

class Pawn : public Figure {
    public:
        Pawn(std::string name, int horizontalPosition, int verticalPosition);
};


#endif //YETANOTHERCHESSGAME_FARMER_H
