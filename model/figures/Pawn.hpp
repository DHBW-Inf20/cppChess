//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_FARMER_H
#define YETANOTHERCHESSGAME_FARMER_H

#include "../Figure.hpp"

class Pawn : public Figure {

    public:
        Pawn(std::string name, bool isWhite, int horizontalPosition, int verticalPosition);
        ~Pawn() override;
        void incrementMoveCounter();
        int getMoveCounter();
        Pawn* cloneFigure() override;

    private:
        int moveCounter;
};


#endif //YETANOTHERCHESSGAME_FARMER_H
