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
        std::vector<Figure*> *figures = new std::vector<Figure*>;
        int numberOfMoves;
        long time;
        int moves;
        int timeToFinish;
        long extra_time;
        int timeMode = 4;
        long startTime;

    public:
        Player(bool isWhite);
        Player(bool isWhite, std::vector<Figure*>* figures);
        ~Player();
        void setIsWhite(bool isWhite);
        bool getIsWhite();
        void setTimeMode(int timeMode);
        int getTimeMode();
        std::vector<Figure*>* getAllFigures();
        std::vector<Figure*>* getUncapturedFigures();
        Figure* getPieceAtPosition(int horizontal, int vertical);
        Figure* hasFigureOnSquare(int horizontalPosition, int verticalPosition);
        int getUncapturedMaterialValue();
        King* getKing();
        std::vector<Rook*>* getRooks();
        Player* clonePlayer();
        void start();
        void stop();
        long getTime();
        void setTime(long time);
        bool timeIsOver();
};


#endif //YETANOTHERCHESSGAME_OPPONENT_H
