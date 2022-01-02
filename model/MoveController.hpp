//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_MOVECONTROLLER_H
#define YETANOTHERCHESSGAME_MOVECONTROLLER_H

#include "Player.hpp"
#include <vector>

class MoveController {

    public:
        MoveController(Player* whitePlayer, Player* blackPlayer);
        std::vector<Move*>* getPseudoLegalMoves(Figure* figure);
        std::vector<Move*>* getPseudoLegalMovesForAll(std::vector<Figure*>* figures);

    private:
        Player* whitePlayer;
        Player* blackPlayer;
        std::vector<Move*>* getBishopMoves(Bishop* bishop);
        std::vector<Move*>* getKingMoves(King* king);
        std::vector<Move*>* getKnightMoves(Knight* knight);
        std::vector<Move*>* getPawnMoves(Pawn* pawn);
        std::vector<Move*>* getQueenMoves(Queen* queen);
        std::vector<Move*>* getRookMoves(Rook* rook);
};

#endif //YETANOTHERCHESSGAME_MOVECONTROLLER_H