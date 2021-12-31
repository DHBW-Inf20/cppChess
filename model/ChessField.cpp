//
// Created by dominic on 28.12.21.
//

#include "ChessField.hpp"
#include <iostream>

ChessField::ChessField(Player player1, Player player2) {
    this->player1 = player1;
    this->player2 = player2;
}

bool ChessField::repaint() {
    try {
        for(int rows = 0; rows <= 8; rows++) {

            for(int columns = 0; columns<=8; columns++) {
                std::cout << "--";
            }
            std::cout << "-" << std::endl;

            for(int columns = 0; columns<=8; columns++) {
                std::cout << "- ";
            }
            std::cout << "-" << std::endl;
        }

        for(int columns = 0; columns<=8; columns++) {
            std::cout << "--";
        }
        std::cout << "-" << std::endl;

    } catch(std::exception *ex) {
        std::cout << ex->what() << std::endl;
        return false;
    }
    return true;
}