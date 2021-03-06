//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_TOWER_H
#define YETANOTHERCHESSGAME_TOWER_H

#include "../Figure.hpp"

class Rook : public Figure {
    public:
        Rook(std::string name, bool isWhite, int horizontalPosition, int verticalPosition);
        ~Rook() override;
        void incrementMoveCounter();
        int getMoveCounter();
        Rook* cloneFigure() override;

    private:
        int moveCounter;
};


#endif //YETANOTHERCHESSGAME_TOWER_H
