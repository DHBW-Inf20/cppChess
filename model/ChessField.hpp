//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_CHESSFIELD_H
#define YETANOTHERCHESSGAME_CHESSFIELD_H

#include <vector>

#include "Player.hpp"

class ChessField {
    public:
        ChessField(Player* player1, Player* player2);
        bool repaint();
        void move();
        ~ChessField();

    private:
        Player* player1;
        Player* player2;
        int currentPlayer;
};


#endif //YETANOTHERCHESSGAME_CHESSFIELD_H
