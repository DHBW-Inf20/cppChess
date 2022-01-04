//
// Created by dominic on 02.01.22.
//

#include "Converter.hpp"

unsigned int convertHorizontal(std::string position) {
    char hor = position[0];

    switch(hor) {
        case 'A':
            return 1;
        case 'a':
            return 1;
        case 'B':
            return 2;
        case 'b':
            return 2;
        case 'C':
            return 3;
        case 'c':
            return 3;
        case 'D': 
            return 4;
        case 'd':
            return 4;
        case 'E': 
            return 5;
        case 'e':
            return 5;
        case 'F': 
            return 6;
        case 'f':
            return 6;
        case 'G': 
            return 7;
        case 'g':
            return 7;
        case 'H': 
            return 8;
        case 'h':
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
            return "A" + std::to_string(vert);
        case 2:
            return "B" + std::to_string(vert);
        case 3:
            return "C" + std::to_string(vert);
        case 4:
            return "D" + std::to_string(vert);
        case 5:
            return "E" + std::to_string(vert);
        case 6:
            return "F" + std::to_string(vert);
        case 7:
            return "G" + std::to_string(vert);
        case 8:
            return "H" + std::to_string(vert);
        default:
            return "not found";
    }
}