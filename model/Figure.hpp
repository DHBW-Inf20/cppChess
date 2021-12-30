//
// Created by dominic on 25.12.21.
//

#ifndef YETANOTHERCHESSGAME_FIGURE_H
#define YETANOTHERCHESSGAME_FIGURE_H

#include <string>

class Figure {
    private:
        std::string name;
        int horizontalPosition;
        int verticalPosition;
        bool notCaptured;
        int delta1;
        int delta2;
        bool moveEndless;
        bool moveOnlyForward;

    public:
        Figure(std::string name, int horizontalPosition, int verticalPosition);
        void setName(std::string name);
        void setHorizontalPosition(int horizontalPosition);
        void setVerticalPosition(int verticalPosition);
        void setNotCaptured(bool notCaptured);
        std::string getName();
        int getHorizontalPosition();
        int getVerticalPosition();
        bool getNotCaptured();
        int getDelta1();
        int getDelta2();
        bool isMoveEndless();
        bool isMoveOnlyForward();

    protected:
        void setDelta(int delta1, int delta2, bool moveEndless, bool moveOnlyForward);
};


#endif //YETANOTHERCHESSGAME_FIGURE_H
