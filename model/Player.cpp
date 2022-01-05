//
// Created by dominic on 28.12.21.
//

#include "Player.hpp"
#include <iostream>

Player::Player(bool isWhite) {
    this->setIsWhite(isWhite);
    if (isWhite) {
        this->figures->push_back(new Rook("wR", true, 1, 1));
        this->figures->push_back(new Knight("wN", true, 2, 1));
        this->figures->push_back(new Bishop("wB", true, 3, 1));
        this->figures->push_back(new Queen("wQ", true, 4, 1));
        this->figures->push_back(new King("wK", true, 5, 1));
        this->figures->push_back(new Bishop("wB", true, 6, 1));
        this->figures->push_back(new Knight("wN", true, 7, 1));
        this->figures->push_back(new Rook("wR", true, 8, 1));
        for (int i = 1; i <= 8; i++) {
            this->figures->push_back(new Pawn("wP", true, i, 2));
        }
    } else {    //isWhite == false
        this->figures->push_back(new Rook("bR", false, 1, 8));
        this->figures->push_back(new Knight("bN", false, 2, 8));
        this->figures->push_back(new Bishop("bB", false, 3, 8));
        this->figures->push_back(new Queen("bQ", false, 4, 8));
        this->figures->push_back(new King("bK", false, 5, 8));
        this->figures->push_back(new Bishop("bB", false, 6, 8));
        this->figures->push_back(new Knight("bN", false, 7, 8));
        this->figures->push_back(new Rook("bR", false, 8, 8));
        for (int i = 1; i <= 8; i++) {
            this->figures->push_back(new Pawn("bP", false, i, 7));
        }
    } 
}

Player::Player(bool isWhite, std::vector<Figure*>* inputFigures) {
    this->isWhite = isWhite;
    for (Figure* fig : *inputFigures) {
        this->figures->push_back(fig);
    }
}

void Player::setIsWhite(bool isWhite) {
    this->isWhite = isWhite;
}

bool Player::getIsWhite() {
    return this->isWhite;
}

std::vector<Figure*>* Player::getAllFigures() {
    return figures;
}

std::vector<Figure*>* Player::getUncapturedFigures() {
    std::vector<Figure*>* uncapturedFigures = new std::vector<Figure*>;
    for (int i = 0; i < figures->size(); i++) {
        Figure* f = figures->at(i);
        if (f->getNotCaptured()) {
            uncapturedFigures->push_back(f);
        }
    }
    return uncapturedFigures;
}

Figure* Player::hasFigureOnSquare(int horizontalPosition, int verticalPosition) {
    std::vector<Figure*>* uncapturedFigures = this->getUncapturedFigures();
    for (int i = 0; i < uncapturedFigures->size(); i++) {
        Figure* f = uncapturedFigures->at(i);
        if ((f->getHorizontalPosition() == horizontalPosition) && (f->getVerticalPosition() == verticalPosition)) {
            return f;
        }
    }
    return nullptr;
}

Player::~Player() {
    for (Figure* figure: *figures) {
        delete(figure);
    }
}

Figure* Player::getPieceAtPosition(int horizontal, int vertical) {
    std::vector<Figure*>* allFigures = this->getAllFigures();
    for(Figure* figure : *allFigures) {
        if(figure->getNotCaptured() && figure->getHorizontalPosition() == horizontal && figure->getVerticalPosition() == vertical) {
            return figure;
        }
    }
    return nullptr;
}

int Player::getUncapturedMaterialValue() {
    std::vector<Figure*>* uncapturedFigures = this->getUncapturedFigures();
    int sumValue = 0;
    for (Figure* figure : *uncapturedFigures) {
        sumValue += figure->getValue();
    }
    return sumValue;
}

Player* Player::clonePlayer() {
    std::vector<Figure*>* clonedFigures = new std::vector<Figure*>();
    for (Figure* f : *figures) {
        clonedFigures->push_back(f->cloneFigure());
    }
    if (clonedFigures->size() == 16) {
        Player* clonedPlayer = new Player(this->isWhite, clonedFigures);
        return clonedPlayer;
    } else {
        std::cout << "An error occured...";
        return nullptr;
    }
}

King* Player::getKing() {
    Figure* kingFigure = this->figures->at(4);
    if (King* king = dynamic_cast<King*>(kingFigure)) {
        return king;
    } else {
        return nullptr;
    }
}