
#ifndef YETANOTHERCHESSGAME_GUI_H
#define YETANOTHERCHESSGAME_GUI_H

#include "../model/Player.hpp"
#include "../model/ChessField.hpp"
#include "../helper/Settings.hpp"
#include "../model/MoveController.hpp"
#include "../model/CheckController.hpp"

class Gui {
    public:
        Gui();
        void printWelcomeScreen();
        int printMainMenu();
        int printMenuInTheGame();
        void printChessField(Settings* settings);
        void printSettings(Settings* settings);
        void getMaterialComparison();
        void selectAFigure(Settings* settings);
        bool isCheckmate();
        ~Gui();

    private:
        MoveController* moveController;
        CheckController* checkController;
        ChessField* chessField;
        Player* player1;
        Player* player2;
        bool checkmate;
};

#endif