//
// Created by dominic on 17.12.21.
//

#include "gui/Gui.cpp"

int main () {
    printWelcomeScreen();

    int main_setting = 0;
    do {
        main_setting = printMainMenu();
    } while (main_setting != -1);

    return 0;
}