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

class Player {
    private:
        bool isWhite;
        Rook *firstRook, *secondRook;
        Bishop *firstBishop, *secondBishop;
        Knight *firstKnight, *secondKnight;
        Queen *queen;
        King *king;
        Pawn *pawns[];

    public:
        Player(bool isWhite);
        ~Player();
        void setIsWhite(bool isWhite);
        std::vector<Figure*>* getAllFigures();
        std::vector<Figure*>* getUncapturedFigures();
        Figure* getPieceAtPosition(int position);
};


#endif //YETANOTHERCHESSGAME_OPPONENT_H
