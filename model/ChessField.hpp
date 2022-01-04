//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_CHESSFIELD_H
#define YETANOTHERCHESSGAME_CHESSFIELD_H

#include <vector>

#include "Player.hpp"
#include "MoveController.hpp"

class ChessField {
    public:
        ChessField(Player* player1, Player* player2);
        bool repaint(bool showIcons);
        int getCurrentPlayer();
        void nextPlayer();
        ~ChessField();

    private:
        Player* player1;
        Player* player2;
        int currentPlayer;
};


#endif //YETANOTHERCHESSGAME_CHESSFIELD_H
