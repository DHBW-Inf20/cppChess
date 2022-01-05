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
#include "Figure.hpp"
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
        std::vector<Figure*> *figures = new std::vector<Figure*>;
        std::vector<Pawn*> *pawns = new std::vector<Pawn*>;

    public:
        Player(bool isWhite);
        Player(bool isWhite, std::vector<Figure*>* figures);
        ~Player();
        void setIsWhite(bool isWhite);
        bool getIsWhite();
        std::vector<Figure*>* getAllFigures();
        std::vector<Figure*>* getUncapturedFigures();
        Figure* getPieceAtPosition(int horizontal, int vertical);
        Figure* hasFigureOnSquare(int horizontalPosition, int verticalPosition);
        int getUncapturedMaterialValue();
        King* getKing();
        Player* clonePlayer();
};


#endif //YETANOTHERCHESSGAME_OPPONENT_H
