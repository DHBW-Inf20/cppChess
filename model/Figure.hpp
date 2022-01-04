//
// Created by dominic on 25.12.21.
//

#ifndef YETANOTHERCHESSGAME_FIGURE_H
#define YETANOTHERCHESSGAME_FIGURE_H

#include <string>
#include <vector>

class Figure {
    private:
        std::string name;
        bool isWhite;
        int horizontalPosition;
        int verticalPosition;
        bool notCaptured;
        int value;

    public:
        Figure(std::string name, bool isWhite, int horizontalPosition, int verticalPosition, int value);
        virtual ~Figure() = default;
        void setName(std::string name);
        void setIsWhite(bool isWhite);
        void setHorizontalPosition(int horizontalPosition);
        void setVerticalPosition(int verticalPosition);
        void setNotCaptured(bool notCaptured);
        void setValue(int value);
        std::string getName();
        bool getIsWhite();
        int getHorizontalPosition();
        int getVerticalPosition();
        bool getNotCaptured();
        std::string returnIcon(bool showIcon);
        int getValue();

    protected:
        std::string icon;
};


#endif //YETANOTHERCHESSGAME_FIGURE_H
