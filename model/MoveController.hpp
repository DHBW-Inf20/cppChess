//
// Created by jannik on 02.01.22.
//

#ifndef YETANOTHERCHESSGAME_MOVECONTROLLER_H
#define YETANOTHERCHESSGAME_MOVECONTROLLER_H

#include "Player.hpp"
#include "Move.hpp"
#include <vector>

class MoveController {

    public:
        MoveController(Player* whitePlayer, Player* blackPlayer);
        std::vector<Move*>* getPseudoLegalMoves(Figure* figure);
        std::vector<Move*>* getPseudoLegalMovesForAll(std::vector<Figure*>* figures);
        void addMoveToHistory(Move* move);
        Move* getMoveAtIndex(int index);
        Move* getLastMove();

    private:
        Player* whitePlayer;
        Player* blackPlayer;
        std::vector<Move*>* moveHistory = new std::vector<Move*>();
        std::vector<Move*>* getBishopMoves(Bishop* bishop);
        std::vector<Move*>* getKingMoves(King* king);
        std::vector<Move*>* getKnightMoves(Knight* knight);
        std::vector<Move*>* getPawnMoves(Pawn* pawn);
        std::vector<Move*>* getQueenMoves(Queen* queen);
        std::vector<Move*>* getRookMoves(Rook* rook);
};

#endif //YETANOTHERCHESSGAME_MOVECONTROLLER_H