//
// Created by jannik on 07.01.22.
//

#ifndef YETANOTHERCHESSGAME_ENPASSANT_H
#define YETANOTHERCHESSGAME_ENPASSANT_H

#include "Move.hpp"
#include "../figures/Pawn.hpp"

class EnPassant : public Move {
    private:
        Pawn* capturedPawn;

    public:
        EnPassant(Pawn* figure, Pawn* capturedFigure, int endVerticalPosition);
        ~EnPassant();
        Pawn* getPawn();
        void setCapturedPawn(Pawn* figure);
        Pawn* getCapturedPawn();
        std::string getAsString();
        void execute();
};

#endif //YETANOTHERCHESSGAME_ENPASSANT_H