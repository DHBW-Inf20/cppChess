//
// Created by dominic on 28.12.21.
//

#include "Player.hpp"

Player::Player(bool isWhite) {
    this->setIsWhite(isWhite);
    if (isWhite) {
        this->firstRook = new Rook("wR", 1);
        this->firstKnight = new Knight("wN", 2);
        this->firstBishop = new Bishop("wB", 3);
        this->queen = new Queen("wQ", 4);
        this->king = new King("wK", 5);
        this->secondBishop = new Bishop("wB", 6);
        this->secondKnight = new Knight("wN", 7);
        this->secondRook = new Rook("wR", 8);
        for (int i = 0; i < 8; i++) {
            this->pawns[i] = new Pawn("wP", i+9);
        }
    } else {    //isWhite == false
        this->firstRook = new Rook("bR", 57);
        this->firstKnight = new Knight("bN", 58);
        this->firstBishop = new Bishop("bB", 59);
        this->queen = new Queen("bQ", 60);
        this->king = new King("bK", 61);
        this->secondBishop = new Bishop("bB", 62);
        this->secondKnight = new Knight("bN", 63);
        this->secondRook = new Rook("bR", 64);
        for (int i = 0; i < 8; i++) {
            this->pawns[i] = new Pawn("bP", i+49);
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

std::vector<Figure*>* Player::getUncapturedFigures(std::vector<Figure*>& allFigures) {
    std::vector<Figure*>* uncapturedFigures = new std::vector<Figure*>;
    for (Figure* f: allFigures) {
        if (f->getNotCaptured()) {
            uncapturedFigures->push_back(f);
        }
    }
    return uncapturedFigures;
}