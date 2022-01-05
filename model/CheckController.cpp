//
// Created by jannik on 05.01.22.
//

#include "CheckController.hpp"

CheckController::CheckController(Player* whitePlayer, Player* blackPlayer) {
    this->whitePlayer = whitePlayer;
    this->blackPlayer = blackPlayer;
}

CheckController::~CheckController() {}

Player* CheckController::getWhitePlayer() {
    return this->whitePlayer;
}

Player* CheckController::getBlackPlayer() {
    return this->blackPlayer;
}

std::vector<Player*>* CheckController::getClonedPositionAfterMove(Move* move) {
    Player* clonedWhitePlayer = whitePlayer->clonePlayer();
    Player* clonedBlackPlayer = blackPlayer->clonePlayer();

    std::vector<Figure*>* clonedWhiteFigures = clonedWhitePlayer->getUncapturedFigures();
    std::vector<Figure*>* clonedBlackFigures = clonedBlackPlayer->getUncapturedFigures();

    if (move->getFigure()->getIsWhite()) {
        Figure* figure = clonedWhitePlayer->getPieceAtPosition(move->getStartHorizontalPosition(), move->getStartVerticalPosition());
        figure->setHorizontalPosition(move->getEndHorizontalPosition());
        figure->setVerticalPosition(move->getEndVerticalPosition());
        
        if (Capture* capture = dynamic_cast<Capture*>(move)) {
            Figure* capturedFigure = clonedBlackPlayer->getPieceAtPosition(capture->getCapturedFigure()->getHorizontalPosition(), capture->getCapturedFigure()->getVerticalPosition());
            capturedFigure->setNotCaptured(false);
        }
    } else {
        Figure* figure = clonedBlackPlayer->getPieceAtPosition(move->getStartHorizontalPosition(), move->getStartVerticalPosition());
        figure->setHorizontalPosition(move->getEndHorizontalPosition());
        figure->setVerticalPosition(move->getEndVerticalPosition());

        if (Capture* capture = dynamic_cast<Capture*>(move)) {
            Figure* capturedFigure = clonedWhitePlayer->getPieceAtPosition(capture->getCapturedFigure()->getHorizontalPosition(), capture->getCapturedFigure()->getVerticalPosition());
            capturedFigure->setNotCaptured(false);
        }
    }

    std::vector<Player*>* clonedPlayers = new std::vector<Player*>();
    clonedPlayers->push_back(clonedWhitePlayer);
    clonedPlayers->push_back(clonedBlackPlayer);
    return clonedPlayers;
}

std::vector<Move*>* CheckController::validateMoves(std::vector<Move*>* moves) {
    std::vector<Move*>* validMoves = new std::vector<Move*>();
    for (Move* move : *moves) {
        std::vector<Player*>* clonedPosition = this->getClonedPositionAfterMove(move);
        if (!this->isCheck(clonedPosition)) {
            validMoves->push_back(move);
        }
        for (Player* p: *clonedPosition) {
            delete(p);
        }
    }
    return validMoves;
}

bool CheckController::isCheck(std::vector<Player*>* players) {
    return false;
}



