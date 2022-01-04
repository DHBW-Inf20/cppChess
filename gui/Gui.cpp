//
// Created by dominic on 03.01.22.
//

#include <iostream>
#include <string>

#include "Gui.hpp"
#include "../helper/Converter.hpp"

Gui::Gui() {
    this->player1 = new Player(true);
    this->player2 = new Player(false);
    this->chessField = new ChessField(this->player1, this->player2);
    this->moveController = new MoveController(this->player1, this->player2);
}

/**
 * Prints the header of the game!
 */
void Gui::printWelcomeScreen() {
    std::cout << "Welcome to YetAnotherChessGame V1.0!" << std::endl;
}

/**
 * Prints the Main-Menu
 * @return 1 for new game, 2 for settings, -1 to quit the game
 */
int Gui::printMainMenu() {
    std::string temp_input;
    std::cout << "**************************************************" << std::endl;
    std::cout << "* Press 1 to start a new Game!                   *" << std::endl;
    std::cout << "* Press 2 to enter the settings!                 *" << std::endl;
    std::cout << "* Press q to quit the game!                      *" << std::endl;
    std::cout << "**************************************************" << std::endl;
    std::cout << "Your input: ";
    std::cin >> temp_input;

    if(temp_input == "q" || temp_input == "Q") {
        return -1;
    } else if(temp_input == "1") {
        return 1;
    } else if(temp_input == "2") {
        return 2;
    } else {
        std::cout << "No valid input!" << std::endl;
        return this->printMainMenu();
    }
}

void Gui::printChessField(Settings* settings) {
    this->chessField->repaint(settings->getShowIcons());
}

void Gui::printSettings(Settings* settings) {
    std::string temp_input;

    do {
        std::cout << "****************************************************" << std::endl;
        if(!settings->getShowIcons()) {
            std::cout << "* Press 1 to show Icons instead of names in field! *" << std::endl;
        } else {
            std::cout << "* Press 1 to show names instead of icons in field! *" << std::endl;
        }
        if(!settings->getShowPossibleMoves()) {
            std::cout << "* Press 2 to show possible moves!                  *" << std::endl;
        } else {
            std::cout << "* Press 2 to hide possible moves!                  *" << std::endl;
        }
        std::cout << "* Press q to quit the game!                        *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        std::cout << "Your input: ";
        std::cin >> temp_input;

        if(temp_input == "1") {
            settings->setShowIcons(!settings->getShowIcons());
        }
        if(temp_input == "2") {
            settings->setShowPossibleMoves(!settings->getShowPossibleMoves());
        }
    } while (temp_input != "q" && temp_input != "Q");
}

int Gui::printMenuInTheGame() {
    std::string temp_input;
    std::cout << "It's the turn of player " << this->chessField->getCurrentPlayer() << "!" << std::endl;
    std::cout << "(S)elect figure, (C)aptured figures, (Q)uit game!" << std::endl;
    std::cout << "Your input: ";
    std::cin >> temp_input;

    if(temp_input == "s" || temp_input == "S") {
        return 1;
    } else if(temp_input == "c" || temp_input == "C") {
        return 2;
    } else if(temp_input == "q" || temp_input == "Q") {
        std::cout << "Are you sure to quit the game (Y,N)?";
        std::cin >> temp_input;
        if(temp_input == "Y") {
            return -1;
        } else {
            return this->printMenuInTheGame();
        }
    } else {
        std::cout << "No valid input!" << std::endl;
        return this->printMenuInTheGame();
    }
}

void Gui::getAllCapturedFigures() {
    Player* tmp;
    if(this->chessField->getCurrentPlayer() == 1) {
        tmp = this->player1;
    } else {
        tmp = this->player2;
    }

    std::cout << "List of captured figures: " << std::endl;
    for(Figure* f : *tmp->getAllFigures()) {
        if(!f->getNotCaptured()) {
            std::cout << f->getName() << std::endl;
        }
    }
}

void Gui::selectAFigure(Settings* settings) {
    std::string position;
    std::cout << "Select a figure by coordinates (A1): ";
    std::cin >> position;

    Player* current;
    if(this->chessField->getCurrentPlayer() == 1) {
        current = this->player1;
    } else {
        current = this->player2;
    }

    Figure* selectedFigure = current->getPieceAtPosition(convertHorizontal(position), convertVertical(position));
    if(selectedFigure == nullptr) {
        std::cout << "You don't have a figure on this square!" << std::endl;
        return this->selectAFigure(settings);
    } else {
        std::cout << selectedFigure->getName() << " selected at position " << position << "!" << std::endl;

        std::vector<Move *>* moves = this->moveController->getPseudoLegalMoves(selectedFigure);
        if(moves->empty()) {
            std::cout << "There are no moves for this figure!" << std::endl;
            return this->selectAFigure(settings);
        }

        // list all Moves
        if(settings->getShowPossibleMoves()) {
            std::cout << "Possible Moves: " << std::endl;

            int i = 1;
            for(Move* possible : *moves) {
                std::cout << i << ". " << convertPos(possible->getEndVerticalPosition(), possible->getEndHorizontalPosition()) << std::endl;
                i++;
            }

            std::string choice;
            std::cout << "Enter your choice or (S)elect another figure: ";
            std::cin >> choice;

            if(choice == "s" || choice == "S") {
                return this->selectAFigure(settings);
            } else {
                Move* mv = moves->at(std::stoi(choice) - 1);
                this->moveController->addMoveToHistory(mv);
                mv->execute();
                std::cout << mv->getAsString() << std::endl;
                this->chessField->nextPlayer();
            }
        } else {
            std::string choice;
            std::cout << "Enter the end position (A1) or (S)elect another figure: ";
            std::cin >> choice;
            if(choice == "s" || choice == "S") {
                return this->selectAFigure(settings);
            } else {
                Move* mv = nullptr;
                for(Move* possible : *moves) {
                    if(convertPos(possible->getEndVerticalPosition(), possible->getEndHorizontalPosition()) == choice) {
                        mv = possible;
                        break;
                    }
                }
                if(mv == nullptr) {
                    std::cout << "No valid Move!" << std::endl;
                    return this->selectAFigure(settings);
                } else {
                    this->moveController->addMoveToHistory(mv);
                    mv->execute();
                    std::cout << mv->getAsString() << std::endl;
                    this->chessField->nextPlayer();
                }
            }
        }
    }
}

Gui::~Gui() {
    delete this->chessField;
    delete this->player1;
    delete this->player2;
}