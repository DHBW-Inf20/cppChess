//
// Created by jannik on 03.01.22.
//

#ifndef YETANOTHERCHESSGAME_CASTLE_H
#define YETANOTHERCHESSGAME_CASTLE_H

#include "Move.hpp"
#include "../figures/King.hpp"
#include "../figures/Rook.hpp"

class Castle : public Move {

    private:
        Rook* rook;
        int rookStartHorizontalPosition;
        int rookStartVerticalPosition;
        int rookEndHorizontalPosition;
        int rookEndVerticalPosition;
        void setRook(Rook* rook);
        void setRookStartHorizontalPosition(int rookStartHorizontalPosition);
        void setRookStartVerticalPosition(int rookStartVerticalPosition);
        void setRookEndHorizontalPosition(int rookEndHorizontalPosition);
        void setRookEndVerticalPosition(int rookEndVerticalPosition);

    public:
        Castle(King* king, int kingEndHorizontalPosition, int kingEndVerticalPosition, Rook* rook, int rookEndHorizontalPosition, int rookEndVerticalPosition);
        ~Castle();
        Rook* getRook();
        int getRookStartHorizontalPosition();
        int getRookStartVerticalPosition();
        int getRookEndHorizontalPosition();
        int getRookEndVerticalPosition();
};

#endif //YETANOTHERCHESSGAME_CASTLE_H