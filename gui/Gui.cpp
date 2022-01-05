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
    this->checkController = new CheckController(this->player1, this->player2);
    this->checkmate = false;
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
        std::cout << "* Press Q to return to the start menu!                        *" << std::endl;
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
    std::cout << "It's ";
    if (this->chessField->getCurrentPlayer() == 1) {
        std::cout << "White's";
    } else {
        std::cout << "Black's";
    }
    std::cout << " turn now!" << std::endl;
    std::cout << "(S)elect figure, (C)ompare material, (Q)uit game!" << std::endl;
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

void Gui::getMaterialComparison() {
    Player* currentPlayer;
    Player* opponentPlayer;
    if(this->chessField->getCurrentPlayer() == 1) {
        currentPlayer = this->player1;
        opponentPlayer = this->player2;
    } else {
        currentPlayer = this->player2;
        opponentPlayer = this->player1;
    }

    int currentMaterialValue = currentPlayer->getUncapturedMaterialValue();
    int opponentMaterialValue = opponentPlayer->getUncapturedMaterialValue();
    
    if (currentMaterialValue > opponentMaterialValue) {
        std::cout << "You are currently up " << (currentMaterialValue-opponentMaterialValue);
        if (currentMaterialValue-opponentMaterialValue > 1) {
            std::cout << " points ";
        } else {
            std::cout << " point ";
        }
        std::cout << "of material!" << std::endl;
    } else if (currentMaterialValue < opponentMaterialValue) {
        std::cout << "You are currently down " << (opponentMaterialValue-currentMaterialValue);
        if (opponentMaterialValue-currentMaterialValue > 1) {
            std::cout << " points ";
        } else {
            std::cout << " point ";
        }
        std::cout << "of material!" << std::endl;
    } else {
        std::cout << "There is equal material on the board!" << std::endl;
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

    Figure* selectedFigure = current->getPieceAtPosition((int) convertHorizontal(position), (int) convertVertical(position));
    if(selectedFigure == nullptr) {
        std::cout << "You don't have a figure on this square!" << std::endl;
        return this->selectAFigure(settings);
    } else {
        std::vector<Move*>* moves = this->moveController->getPseudoLegalMoves(selectedFigure);
        std::vector<Move*>* validMoves = this->checkController->validateMoves(moves);

        if(validMoves->empty()) {
            std::cout << "There are no moves for this figure!" << std::endl;
            return this->selectAFigure(settings);
        } else {
            std::cout << selectedFigure->getName() << " selected at position " << position << "!" << std::endl;
        }

        // list all Moves
        if(settings->getShowPossibleMoves()) {
            std::cout << "Possible Moves: " << std::endl;

            int i = 1;
            for(Move* possible : *validMoves) {
                std::cout << i << ". " << convertPos(possible->getEndVerticalPosition(), possible->getEndHorizontalPosition()) << std::endl;
                i++;
            }

            std::string choice;
            std::cout << "Enter your choice (1,2,...) or (S)elect another figure: ";
            std::cin >> choice;

            if(choice == "s" || choice == "S") {
                return this->selectAFigure(settings);
            } else {
                Move* mv = validMoves->at(std::stoi(choice) - 1);
                this->moveController->addMoveToHistory(mv);
                mv->execute();
                std::cout << mv->getAsString() << std::endl;

                //verify, if an player is in check
                if (chessField->getCurrentPlayer() == 1) {
                    std::vector<Move*>* nextPseudoLegalMoves = moveController->getPseudoLegalMovesForAll(this->player2->getUncapturedFigures());
                    if (checkController->validateMoves(nextPseudoLegalMoves)->empty()) {
                        std::cout << "White won by checkmate!!!" << std::endl;
                        this->checkmate = true;
                    } else {
                        std::vector<Player*>* players = new std::vector<Player*>();
                        players->push_back(this->player2);
                        players->push_back(this->player1);
                        if (checkController->isCheck(players)) {
                            std::cout << "Attention, Black: You are in check!" << std::endl;
                        }
                    }
                } else {
                    std::vector<Move*>* nextPseudoLegalMoves = moveController->getPseudoLegalMovesForAll(this->player1->getUncapturedFigures());
                    if (checkController->validateMoves(nextPseudoLegalMoves)->empty()) {
                        std::cout << "Black won by checkmate!!!" << std::endl;
                        this->checkmate = true;
                    } else {
                        std::vector<Player*>* players = new std::vector<Player*>();
                        players->push_back(this->player1);
                        players->push_back(this->player2);
                        if (checkController->isCheck(players)) {
                            std::cout << "Attention, White: You are in check!" << std::endl;
                        }
                    }
                }
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
                for(Move* possible : *validMoves) {
                    if((convertHorizontal(choice) == possible->getEndHorizontalPosition()) && (convertVertical(choice) == possible->getEndVerticalPosition())) {
                        mv = possible;
                        break;
                    }
                }
                if(mv == nullptr) {
                    std::cout << "This is not a valid move!" << std::endl;
                    return this->selectAFigure(settings);
                } else {
                    this->moveController->addMoveToHistory(mv);
                    mv->execute();
                    std::cout << mv->getAsString() << std::endl;
                    //verify, if any player is in check
                    if (chessField->getCurrentPlayer() == 1) {
                        std::vector<Move*>* nextPseudoLegalMoves = moveController->getPseudoLegalMovesForAll(this->player2->getUncapturedFigures());
                        if (checkController->validateMoves(nextPseudoLegalMoves)->empty()) {
                            std::cout << "White won by checkmate!!!" << std::endl;
                            this->checkmate = true;
                        } else {
                            std::vector<Player*>* players = new std::vector<Player*>();
                            players->push_back(this->player2);
                            players->push_back(this->player1);
                            if (checkController->isCheck(players)) {
                                std::cout << "Attention, Black: You are in check!" << std::endl;
                            }
                        }
                    } else {
                        std::vector<Move*>* nextPseudoLegalMoves = moveController->getPseudoLegalMovesForAll(this->player1->getUncapturedFigures());
                        if (checkController->validateMoves(nextPseudoLegalMoves)->empty()) {
                            std::cout << "Black won by checkmate!!!" << std::endl;
                            this->checkmate = true;
                        } else {
                            std::vector<Player*>* players = new std::vector<Player*>();
                            players->push_back(this->player1);
                            players->push_back(this->player2);
                            if (checkController->isCheck(players)) {
                                std::cout << "Attention, White: You are in check!" << std::endl;
                            }
                        }
                    }
                    this->chessField->nextPlayer();
                }
            }
        }
    }
}

bool Gui::isCheckmate() {
    return this->checkmate;
}

Gui::~Gui() {
    delete this->chessField;
    delete this->player1;
    delete this->player2;
}