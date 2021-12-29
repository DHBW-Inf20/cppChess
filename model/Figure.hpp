//
// Created by dominic on 25.12.21.
//

#ifndef YETANOTHERCHESSGAME_FIGURE_H
#define YETANOTHERCHESSGAME_FIGURE_H

#include <string>

class Figure {
    private:
        int position;     //Horizontal: pos div 8, Vertikal: pos mod 8. Bsp: 14 -> F2
        int delta1;
        int delta2;
        bool moveEndless;
        bool moveOnlyForward;

    public:
        void setPosition(int position);
        int getPosition();
        int getDelta1();
        int getDelta2();
        bool isMoveEndless();
        bool isMoveOnlyForward();

    protected:
        void setDelta(int delta1, int delta2, bool moveEndless, bool moveOnlyForward);
};


#endif //YETANOTHERCHESSGAME_FIGURE_H
