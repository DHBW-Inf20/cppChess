//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_QUEEN_H
#define YETANOTHERCHESSGAME_QUEEN_H

#include "../Figure.hpp"

class Queen : public Figure {
    public:
        Queen(std::string name, bool isWhite, int horizontalPosition, int verticalPosition);
        std::vector<Move*>* calcPseudoLegalMoves() override;
};


#endif //YETANOTHERCHESSGAME_QUEEN_H
