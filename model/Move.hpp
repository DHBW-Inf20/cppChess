//
// Created by jannik on 30.12.21.
//

#ifndef YETANOTHERCHESSGAME_MOVE_H
#define YETANOTHERCHESSGAME_MOVE_H

class Move {
    private:
        int startPos;
        int endPos;

    public: 
        Move(int startPos, int endPos);
        void setStartPos(int startPos);
        void setEndPos(int endPos);
        int getStartPos();
        int getEndPos();
};


#endif //YETANOTHERCHESSGAME_MOVE_H
