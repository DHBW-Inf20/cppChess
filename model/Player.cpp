//
// Created by dominic on 28.12.21.
//

#include "Player.hpp"
#include <iostream>
#include <chrono>

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

void Player::setTimeMode(int timeMode) {
    this->timeMode = timeMode;
    this->numberOfMoves = 0;
    if(this->timeMode == 4) {
        this->time = 180000;
        this->extra_time = 2000;
        this->moves = -1;
        this->timeToFinish = -1;
    } else if(this->timeMode == 5) {
        this->time = 900000;
        this->extra_time = 10000;
        this->moves = -1;
        this->timeToFinish = -1;
    } else if(this->timeMode == 6) {
        this->time = 5400000;
        this->extra_time = 30000;
        this->moves = 40;
        this->timeToFinish = 1800000;
    } else {
        this->time = 0;
        this->extra_time = 0;
        this->moves = -1;
        this->timeToFinish = -1;
    }
    std::cout << this->time << this->extra_time << this->moves << this->timeToFinish << std::endl;
}

int Player::getTimeMode() {
    return this->timeMode;
}

void Player::start() {
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    this->startTime = ms.count();
}

void Player::stop() {
    if(this->timeMode != 3) {
        std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        long diff = ms.count() - this->startTime;

        if(this->moves != -1 && this->moves < this->numberOfMoves) {
            this->timeToFinish = this->timeToFinish - diff + this->extra_time;
        } else {
            this->time = this->time - diff + this->extra_time;
        }
        this->numberOfMoves++;
    }
}

long Player::getTime() {
    if(this->timeMode == 3) {
        return 0;
    } else {
        if(this->moves != -1 && this->moves < this->numberOfMoves) {
            return this->timeToFinish;
        } else {
            return this->time;
        }
    }
}

bool Player::timeIsOver() {
    if(this->timeMode == 3) {
        return false;
    } else {
        if(this->moves != -1 && this->moves < this->numberOfMoves) {
            return this->timeToFinish <= 0;
        } else {
            return this->time <= 0;
        }
    }
}