//
// Created by dominic on 02.01.22.
//

#include "Converter.hpp"

unsigned int convertHorizontal(std::string position) {
    char hor = position[0];

    switch(hor) {
        case 'A' | 'a':
            return 1;
        case 'B' | 'b':
            return 2;
        case 'C' | 'c':
            return 3;
        case 'D' | 'd':
            return 4;
        case 'E' | 'e':
            return 5;
        case 'F' | 'f':
            return 6;
        case 'G' | 'g':
            return 7;
        case 'H' | 'h':
            return 8;
        default:
            return -1;
    }
}

unsigned int convertVertical(std::string position) {
    return std::stoi(position.substr(1));
}

std::string convertPos(int vert, int hor) {
    switch(hor) {
        case 1:
            return "a" + std::to_string(vert);
        case 2:
            return "b" + std::to_string(vert);
        case 3:
            return "c" + std::to_string(vert);
        case 4:
            return "d" + std::to_string(vert);
        case 5:
            return "e" + std::to_string(vert);
        case 6:
            return "f" + std::to_string(vert);
        case 7:
            return "g" + std::to_string(vert);
        case 8:
            return "h" + std::to_string(vert);
        default:
            return "not found";
    }
}