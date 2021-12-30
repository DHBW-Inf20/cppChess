//
// Created by dominic on 28.12.21.
//

#include "Player.hpp"

Player::Player(bool isWhite) {
    this->setIsWhite(isWhite);
    if (isWhite) {
        this->firstRook = new Rook("wR", 1, 1);
        this->firstKnight = new Knight("wN", 2, 1);
        this->firstBishop = new Bishop("wB", 3, 1);
        this->queen = new Queen("wQ", 4, 1);
        this->king = new King("wK", 5, 1);
        this->secondBishop = new Bishop("wB", 6, 1);
        this->secondKnight = new Knight("wN", 7, 1);
        this->secondRook = new Rook("wR", 8, 1);
        for (int i = 0; i < 8; i++) {
            this->pawns[i] = new Pawn("wP", i+1, 2);
        }
    } else {    //isWhite == false
        this->firstRook = new Rook("bR", 1, 8);
        this->firstKnight = new Knight("bN", 2, 8);
        this->firstBishop = new Bishop("bB", 3, 8);
        this->queen = new Queen("bQ", 4, 8);
        this->king = new King("bK", 5, 8);
        this->secondBishop = new Bishop("bB", 6, 8);
        this->secondKnight = new Knight("bN", 7, 8);
        this->secondRook = new Rook("bR", 8, 8);
        for (int i = 0; i < 8; i++) {
            this->pawns[i] = new Pawn("bP", i+1, 7);
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
