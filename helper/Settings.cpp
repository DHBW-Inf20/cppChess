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

bool Settings::getResetUI() {
    return this->resetUI;
}

void Settings::setResetUI(bool resetUI) {
    this->resetUI = resetUI;
}

int Settings::getTimeMode() {
    return this->timeMode;
}

void Settings::setTimeMode(int timeMode) {
    this->timeMode = timeMode;
}