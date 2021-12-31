//
// Created by dominic on 28.12.21.
//

#include "Player.hpp"
#include <iostream>

Player::Player(bool isWhite) {
    this->setIsWhite(isWhite);
    if (isWhite) {
        this->firstRook = new Rook("wR", true, 1, 1);
        this->firstKnight = new Knight("wN", true, 2, 1);
        this->firstBishop = new Bishop("wB", true, 3, 1);
        this->queen = new Queen("wQ", true, 4, 1);
        this->king = new King("wK", true, 5, 1);
        this->secondBishop = new Bishop("wB", true, 6, 1);
        this->secondKnight = new Knight("wN", true, 7, 1);
        this->secondRook = new Rook("wR", true, 8, 1);
        for (int i = 1; i <= 8; i++) {
            this->pawns->push_back(new Pawn("wP", true, i, 2));
        }
    } else {    //isWhite == false
        this->firstRook = new Rook("bR", false, 1, 8);
        this->firstKnight = new Knight("bN", false, 2, 8);
        this->firstBishop = new Bishop("bB", false, 3, 8);
        this->queen = new Queen("bQ", false, 4, 8);
        this->king = new King("bK", false, 5, 8);
        this->secondBishop = new Bishop("bB", false, 6, 8);
        this->secondKnight = new Knight("bN", false, 7, 8);
        this->secondRook = new Rook("bR", false, 8, 8);
        for (int i = 1; i <= 8; i++) {
            this->pawns->push_back(new Pawn("bP", false, i, 7));
        }
    } 
}

void Player::setIsWhite(bool isWhite) {
    this->isWhite = isWhite;
}

std::vector<Figure*>* Player::getAllFigures() {
    std::vector<Figure*> *figures = new std::vector<Figure*>;
    figures -> push_back(this->firstRook);
    figures -> push_back(this->firstKnight);
    figures -> push_back(this->firstBishop);
    figures -> push_back(this->queen);
    figures -> push_back(this->king);
    figures -> push_back(this->secondBishop);
    figures -> push_back(this->secondKnight);
    figures -> push_back(this->secondRook);
    for (int i = 0; i < this->pawns->size(); i++) {
        figures->push_back(this->pawns->at(i));
    }
    return figures;
}

std::vector<Figure*>* Player::getUncapturedFigures() {
    std::vector<Figure*>* allFigures = this->getAllFigures();
    std::vector<Figure*>* uncapturedFigures = new std::vector<Figure*>;
    for (int i = 0; i < allFigures->size(); i++) {
        Figure* f = allFigures->at(i);
        if (f->getNotCaptured()) {
            uncapturedFigures->push_back(f);
        }
    }
    return uncapturedFigures;
}

bool Player::hasFigureOnSquare(int horizontalPosition, int verticalPosition) {
    std::vector<Figure*>* uncapturedFigures = this->getUncapturedFigures();
    bool foundFigure = false;
    for (int i = 0; i < uncapturedFigures->size(); i++) {
        Figure* f = uncapturedFigures->at(i);
        if ((f->getHorizontalPosition() == horizontalPosition) && (f->getVerticalPosition() == verticalPosition)) {
            foundFigure = true;
        }
    }
    return foundFigure;
}