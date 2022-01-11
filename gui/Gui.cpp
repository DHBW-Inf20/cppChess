//
// Created by dominic on 03.01.22.
//

#include <iostream>

#include "Gui.hpp"
#include "../helper/Converter.hpp"
#include <ctype.h>

Gui::Gui() {
    this->settings = new Settings();
    this->resetChessField();
}

void Gui::resetChessField() {
    this->player1 = new Player(true);
    this->player2 = new Player(false);
    this->player1->setTimeMode(this->settings->getTimeMode());
    this->player2->setTimeMode(this->settings->getTimeMode());
    this->chessField = new ChessField(this->player1, this->player2);
    this->moveController = new MoveController(this->player1, this->player2);
    this->checkController = new CheckController(this->player1, this->player2);
    this->checkmate = false;
}

/**
 * Prints the header of the game!
 */
void Gui::printWelcomeScreen() {
    this->clear();
    std::cout << "Welcome to YetAnotherChessGame V1.0!" << std::endl;
}

/**
 * Prints the Main-Menu
 * @return 1 for new game, 2 to load a game, 3 for settings, -1 to quit the game
 */
int Gui::printMainMenu() {
    std::string temp_input;
    std::cout << "**************************************************" << std::endl;
    std::cout << "* Press 1 to start a new Game!                   *" << std::endl;
    std::cout << "* Press 2 to load a Game!                        *" << std::endl;
    std::cout << "* Press s to enter the settings!                 *" << std::endl;
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
    } else if(temp_input == "s" || temp_input == "S") {
        return 3;
    } else {
        std::cout << "No valid input!" << std::endl;
        return this->printMainMenu();
    }
}

void Gui::printChessField() {
    this->chessField->repaint(this->settings->getShowIcons());
}

void Gui::loadAGame() {
    try {
        std::string path;
        std::cout << "Enter a path to a valid Game-File: ";
        std::cin >> path;
        this->importExport = new ImportExport(path, ';');
        bool fileExists = this->importExport->exists();

        if(fileExists) {
            // meta-data in first line
            std::vector<std::vector<std::string>> data = this->importExport->importData();
            std::string first = data.at(0).at(0);
            int player = std::stoi(data.at(0).at(2));
            int timeMode = std::stoi(data.at(0).at(3));
            this->player1->setTime(std::stoi(data.at(0).at(4)));
            this->player2->setTime(std::stoi(data.at(0).at(4)));

            if(first != "YetAnotherChessGame") {
                throw 1;
            }

            // all figures are captured
            for(Figure* figure : *this->player1->getAllFigures()) {
                figure->setNotCaptured(false);
            }
            for(Figure* figure : *this->player2->getAllFigures()) {
                figure->setNotCaptured(false);
            }

            int row = 1;
            int column = 1;
            for(std::vector<std::string> line : data) {
                if(row != 1) {
                    for(std::string field : line) {
                        if(field != "") {
                            Player* tmp = nullptr;
                            if(field[0] == 'b') {
                                if(!player1->getIsWhite()) {
                                    tmp = player1;
                                } else if(!player2->getIsWhite()) {
                                    tmp = player2;
                                }
                            } else if(field[0] == 'w') {
                                if(player1->getIsWhite()) {
                                    tmp = player1;
                                } else if(player2->getIsWhite()) {
                                    tmp = player2;
                                }
                            }

                            if(tmp == nullptr) {
                                throw -1;
                            }
                            for(Figure* figure : *tmp->getAllFigures()) {
                                if(figure->getName() == field && !figure->getNotCaptured()) {
                                    figure->setNotCaptured(true);
                                    figure->setVerticalPosition(row-1);
                                    figure->setHorizontalPosition(column);
                                    break;
                                }
                            }
                        }
                        column++;
                    }
                }
                row++;
                column = 1;
            }
            this->chessField->setCurrentPlayer(player);
            this->settings->setTimeMode(timeMode);
            data.clear();
            std::vector<std::vector<std::string>>().swap(data);
        } else {
            throw -1;
        }
    } catch(int data) {
        std::cout << "Loading the game failed! Please enter a valid path!" << std::endl;
    }
}

void Gui::saveTheGame() {
    try {
        std::string path;
        std::cout << "Enter a path to save the game (File with 'csv' as extension): ";
        std::cin >> path;

        this->importExport = new ImportExport(path, ';');
        bool fileExists = this->importExport->exists();

        if(!fileExists) {
            std::vector<std::vector<std::string>> data;
            std::vector<std::string> firstLine;
            firstLine.push_back("YetAnotherChessGame");
            firstLine.push_back("1.0");
            firstLine.push_back(std::to_string(this->chessField->getCurrentPlayer()));
            firstLine.push_back(std::to_string(this->settings->getTimeMode()));
            firstLine.push_back(std::to_string(this->player1->getTime()));
            firstLine.push_back(std::to_string(this->player2->getTime()));
            data.push_back(firstLine);

            for(int i = 0; i<=7; i++) {
                std::vector<std::string> line;
                for(int j = 0; j<=7; j++) {
                    line.push_back("");
                }
                data.push_back(line);
            }

            std::vector<Figure*>* whiteFigures = this->player1->getUncapturedFigures();
            for(Figure* figure : *whiteFigures) {
                data.at(figure->getVerticalPosition()).at(figure->getHorizontalPosition()-1) = figure->getName();
            }
            std::vector<Figure*>().swap(*whiteFigures);

            std::vector<Figure*>* blackFigures = this->player2->getUncapturedFigures();
            for(Figure* figure : *blackFigures) {
                data.at(figure->getVerticalPosition()).at(figure->getHorizontalPosition()-1) = figure->getName();
            }
            std::vector<Figure*>().swap(*blackFigures);
            this->importExport->exportData(data);
            data.clear();
            std::vector<std::vector<std::string>>().swap(data);
        } else {
            throw -1;
        }
    } catch(int data) {
        std::cout << "Saving the game failed! Please enter a valid path!" << std::endl;
    }
}

void Gui::printSettings() {
    std::string temp_input;

    do {
        std::cout << "****************************************************" << std::endl;
        if(!this->settings->getShowIcons()) {
            std::cout << "* Press 1 to show Icons instead of names in field! *" << std::endl;
        } else {
            std::cout << "* Press 1 to show names instead of icons in field! *" << std::endl;
        }
        if(!this->settings->getShowPossibleMoves()) {
            std::cout << "* Press 2 to show possible moves!                  *" << std::endl;
        } else {
            std::cout << "* Press 2 to hide possible moves!                  *" << std::endl;
        }
        if(!this->settings->getResetUI()) {
            std::cout << "* Press 3 to enable UI clearing after every move!  *" << std::endl;
        } else {
            std::cout << "* Press 3 to disable UI clearing after every move! *" << std::endl;
        }
        std::cout << "* Set Time-Mode (Your choice: " << this->settings->getTimeMode() << "):                  *" << std::endl;
        std::cout << "*     4 for none                                   *" << std::endl;
        std::cout << "*     5 for blitz                                  *" << std::endl;
        std::cout << "*     6 for rapid                                  *" << std::endl;
        std::cout << "*     7 for classical                              *" << std::endl;
        std::cout << "* Press Q to return to the start menu!             *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        std::cout << "Your input: ";
        std::cin >> temp_input;

        if(temp_input == "1") {
            this->settings->setShowIcons(!this->settings->getShowIcons());
        }
        if(temp_input == "2") {
            this->settings->setShowPossibleMoves(!this->settings->getShowPossibleMoves());
        }
        if(temp_input == "3") {
            this->settings->setResetUI(!this->settings->getResetUI());
        }
        if(temp_input == "4" || temp_input == "5" || temp_input == "6" || temp_input == "7") {
            this->settings->setTimeMode(std::stoi(temp_input));
        }
        this->player1->setTimeMode(this->settings->getTimeMode());
        this->player2->setTimeMode(this->settings->getTimeMode());
    } while (temp_input != "q" && temp_input != "Q");
}

int Gui::printMenuInTheGame() {
    std::string temp_input;
    std::cout << "It's ";
    if (this->chessField->getCurrentPlayer() == 1) {
        this->player1->start();
        std::cout << "White's";

        if(this->settings->getTimeMode() == 4) {
            std::cout << " turn now!" << std::endl;
        } else {
            std::cout << " turn now! He's got " << (this->player1->getTime() / 1000) << "s left!" << std::endl;
        }
    } else {
        this->player2->start();
        std::cout << "Black's";

        if(this->settings->getTimeMode() == 4) {
            std::cout << " turn now!" << std::endl;
        } else {
            std::cout << " turn now! He's got " << (this->player2->getTime() / 1000) << "s left!" << std::endl;
        }
    }
    std::cout << "(S)elect figure, (C)ompare material, (Q)uit game!" << std::endl;
    std::cout << "Your input: ";
    std::cin >> temp_input;

    if(temp_input == "s" || temp_input == "S") {
        return 1;
    } else if(temp_input == "c" || temp_input == "C") {
        return 2;
    } else if(temp_input == "q" || temp_input == "Q") {
        std::cout << "Are you sure (Y,N)? ";
        std::cin >> temp_input;
        if(temp_input == "Y") {
            std::cout << "Do you want to save the game (Y,N)? ";
            std::cin >> temp_input;
            if(temp_input == "Y" || temp_input == "y") {
                return 3;
            } else {
                return -1;
            }
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

bool validInput(std::string input) {
    if(!std::isalpha(input[0]) || !std::isdigit(input[1])) {
        return false;
    } else {
        return true;
    }
}

Figure* getFigure(Player* player, std::string input) {
    if(!validInput(input)) {
        return nullptr;
    }

    int horizontal = (int) convertHorizontal(input);
    int vertical = (int) convertVertical(input);

    return player->getPieceAtPosition(horizontal, vertical);
}

void Gui::selectAFigure() {

    std::string position;
    std::cout << "Select a figure by coordinates (A1): ";
    std::cin >> position;

    Player* current;
    if(this->chessField->getCurrentPlayer() == 1) {
        current = this->player1;
    } else {
        current = this->player2;
    }

    Figure* selectedFigure = getFigure(current, position);
    if(selectedFigure == nullptr) {
        std::cout << "You don't have a figure on this square!" << std::endl;
        return this->selectAFigure();
    } else {
        std::vector<Move*>* moves = this->moveController->getPseudoLegalMoves(selectedFigure);
        std::vector<Move*>* validMoves = this->checkController->validateMoves(moves);
        for (Move* m : *moves) {
            delete(m);
        }
        moves->clear();
        moves->shrink_to_fit();

        if(validMoves->empty()) {
            std::cout << "There are no moves for this figure!" << std::endl;
            return this->selectAFigure();
        } else {
            std::cout << selectedFigure->getName() << " selected at position " << position << "!" << std::endl;
        }

        // list all Moves
        if(this->settings->getShowPossibleMoves()) {
            std::cout << "Possible Moves: " << std::endl;

            int i = 1;
            for(Move* possible : *validMoves) {
                std::cout << i << ". ";
                if (Castle* c = dynamic_cast<Castle*>(possible)) {
                    if (c->getIsShort()) {
                        std::cout << "O-O";
                    } else {
                        std::cout << "O-O-O";
                    }
                } else {
                    std::cout << convertPos(possible->getEndVerticalPosition(), possible->getEndHorizontalPosition());
                }
                std::cout << std::endl;
                i++;
            }

            std::string choice;
            std::cout << "Enter your choice (1,2,...) or (S)elect another figure: ";
            std::cin >> choice;

            if(choice == "s" || choice == "S") {
                for (Move *m : *validMoves) {
                    delete(m);
                }
                validMoves->clear();
                validMoves->shrink_to_fit();
                return this->selectAFigure();
            } else {
                try {
                    int number = std::stoi(choice);
                    if (number-1 <= validMoves->size() && number > 0) {
                        Move* mv = validMoves->at(number - 1);
                        this->moveController->addMoveToHistory(mv);
                        mv->execute();
                        if (!this->settings->getResetUI()) {
                            std::cout << mv->getAsString() << std::endl;
                        }
                        for (Move* m : *validMoves) {
                            delete(m);
                        }
                        validMoves->clear();
                        validMoves->shrink_to_fit();
                    } else {
                        std::cout << "Please enter a valid number (1,2,...)!" << std::endl;
                        for (Move* m : *validMoves) {
                            delete(m);
                        }
                        validMoves->clear();
                        validMoves->shrink_to_fit();
                        return this->selectAFigure();
                    }
                } catch(...) {
                    std::cout << "This input is not valid!" << std::endl;
                    for (Move* m : *validMoves) {
                        delete(m);
                    }
                    validMoves->clear();
                    validMoves->shrink_to_fit();
                    return this->selectAFigure();
                }

                if(this->player1->timeIsOver()) {
                    std::cout << "Black won by timeout!" << std::endl;
                    this->checkmate = true;
                }
                if(this->player2->timeIsOver()) {
                    std::cout << "White won by timeout!" << std::endl;
                    this->checkmate = true;
                }

                //verify, if an player is in check
                if (chessField->getCurrentPlayer() == 1) {
                    std::vector<Figure*>* uncapturedFigures = this->player2->getUncapturedFigures();
                    std::vector<Move*>* nextPseudoLegalMoves = moveController->getPseudoLegalMovesForAll(uncapturedFigures);
                    std::vector<Move*>* notCheckMoves = checkController->validateMoves(nextPseudoLegalMoves);
                    if (notCheckMoves->empty()) {
                        std::vector<Player*> players {this->player2, this->player1};
                        if (checkController->isCheck(&players)) {
                            std::cout << "White won by checkmate!!!" << std::endl;
                        } else {
                            std::cout << "Draw by stalemate!!!" << std::endl;
                        }
                        this->checkmate = true;
                    } else {
                        std::vector<Player*>* players = new std::vector<Player*>();
                        players->push_back(this->player2);
                        players->push_back(this->player1);
                        if (checkController->isCheck(players)) {
                            std::cout << "Attention, Black: You are in check!" << std::endl;
                        }
                        players->clear();
                        players->shrink_to_fit();
                    }
                    for (Move* m : *nextPseudoLegalMoves) {
                        delete(m);
                    }
                    for (Move* m : *notCheckMoves) {
                        delete(m);
                    }
                    uncapturedFigures->clear();
                    uncapturedFigures->shrink_to_fit();
                    nextPseudoLegalMoves->clear();
                    nextPseudoLegalMoves->shrink_to_fit();
                    notCheckMoves->clear();
                    notCheckMoves->shrink_to_fit();
                } else {
                    std::vector<Figure*>* uncapturedFigures = this->player1->getUncapturedFigures();
                    std::vector<Move*>* nextPseudoLegalMoves = moveController->getPseudoLegalMovesForAll(uncapturedFigures);
                    std::vector<Move*>* notCheckMoves = checkController->validateMoves(nextPseudoLegalMoves);
                    if (notCheckMoves->empty()) {
                        std::vector<Player*> players {this->player1, this->player2};
                        if (checkController->isCheck(&players)) {
                            std::cout << "Black won by checkmate!!!" << std::endl;
                        } else {
                            std::cout << "Draw by stalemate!!!" << std::endl;
                        }
                        this->printChessField();
                        players.clear();
                        players.shrink_to_fit();
                        this->checkmate = true;
                    } else {
                        std::vector<Player*>* players = new std::vector<Player*>();
                        players->push_back(this->player1);
                        players->push_back(this->player2);
                        if (checkController->isCheck(players)) {
                            std::cout << "Attention, White: You are in check!" << std::endl;
                        }
                        players->clear();
                        players->shrink_to_fit();
                    }
                    for (Move* m : *nextPseudoLegalMoves) {
                        delete(m);
                    }
                    for (Move* m : *notCheckMoves) {
                        delete(m);
                    }
                    uncapturedFigures->clear();
                    uncapturedFigures->shrink_to_fit();
                    nextPseudoLegalMoves->clear();
                    nextPseudoLegalMoves->shrink_to_fit();
                    notCheckMoves->clear();
                    notCheckMoves->shrink_to_fit();
                }
                this->chessField->nextPlayer();
            }
        } else {
            std::string choice;
            std::cout << "Enter the end position (A1) or (S)elect another figure: ";
            std::cin >> choice;
            if(choice == "s" || choice == "S") {
                for (Move* m : *validMoves) {
                    delete(m);
                }
                validMoves->clear();
                validMoves->shrink_to_fit();
                return this->selectAFigure();
            } else {
                Move* mv = nullptr;
                if(validInput(choice)) {
                    for(Move* possible : *validMoves) {
                        if((convertHorizontal(choice) == possible->getEndHorizontalPosition()) && (convertVertical(choice) == possible->getEndVerticalPosition())) {
                            mv = possible;
                            break;
                        }
                    }
                }
                if(mv == nullptr) {
                    std::cout << "This is not a valid move!" << std::endl;
                    for (Move* m : *validMoves) {
                        delete(m);
                    }
                    validMoves->clear();
                    validMoves->shrink_to_fit();
                    return this->selectAFigure();
                } else {
                    this->moveController->addMoveToHistory(mv);
                    mv->execute();
                    if (!this->settings->getResetUI()) {
                        std::cout << mv->getAsString() << std::endl;
                    }
                    for (Move* m : *validMoves) {
                        delete(m);
                    }
                    validMoves->clear();
                    validMoves->shrink_to_fit();

                    if(this->player1->timeIsOver()) {
                        std::cout << "Black won by timeout!" << std::endl;
                        this->checkmate = true;
                    }
                    if(this->player2->timeIsOver()) {
                        std::cout << "White won by timeout!" << std::endl;
                        this->checkmate = true;
                    }

                    //verify, if any player is in check
                    if (chessField->getCurrentPlayer() == 1) {
                        std::vector<Figure*>* blackFigures = player2->getUncapturedFigures();
                        std::vector<Move*>* nextPseudoLegalMoves = moveController->getPseudoLegalMovesForAll(blackFigures);
                        std::vector<Move*>* notCheckMoves = checkController->validateMoves(nextPseudoLegalMoves);
                        if (notCheckMoves->empty()) {
                            std::vector<Player*> players {this->player2, this->player1};
                            if (checkController->isCheck(&players)) {
                                std::cout << "White won by checkmate!!!" << std::endl;
                            } else {
                                std::cout << "Draw by stalemate!!!" << std::endl;
                            }
                            this->printChessField();
                            std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
                            this->checkmate = true;
                            players.clear();
                            players.shrink_to_fit();
                        } else {
                            std::vector<Player*>* players = new std::vector<Player*>();
                            players->push_back(this->player2);
                            players->push_back(this->player1);
                            if (checkController->isCheck(players)) {
                                std::cout << "Attention, Black: You are in check!" << std::endl;
                            }
                            players->clear();
                            players->shrink_to_fit();
                        }
                        for (Move* m : *nextPseudoLegalMoves) {
                            delete(m);
                        }
                        for (Move* m : *notCheckMoves) {
                            delete(m);
                        }
                        nextPseudoLegalMoves->clear();
                        nextPseudoLegalMoves->shrink_to_fit();
                        notCheckMoves->clear();
                        notCheckMoves->shrink_to_fit();
                        blackFigures->clear();
                        blackFigures->shrink_to_fit();
                    } else {
                        std::vector<Figure*>* whiteFigures = player1->getUncapturedFigures();
                        std::vector<Move*>* nextPseudoLegalMoves = moveController->getPseudoLegalMovesForAll(whiteFigures);
                        std::vector<Move*>* notCheckMoves = checkController->validateMoves(nextPseudoLegalMoves);
                        if (notCheckMoves->empty()) {
                            std::vector<Player*> players {this->player1, this->player2};
                            if (checkController->isCheck(&players)) {
                                std::cout << "Black won by checkmate!!!" << std::endl;
                            } else {
                                std::cout << "Draw by stalemate!!!" << std::endl;
                            }
                            this->checkmate = true;
                            this->printChessField();
                            std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
                            players.clear();
                            players.shrink_to_fit();
                        } else { 
                            std::vector<Player*>* players = new std::vector<Player*>();
                            players->push_back(this->player1);
                            players->push_back(this->player2);
                            if (checkController->isCheck(players)) {
                                std::cout << "Attention, White: You are in check!" << std::endl;
                            }
                            players->clear();
                            players->shrink_to_fit();
                        }
                        for (Move* m : *nextPseudoLegalMoves) {
                            delete(m);
                        }
                        for (Move* m : *notCheckMoves) {
                            delete(m);
                        }
                        nextPseudoLegalMoves->clear();
                        nextPseudoLegalMoves->shrink_to_fit();
                        notCheckMoves->clear();
                        notCheckMoves->shrink_to_fit();
                        whiteFigures->clear();
                        whiteFigures->shrink_to_fit();
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

void Gui::clear() {
    std::string os;
    #ifdef _WIN32
        os = "win";
    #elif _WIN64
        os = "win";
    #elif __CYGWIN__
        os = "win";
    #elif unix
        os = "unix";
    #elif __unix
        os = "unix";
    #elif __unix__
        os = "unix";
    #elif __APPLE__
        os = "mac";
    #elif __MACH__
        os = "mac";
    #else
        os = "undefined";
    #endif

    if(os != "undefined") {
        if(os == "win") {
            std::system("cls");
        } else if(os == "unix") {
            //std::cout << "\x1B[2J\x1B[H";
            std::system("clear");
        } else {
            //std::cout << "\x1B[2J\x1B[H";
            std::system("clear");
        }
    }
}

Settings* Gui::getSettings() {
    return this->settings;
}

Gui::~Gui() {
    delete this->chessField;
    delete this->player1;
    delete this->player2;
    delete this->settings;
    delete this->moveController;
    delete this->checkController;
}