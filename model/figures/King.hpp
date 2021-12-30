//
// Created by dominic on 28.12.21.
//

#ifndef YETANOTHERCHESSGAME_KING_H
#define YETANOTHERCHESSGAME_KING_H

#include "../Figure.hpp"

class King : public Figure {
    public:
        King(std::string name, int horizontalPosition, int verticalPosition);
        std::vector<Move*>* calcPseudoLegalMoves() override;
};


#endif //YETANOTHERCHESSGAME_KING_H
