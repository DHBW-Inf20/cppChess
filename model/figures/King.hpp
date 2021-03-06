//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_KING_H
#define YETANOTHERCHESSGAME_KING_H

#include "../Figure.hpp"

class King : public Figure {
    public:
        King(std::string name, bool isWhite, int horizontalPosition, int verticalPosition);
        ~King() override;
        void incrementMoveCounter();
        int getMoveCounter();
        King* cloneFigure() override;

    private:
        int moveCounter;
};


#endif //YETANOTHERCHESSGAME_KING_H
