//
// Created by jannik on 03.01.22.
//

#ifndef YETANOTHERCHESSGAME_CONVERTER_H
#define YETANOTHERCHESSGAME_CONVERTER_H

#include <string>

unsigned int convertHorizontal(std::string position);
unsigned int convertVertical(std::string position);
std::string convertPos(int vert, int hor);


#endif //YETANOTHERCHESSGAME_CONVERTER_H