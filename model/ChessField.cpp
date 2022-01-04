//
// Created by dominic on 28.12.21.
//

#include "ChessField.hpp"
#include "Player.hpp"
#include "../helper/Converter.hpp"

#include <iostream>
#include <string>
#include <vector>

ChessField::ChessField(Player* player1, Player* player2) {
    this->player1 = player1;
    this->player2 = player2;
    this->currentPlayer = 1;
    this->moveController = new MoveController(player1, player2);
}

int ChessField::getCurrentPlayer() {
    return this->currentPlayer;
}

std::string printField(int horizontal, int vertical, Figure* figure, bool showIcons) {
    std::string tmp;
    if(showIcons) {
        if((vertical % 2 == 1 && horizontal % 2 == 1) || (vertical % 2 == 0 && horizontal % 2 == 0)) {
            tmp = "\u25A1";
        } else {
            tmp = "\u25A0";
        }
    } else {
        tmp = "  ";
    }
    if(figure != nullptr) {
        tmp = figure->returnIcon(showIcons);
    }
    return tmp;
}


bool ChessField::repaint(bool showIcons) {
    try {
        if(showIcons) {
            std::cout << "    A   B   C   D   E   F   G   H" << std::endl;
            std::cout << "  *********************************" << std::endl;
        } else {
            std::cout << "    A     B     C     D     E     F     G     H" << std::endl;
            std::cout << "   ************************************************" << std::endl;
        }


        for(int row = 8; row >= 1; row--) {

            std::cout << row << " ";
            for(int column = 1; column <= 8; column++) {
                Figure* f = nullptr;
                for(Figure* figure : *this->player1->getUncapturedFigures()) {
                    if(column == figure->getHorizontalPosition() && row == figure->getVerticalPosition()) {
                        f = figure;
                        break;
                    }
                }
                if(f == nullptr) {
                    for(Figure* figure : *this->player2->getUncapturedFigures()) {
                        if(column == figure->getHorizontalPosition() && row == figure->getVerticalPosition()) {
                            f = figure;
                            break;
                        }
                    }
                }
                std::cout << " * " << printField(column, row, f, showIcons) << " ";
            }
            std::cout << "*" << std::endl;

            if(showIcons) {
                std::cout << "  *********************************" << std::endl;
            } else {
                std::cout << "   ************************************************" << std::endl;
            }
        }
        if(showIcons) {
            std::cout << "    A   B   C   D   E   F   G   H" << std::endl;
        } else {
            std::cout << "    A     B     C     D     E     F     G     H" << std::endl;
        }
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

    Figure* selectedFigure = nullptr;
    std::vector<Move *>* moves;
    do {
        std::string position;
        std::cout << "Enter the position of your figure:";
        std::cin >> position;

        Figure* selectedFigure = current->getPieceAtPosition(convertHorizontal(position), convertVertical(position));
        if (selectedFigure != nullptr) {
             moves = this->moveController->getPseudoLegalMoves(selectedFigure);
             if (moves->size() == 0) {
                 std::cout << "This figure has no moves!" << std::endl;
             } else {
                 break;
             }
        } else {
            std::cout << "You don't have a figure on this square!";
        }

    } while(!selectedFigure);
    
    std::cout << "Possible Moves:" << std::endl;

    int i = 1;
    for(Move* possible : *moves) {
        std::cout << i << ". " << convertPos(possible->getEndVerticalPosition(), possible->getEndHorizontalPosition()) << std::endl;
        i++;
    }

    int choice;
    std::cout << "Your choice:";
    std::cin >> choice;

    Move* mv = moves->at(choice-1);
    this->moveController->addMoveToHistory(mv);
    mv->execute();
    std::cout << mv->getAsString() << std::endl;
}

ChessField::~ChessField() {
    delete this->moveController;
    delete this->player1;
    delete this->player2;
}