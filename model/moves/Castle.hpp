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
        bool isShort;
        int rookEndHorizontalPosition;
        int rookEndVerticalPosition;
        
        void setRookEndHorizontalPosition(int pos);
        void setRookEndVerticalPosition(int pos);
        int getRookEndHorizontalPosition();
        int getRookEndVerticalPosition();

    public:
        Castle(King* king, Rook* rook, bool isShort);
        bool getIsShort();
        King* getKing();
        Rook* getRook();
        void execute() override;
        std::string getAsString() override;
};

#endif //YETANOTHERCHESSGAME_CASTLE_H