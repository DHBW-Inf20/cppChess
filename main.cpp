//
// Created by dominic on 17.12.21.
//

#include "gui/Gui.cpp"
#include "helper/Settings.hpp"

int main () {
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

                    }
                } while (main_setting != -1);
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