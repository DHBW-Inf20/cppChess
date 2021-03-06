//
// Created by dominic on 28.12.21.
//

#include "ChessField.hpp"
#include "Player.hpp"

#include <iostream>

ChessField::ChessField(Player* player1, Player* player2) {
    this->player1 = player1;
    this->player2 = player2;
    this->currentPlayer = 1;
}

int ChessField::getCurrentPlayer() {
    return this->currentPlayer;
}

void ChessField::setCurrentPlayer(int player) {
    this->currentPlayer = player;
}

void ChessField::nextPlayer() {
    if(this->currentPlayer == 1) {
        this->player1->stop();
        this->currentPlayer = 2;
    } else {
        this->player2->stop();
        this->currentPlayer = 1;
    }
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
            if (this->currentPlayer == 1) {
                std::cout << "     A    B    C    D    E    F    G    H" << std::endl;
            } else {
                std::cout << "     H    G    F    E    D    C    B    A" << std::endl;
            }
            std::cout << "   ****************************************" << std::endl;
        } else {
            if (this->currentPlayer == 1) {
                std::cout << "    A     B     C     D     E     F     G     H" << std::endl;
            } else {
                std::cout << "    H     G     F     E     D     C     B     A" << std::endl;
            }
            std::cout << "   ************************************************" << std::endl;
        }

        if (this->currentPlayer == 1) {
            for(int row = 8; row >= 1; row--) {
                std::cout << row << " ";
                for(int column = 1; column <= 8; column++) {
                    Figure* f = nullptr;
                    std::vector<Figure*>* figures = this->player1->getUncapturedFigures();
                    for(Figure* figure : *figures) {
                        if(column == figure->getHorizontalPosition() && row == figure->getVerticalPosition()) {
                            f = figure;
                            std::vector<Figure*>().swap(*figures);
                            break;
                        }
                    }
                    if(f == nullptr) {
                        figures = this->player2->getUncapturedFigures();
                        for(Figure* figure : *figures) {
                            if(column == figure->getHorizontalPosition() && row == figure->getVerticalPosition()) {
                                f = figure;
                                std::vector<Figure*>().swap(*figures);
                                break;
                            }
                        }
                    }
                    std::cout << " * " << printField(column, row, f, showIcons) << " ";
                }
                std::cout << "*" << std::endl;
                if (showIcons) {
                    std::cout << "   ****************************************" << std::endl;
                } else {
                    std::cout << "   ************************************************" << std::endl;
                }
            }
        } else {
            for(int row = 1; row <= 8; row++) {
                std::cout << row << " ";
                for(int column = 8; column >= 1; column--) {
                    Figure* f = nullptr;
                    std::vector<Figure*>* figures = this->player1->getUncapturedFigures();
                    for(Figure* figure : *figures) {
                        if(column == figure->getHorizontalPosition() && row == figure->getVerticalPosition()) {
                            f = figure;
                            std::vector<Figure*>().swap(*figures);
                            break;
                        }
                    }
                    if(f == nullptr) {
                        figures = this->player2->getUncapturedFigures();
                        for(Figure* figure : *this->player2->getUncapturedFigures()) {
                            if(column == figure->getHorizontalPosition() && row == figure->getVerticalPosition()) {
                                f = figure;
                                std::vector<Figure*>().swap(*figures);
                                break;
                            }
                        }
                    }
                    std::cout << " * " << printField(column, row, f, showIcons) << " ";
                }
                std::cout << "*" << std::endl;
                if (showIcons) {
                    std::cout << "   ****************************************" << std::endl;
                } else {
                    std::cout << "   ************************************************" << std::endl;
                }
            }
        }
        
        if(showIcons) {
            if (this->currentPlayer == 1) {
                std::cout << "     A    B    C    D    E    F    G    H" << std::endl;
            } else {
                std::cout << "     H    G    F    E    D    C    B    A" << std::endl;
            }
        } else {
            if (this->currentPlayer == 1) {
                std::cout << "    A     B     C     D     E     F     G     H" << std::endl;
            } else {
                std::cout << "    H     G     F     E     D     C     B     A" << std::endl;
            }
        }
    } catch(std::exception *ex) {
        std::cout << ex->what() << std::endl;
        return false;
    }
    return true;
}

ChessField::~ChessField() {}