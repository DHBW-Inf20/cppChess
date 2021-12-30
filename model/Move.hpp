//
// Created by jannik on 30.12.21.
//

#ifndef YETANOTHERCHESSGAME_MOVE_H
#define YETANOTHERCHESSGAME_MOVE_H

#include <string>

class Move {
    private:
        int startHorizontalPosition;
        int startVerticalPosition;
        int endHorizontalPosition;
        int endVerticalPosition;

    public: 
         Move(int startHorizontalPosition, int startVerticalPosition, int endHorizontalPosition, int endVerticalPosition);
        void setStartHorizontalPosition(int startHorizontalPosition);
        void setStartVerticalPosition(int startVerticalPosition);
        void setEndHorizontalPosition(int endHorizontalPosition);
        void setEndVerticalPosition(int endVerticalPosition);
        int getStartHorizontalPosition();
        int getStartVerticalPosition();
        int getEndHorizontalPosition();
        int getEndVerticalPosition();
        std::string getAsString();
};


#endif //YETANOTHERCHESSGAME_MOVE_H
