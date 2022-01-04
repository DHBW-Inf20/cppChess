//
// Created by dominic on 03.01.22.
//

#include <iostream>
#include <string>

#include "Gui.hpp"

Gui::Gui() {
    this->player1 = new Player(true);
    this->player2 = new Player(false);
    this->chessField = new ChessField(this->player1, this->player2);
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
        std::cout << "* Press q to quit the game!                        *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        std::cout << "Your input: ";
        std::cin >> temp_input;

        if(temp_input == "1") {
            settings->setShowIcons(!settings->getShowIcons());
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

Gui::~Gui() {
    delete this->chessField;
    delete this->player1;
    delete this->player2;
}