//
// Created by dominic on 25.12.21.
//

#ifndef YETANOTHERCHESSGAME_FIGURE_H
#define YETANOTHERCHESSGAME_FIGURE_H

#include <string>

class Figure {
    private:
        std::string name;
        int position;     //Horizontal: pos div 8, Vertikal: pos mod 8. Bsp: 14 -> F2
        bool notCaptured;
        int delta1;
        int delta2;
        bool moveEndless;
        bool moveOnlyForward;

    public:
        Figure(std::string name, int position);
        void setName(std::string name);
        void setPosition(int position);
        void setNotCaptured(bool notCaptured);
        std::string getName();
        int getPosition();
        bool getNotCaptured();
        int getDelta1();
        int getDelta2();
        bool isMoveEndless();
        bool isMoveOnlyForward();

    protected:
        void setDelta(int delta1, int delta2, bool moveEndless, bool moveOnlyForward);
};


#endif //YETANOTHERCHESSGAME_FIGURE_H
