
#ifndef YETANOTHERCHESSGAME_GUI_H
#define YETANOTHERCHESSGAME_GUI_H

#include "../model/Player.hpp"
#include "../model/ChessField.hpp"
#include "../helper/Settings.hpp"

class Gui {
    public:
        Gui();
        void printWelcomeScreen();
        int printMainMenu();
        int printMenuInTheGame();
        void printChessField(Settings* settings);
        void printSettings(Settings* settings);
        ~Gui();

    private:
        ChessField* chessField;
        Player* player1;
        Player* player2;
};

#endif