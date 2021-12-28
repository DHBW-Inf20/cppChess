//
// Created by dominic on 25.12.21.
//

#ifndef YETANOTHERCHESSGAME_FIGURE_H
#define YETANOTHERCHESSGAME_FIGURE_H

#include <string>

class Figure {
    private:
        std::string horizontalPosition;
        int verticalPosition;
        int delta1;
        int delta2;
        bool moveEndless;
        bool moveOnlyForward;

    public:
        void setPosition(std::string horizontal, int vertical);
        std::string getHorizontalPosition();
        int getVerticalPosition();
        int getDelta1();
        int getDelta2();
        bool isMoveEndless();
        bool isMoveOnlyForward();

    protected:
        void setDelta(int delta1, int delta2, bool moveEndless, bool moveOnlyForward);
};


#endif //YETANOTHERCHESSGAME_FIGURE_H
