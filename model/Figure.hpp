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

    public:
        void setPosition(std::string horizontal, int vertical);
        std::string getHorizontalPosition();
        int getVerticalPosition();
        int getDelta1();
        int getDelta2();
        bool isMoveEndless();

    protected:
        void setDelta(int delta1, int delta2, bool moveEndless);
};


#endif //YETANOTHERCHESSGAME_FIGURE_H
