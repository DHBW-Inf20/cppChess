//
// Created by dominic on 17.12.21.
//

#include "gui/Gui.hpp"
#include "helper/Settings.hpp"

#include <Windows.h>

int main () {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    auto settings = new Settings();
    Gui* gui = new Gui();

    gui->printWelcomeScreen();

    int main_setting = 0;
    do {
        main_setting = gui->printMainMenu();
        switch (main_setting) {
            case 1:
                do {
                    gui->printChessField(settings);
                    main_setting = gui->printMenuInTheGame();
                    if(main_setting != -1) {
                        if(main_setting == 1) {
                            gui->selectAFigure(settings);
                        } else if(main_setting == 2) {
                            gui->getMaterialComparison();
                        }
                    }
                } while (main_setting != -1);
                main_setting = 1;
                break;
            case 2:
                gui->printSettings(settings);
                break;
        }
    } while (main_setting != -1);

    delete settings;
    delete gui;
    return 0;
}