//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_CHESSFIELD_H
#define YETANOTHERCHESSGAME_CHESSFIELD_H

#include <vector>

#include "Player.hpp"

class ChessField {

    public:
        ChessField(Player player1, Player player2);
        bool repaint();

    private:
        Player player1 = new Player(false);
        Player player2 = new Player(true);
};


#endif //YETANOTHERCHESSGAME_CHESSFIELD_H
