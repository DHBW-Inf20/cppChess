//
// Created by dominic on 17.12.21.
//

#include <string>
#include "Gui.hpp"

int main () {
    Gui* gui = new Gui();

    gui->printWelcomeScreen();

    int main_setting;
    bool loaded = false;
    do {
        if(!loaded) {
            main_setting = gui->printMainMenu();
        } else {
            main_setting = 1;
        }
        switch (main_setting) {
            case 1:
                if(!loaded) {
                    gui->resetChessField();
                }
                loaded = false;
                do {
                    if (main_setting != 2 && main_setting != 4 && gui->getSettings()->getResetUI()) {
                        gui->clear();
                    }
                    gui->printChessField();
                    main_setting = gui->printMenuInTheGame();
                    if(main_setting != -1) {
                        if(main_setting == 1) {
                            gui->selectAFigure();
                        } else if(main_setting == 2) {
                            gui->getMaterialComparison();
                        } else if(main_setting == 3) {
                            gui->saveTheGame();
                            main_setting = -1;
                        } else if (main_setting == 4) {
                            gui->printLastMoves();
                        }
                    }
                } while (main_setting != -1 && !gui->isCheckmate());
                main_setting = 1;
                if (!gui->isCheckmate()) {
                    gui->clear();
                }
                break;
            case 2:
                gui->loadAGame();
                loaded = true;
                break;
            case 3:
                gui->printSettings();
                break;
        }
    } while (main_setting != -1);

    delete gui;
    return 0;
}