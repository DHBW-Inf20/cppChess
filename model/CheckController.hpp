//
// Created by jannik on 05.01.22.
//

#ifndef YETANOTHERCHESSGAME_CHECKCONTROLLER_H
#define YETANOTHERCHESSGAME_CHECKCONTROLLER_H

#include<vector>
#include "Player.hpp"
#include "moves/Move.hpp"
#include "moves/Capture.hpp"
#include "moves/Castle.hpp"

class CheckController {
    private:
        Player* whitePlayer;
        Player* blackPlayer;
        Player* getWhitePlayer();
        Player* getBlackPlayer();
    
    public:
        CheckController(Player* whitePlayer, Player* blackPlayer);
        ~CheckController();
        std::vector<Player*>* getClonedPositionAfterMove(Move*);
        std::vector<Move*>* validateMoves(std::vector<Move*>* moves);
        bool isCheck(std::vector<Player*>* players);
};

#endif  //YETANOTHERCHESSGAME_CHECKCONTROLLER_H