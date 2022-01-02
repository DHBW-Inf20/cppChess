#include "MoveController.hpp"

MoveController::MoveController(Player* whitePlayer, Player* blackPlayer) {
    this->whitePlayer = whitePlayer;
    this->blackPlayer = blackPlayer;
}

std::vector<Move*>* MoveController::getPseudoLegalMoves(Figure* figure) {
    //figure is object of Bishop
    if (Bishop* bishop = dynamic_cast<Bishop*>(figure)) {
        return getBishopMoves(bishop);
    } 
    //figure is object of King
    else if (King* king = dynamic_cast<King*>(figure)) {
        return getKingMoves(king);
    } 
    //figure is object of Knight
    else if (Knight* knight = dynamic_cast<Knight*>(figure)) {
        return getKnightMoves(knight);
    } 
    //figure is object of Pawn
    else if (Pawn* pawn = dynamic_cast<Pawn*>(figure)) {
        return getPawnMoves(pawn);
    } 
    //figure is object of Queen
    else if (Queen* queen = dynamic_cast<Queen*>(figure)) {
        return getQueenMoves(queen);
    }
    //figure is object of Knight
    else if (Rook* rook = dynamic_cast<Rook*>(figure)) {
        return getRookMoves(rook);
    }  
    //figure is something weird
    else {
        return nullptr;
    }
}

std::vector<Move*>* MoveController::getPseudoLegalMovesForAll(std::vector<Figure*>* figures) {
    return nullptr;
}

std::vector<Move*>* MoveController::getBishopMoves(Bishop* bishop) {
    int figHorizontalPosition = bishop->getHorizontalPosition();
    int figVerticalPosition = bishop->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;
    Player* owner;
    Player* opponent;

    if (bishop->getIsWhite()) {
        owner = whitePlayer;
        opponent = blackPlayer;
    } else {
        owner = blackPlayer;
        opponent = whitePlayer;
    }

    //Züge nach rechts oben
    int calcHorizontalPosition = figHorizontalPosition;
    int calcVerticalPosition = figVerticalPosition;
    bool breakPoint = false;
    while ((calcHorizontalPosition+1 <= 8) && (calcVerticalPosition+1 <=8) && !breakPoint) {
        calcHorizontalPosition++;
        calcVerticalPosition++;
        if (!owner->hasFigureOnSquare(calcHorizontalPosition, calcVerticalPosition)) {
            if (opponent->hasFigureOnSquare(calcHorizontalPosition, calcVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, calcVerticalPosition));
        } else {
            breakPoint = true;
        } 
    }

    //Züge nach links oben
    calcHorizontalPosition = figHorizontalPosition;
    calcVerticalPosition = figVerticalPosition;
    breakPoint = false;
    while ((calcHorizontalPosition-1 >= 1) && (calcVerticalPosition+1 <=8) && !breakPoint) {
        calcHorizontalPosition--;
        calcVerticalPosition++;
        if (!owner->hasFigureOnSquare(calcHorizontalPosition, calcVerticalPosition)) {
            if (opponent->hasFigureOnSquare(calcHorizontalPosition, calcVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, calcVerticalPosition));
        } else {
            breakPoint = true;
        } 
    }

    //Züge nach rechts unten
    calcHorizontalPosition = figHorizontalPosition;
    calcVerticalPosition = figVerticalPosition;
    breakPoint = false;
    while ((calcHorizontalPosition+1 <= 8) && (calcVerticalPosition-1 >= 1) && !breakPoint) {
        calcHorizontalPosition++;
        calcVerticalPosition--;
        if (!owner->hasFigureOnSquare(calcHorizontalPosition, calcVerticalPosition)) {
            if (opponent->hasFigureOnSquare(calcHorizontalPosition, calcVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, calcVerticalPosition));
        } else {
            breakPoint = true;
        } 
    }

    //Züge nach links unten
    calcHorizontalPosition = figHorizontalPosition;
    calcVerticalPosition = figVerticalPosition;
    breakPoint = false;
    while ((calcHorizontalPosition-1 >= 1) && (calcVerticalPosition-1 >= 1) && !breakPoint) {
        calcHorizontalPosition--;
        calcVerticalPosition--;
        if (!owner->hasFigureOnSquare(calcHorizontalPosition, calcVerticalPosition)) {
            if (opponent->hasFigureOnSquare(calcHorizontalPosition, calcVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, calcVerticalPosition));
        } else {
            breakPoint = true;
        } 
    }
    return pseudoLegalMoves;
}

std::vector<Move*>* MoveController::getKingMoves(King* king) {
    return nullptr;
}

std::vector<Move*>* MoveController::getKnightMoves(Knight* knight) {
    return nullptr;
}

std::vector<Move*>* MoveController::getPawnMoves(Pawn* pawn) {
    return nullptr;
}

std::vector<Move*>* MoveController::getQueenMoves(Queen* queen) {
    return nullptr;
}

std::vector<Move*>* MoveController::getRookMoves(Rook* rook) {
    return nullptr;
}