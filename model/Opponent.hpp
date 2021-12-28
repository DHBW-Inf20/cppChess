//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_OPPONENT_H
#define YETANOTHERCHESSGAME_OPPONENT_H

#include "figures/Rook.hpp"
#include "figures/Bishop.hpp"
#include "figures/Knight.hpp"
#include "figures/King.hpp"
#include "figures/Queen.hpp"
#include "figures/Pawn.hpp"
#include <vector>
#include <string>

class Opponent {
    private:
        Rook* firstRook, secondRook;
        Bishop firstBishop, secondBishop;
        Knight firstKnight, secondKnight;
        Queen queen;
        King king;
        Pawn* pawns;

    public:
        Opponent(int line);
        changeFigurePosition(int oldVertical, char oldHorizontal, int vertical, char horizontal);
        changeFigurePosition(std::string name, int vertical, char horizontal);
        ~Opponent();
};


#endif //YETANOTHERCHESSGAME_OPPONENT_H
