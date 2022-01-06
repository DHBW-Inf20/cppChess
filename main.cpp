//
// Created by dominic on 17.12.21.
//

#include <string>
#include "gui/Gui.hpp"
#include "helper/Settings.hpp"

int main () {
    auto settings = new Settings();
    Gui* gui = new Gui();

    gui->printWelcomeScreen();

    int main_setting = 0;
    bool loaded = false;
    do {
        if(!loaded) {
            main_setting = gui->printMainMenu();
        } else {
            main_setting = 1;
        }
        switch (main_setting) {
            case 1:
                loaded = false;
                do {
                    gui->printChessField(settings);
                    main_setting = gui->printMenuInTheGame();
                    if(main_setting != -1) {
                        if(main_setting == 1) {
                            gui->selectAFigure(settings);
                        } else if(main_setting == 2) {
                            gui->getMaterialComparison();
                        } else if(main_setting == 3) {
                            gui->saveTheGame();
                            main_setting = -1;
                        }
                    }
                } while (main_setting != -1 && !gui->isCheckmate());
                main_setting = 1;
                break;
            case 2:
                gui->loadAGame(settings);
                loaded = true;
                break;
            case 3:
                gui->printSettings(settings);
                break;
        }
    } while (main_setting != -1);

    delete settings;
    delete gui;
    return 0;
}