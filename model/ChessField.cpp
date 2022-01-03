//
// Created by dominic on 28.12.21.
//

#include "ChessField.hpp"
#include "Player.hpp"
#include "../helper/Converter.cpp"

#include <iostream>
#include <string>
#include <vector>

ChessField::ChessField(Player* player1, Player* player2) {
    this->player1 = player1;
    this->player2 = player2;
    this->currentPlayer = 1;
    this->moveController = new MoveController(player1, player2);
}

std::string printField(int horizontal, int vertical, Figure* figure) {
    std::string tmp;
    if((vertical % 2 == 1 && horizontal % 2 == 1) || (vertical % 2 == 0 && horizontal % 2 == 0)) {
        tmp = "\u25A1";
    } else {
        tmp = "\u25A0";
    }
    if(figure != nullptr) {
        tmp = figure->returnIcon();
    }
    return tmp;
}


bool ChessField::repaint() {
    try {
        std::cout << "    A   B   C   D   E   F   G   H" << std::endl;
        std::cout << "  *********************************" << std::endl;
        for(int row = 1; row <= 8; row++) {

            std::cout << row << " ";
            for(int column = 1; column <= 8; column++) {
                Figure* f = nullptr;
                for(Figure* figure : *this->player1->getAllFigures()) {
                    if(column == figure->getHorizontalPosition() && row == figure->getVerticalPosition() && figure->getNotCaptured()) {
                        f = figure;
                        break;
                    }
                }
                if(f == nullptr) {
                    for(Figure* figure : *this->player2->getAllFigures()) {
                        if(column == figure->getHorizontalPosition() && row == figure->getVerticalPosition() && figure->getNotCaptured()) {
                            f = figure;
                            break;
                        }
                    }
                }
                std::cout << "* " << printField(column, row, f) << " ";
            }
            std::cout << "*" << std::endl;

            std::cout << "  *********************************" << std::endl;
        }
        std::cout << "    A   B   C   D   E   F   G   H" << std::endl;
    } catch(std::exception *ex) {
        std::cout << ex->what() << std::endl;
        return false;
    }
    return true;
}


void ChessField::move() {
    Player* current;
    Player* opponent;
    std::cout << "It's the turn of Player " << this->currentPlayer << std::endl;
    if(this->currentPlayer == 1) {
        current = this->player1;
        opponent = this->player2;
        this->currentPlayer = 2;
    } else {
        current = this->player2;
        opponent = this->player1;
        this->currentPlayer = 1;
    }

    std::string position;
    std::cout << "Enter the position of your figure:";
    std::cin >> position;

    std::cout << "Possible Moves:" << std::endl;
    Figure* selectedFigure = current->getPieceAtPosition((int) convertHorizontal(position), (int) convertVertical(&position));

    int i = 1;
    std::vector<Move *>* moves = this->moveController->getPseudoLegalMoves(selectedFigure);
    for(Move* possible : *moves) {
        std::cout << i << ". " << convertPos(possible->getEndVerticalPosition(), possible->getEndHorizontalPosition()) << std::endl;
        i++;
    }

    int choice;
    std::cout << "Your choice:";
    std::cin >> choice;

    Move* mv = moves->at(choice-1);
    this->moveController->addMoveToHistory(mv);
    selectedFigure->setVerticalPosition(mv->getEndVerticalPosition());
    selectedFigure->setHorizontalPosition(mv->getEndHorizontalPosition());
    std::cout << mv->getAsString() << std::endl;

    Figure* f = opponent->hasFigureOnSquare(mv->getEndHorizontalPosition(), mv->getEndVerticalPosition());
    if(f != nullptr) {
        std::cout << f->getName() << " was captured!" << std::endl;
        f->setNotCaptured(false);
    }
}

ChessField::~ChessField() {
    delete this->player1;
    delete this->player2;
}