//
// Created by jannik on 03.01.22.
//

#ifndef YETANOTHERCHESSGAME_CONVERTER_H
#define YETANOTHERCHESSGAME_CONVERTER_H

#include <string>
#include "../model/Figure.hpp"
#include "../model/figures/Pawn.hpp"
#include "../model/figures/Bishop.hpp"
#include "../model/figures/Knight.hpp"
#include "../model/figures/Rook.hpp"
#include "../model/figures/Queen.hpp"
#include "../model/figures/King.hpp"


unsigned int convertHorizontal(std::string position);
unsigned int convertVertical(std::string position);
std::string convertPos(int vert, int hor);

#endif //YETANOTHERCHESSGAME_CONVERTER_H