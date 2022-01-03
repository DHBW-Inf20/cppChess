//
// Created by jannik on 30.12.21.
//

#ifndef YETANOTHERCHESSGAME_MOVE_H
#define YETANOTHERCHESSGAME_MOVE_H

#include <string>
#include "../Figure.hpp"

class Move {
    private:
        Figure* figure;
        int startHorizontalPosition;
        int startVerticalPosition;
        int endHorizontalPosition;
        int endVerticalPosition;

    public: 
        Move(Figure* figure, int endHorizontalPosition, int endVerticalPosition);
        void setFigure(Figure* figure);
        void setStartHorizontalPosition(int startHorizontalPosition);
        void setStartVerticalPosition(int startVerticalPosition);
        void setEndHorizontalPosition(int endHorizontalPosition);
        void setEndVerticalPosition(int endVerticalPosition);
        Figure* getFigure();
        int getStartHorizontalPosition();
        int getStartVerticalPosition();
        int getEndHorizontalPosition();
        int getEndVerticalPosition();
        virtual std::string getAsString();
        virtual void execute();
};


#endif //YETANOTHERCHESSGAME_MOVE_H
