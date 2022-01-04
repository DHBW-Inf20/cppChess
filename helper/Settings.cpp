//
// Created by dj on 04.01.2022.
//

#include "Settings.hpp"

bool Settings::getShowIcons() {
    return this->showIcons;
}

void Settings::setShowIcons(bool showIcons) {
    this->showIcons = showIcons;
}

bool Settings::getShowPossibleMoves() {
    return this->showPossibleMoves;
}

void Settings::setShowPossibleMoves(bool showPossibleMoves) {
    this->showPossibleMoves = showPossibleMoves;
}