//
// Created by dominic on 28.12.21.
//

#include "ChessField.hpp"
#include <iostream>
#include "Move.hpp"
#include <string>
#include <vector>
#include "Player.hpp"

ChessField::ChessField(Player* player1, Player* player2) {
    this->player1 = player1;
    this->player2 = player2;
    this->currentPlayer = 1;
}

bool ChessField::repaint() {
    try {
        std::cout << "   A    B    C    D    E    F    G    H" << std::endl;
        for(int rows = 0; rows <= 7; rows++) {
            std::cout << " ";
            for(int columns = 0; columns<=7; columns++) {
                std::cout << "-----";
            }
            std::cout << "-" << std::endl;

            std::cout << (rows + 1);
            for(int columns = 0; columns<=7; columns++) {
                bool fieldHasFigure = false;
                for(Figure* figure : *this->player1->getAllFigures()) {
                    if(rows + 1 == figure->getVerticalPosition() && columns + 1 == figure->getHorizontalPosition() && figure->getNotCaptured()) {
                        std::cout << "| " << figure->getName() << " ";
                        fieldHasFigure = true;
                        break;
                    }
                }
                if(!fieldHasFigure) {
                    for(Figure* figure : *this->player2->getAllFigures()) {
                        if(rows + 1 == figure->getVerticalPosition() && columns + 1 == figure->getHorizontalPosition() && figure->getNotCaptured()) {
                            std::cout << "| " << figure->getName() << " ";
                            fieldHasFigure = true;
                            break;
                        }
                    }
                }

                if(!fieldHasFigure) {
                    std::cout << "|    ";
                }
            }
            std::cout << "|" << std::endl;
        }

        std::cout << " ";
        for(int columns = 0; columns<=7; columns++) {
            std::cout << "-----";
        }
        std::cout << "-" << std::endl;

    } catch(std::exception *ex) {
        std::cout << ex->what() << std::endl;
        return false;
    }
    return true;
}

unsigned int convertPos(std::string position) {
    char hor = position[1];
    unsigned int vert = std::stoi(position.substr(0));

    switch(hor) {
        case 'A':
            return vert;
        case 'B':
            return 2 * vert;
        case 'C':
            return 3 * vert;
        case 'D':
            return 4 * vert;
        case 'E':
            return 5 * vert;
        case 'F':
            return 6 * vert;
        case 'G':
            return 7 * vert;
        case 'H':
            return 8 * vert;
        default:
            return -1;
    }
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
            return "";
    }
}

void ChessField::move() {
    Player* tmp;
    std::cout << "It's the turn of Player " << this->currentPlayer << std::endl;
    if(this->currentPlayer == 1) {
        tmp = this->player1;
        this->currentPlayer = 2;
    } else {
        tmp = this->player2;
        this->currentPlayer = 1;
    }

    std::string position;
    std::cout << "Enter the position of your figure:";
    std::cin >> position;



    std::cout << "Possible Moves:" << std::endl;
    Figure* selectedFigure = tmp->getPieceAtPosition((int) convertPos(position));

    int i = 1;
    std::vector<Move *>* moves = selectedFigure->calcPseudoLegalMoves();
    for(Move* possible : *moves) {
        std::cout << i << ". " << convertPos(possible->getEndHorizontalPosition(), possible->getEndVerticalPosition()) << std::endl;
        i++;
    }

    int choice;
    std::cout << "Your choice:";
    std::cin >> choice;
    selectedFigure->setVerticalPosition(moves->at(choice-1)->getEndVerticalPosition());
    selectedFigure->setHorizontalPosition(moves->at(choice-1)->getEndHorizontalPosition());
}

ChessField::~ChessField() {
    delete this->player1;
    delete this->player2;
}