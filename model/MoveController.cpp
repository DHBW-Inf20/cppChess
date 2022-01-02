//
// Created by jannik on 02.01.22.
//

#include "MoveController.hpp"

MoveController::MoveController(Player* whitePlayer, Player* blackPlayer) {
    this->whitePlayer = whitePlayer;
    this->blackPlayer = blackPlayer;
}

void MoveController::addMoveToHistory(Move* move) {
    this->moveHistory->push_back(move);
}

Move* MoveController::getMoveAtIndex(int index) {
    return this->moveHistory->at(index);
}

Move* MoveController::getLastMove() {
    return this->moveHistory->at(this->moveHistory->size()-1);
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
    int figHorizontalPosition = king->getHorizontalPosition();
    int figVerticalPosition = king->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;
    
    Player* owner;
    Player* opponent;
    if (king->getIsWhite()) {
        owner = whitePlayer;
        opponent = blackPlayer;
    } else {
        owner = blackPlayer;
        opponent = whitePlayer;
    }
    
    //rechts
    if (figHorizontalPosition+1 <= 8) {
        //rechts oben
        if (figVerticalPosition+1 <= 8 && !owner->hasFigureOnSquare(figHorizontalPosition+1, figVerticalPosition+1)) {
                pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition+1));
        }
        //rechts mittig
        if (!owner->hasFigureOnSquare(figHorizontalPosition+1, figVerticalPosition)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition));
        }
        //rechts unten
        if (figVerticalPosition-1 >= 1 && !owner->hasFigureOnSquare(figHorizontalPosition+1, figVerticalPosition-1)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition-1));
        }
    }

    //links
    if (figHorizontalPosition-1 >= 1) {
        //links oben
        if (figVerticalPosition+1 <= 8 && !owner->hasFigureOnSquare(figHorizontalPosition-1, figVerticalPosition+1)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition+1));
        }
        //links mittig
        if (!owner->hasFigureOnSquare(figHorizontalPosition-1, figVerticalPosition)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition));
        }
        //links unten
        if (figVerticalPosition-1 >= 1 && !owner->hasFigureOnSquare(figHorizontalPosition-1, figVerticalPosition-1)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition-1));
        }
    }

    //oben
    if (figVerticalPosition+1 <= 8 && !owner->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition+1)) {
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition+1));
    }

    //unten
    if (figVerticalPosition-1 >= 1 && !owner->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition-1)) {
        pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition-1));
    }

    return pseudoLegalMoves;
}

std::vector<Move*>* MoveController::getKnightMoves(Knight* knight) {
    int figHorizontalPosition = knight->getHorizontalPosition();
    int figVerticalPosition = knight->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;

    Player* owner;
    Player* opponent;

    if (knight->getIsWhite()) {
        owner = whitePlayer;
        opponent = blackPlayer;
    } else {
        owner = blackPlayer;
        opponent = whitePlayer;
    }

    //Züge nach rechts
    if (figHorizontalPosition+2 <= 8) {
        if (figVerticalPosition+1 <= 8) {
            if (!owner->hasFigureOnSquare(figHorizontalPosition+2, figVerticalPosition+1)) {
                pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+2, figVerticalPosition+1));
            }
        }
        if (figVerticalPosition-1 >= 1) {
            if (!owner->hasFigureOnSquare(figHorizontalPosition+2, figVerticalPosition-1)) {
                pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+2, figVerticalPosition-1));
            }
        }
    }

    //Züge nach links
    if (figHorizontalPosition-2 >= 1) {
        if (figVerticalPosition+1 <= 8) {
            if (!owner->hasFigureOnSquare(figHorizontalPosition-2, figVerticalPosition+1)) {
                pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-2, figVerticalPosition+1));
            }
        }
        if (figVerticalPosition-1 >= 1) {
            if (!owner->hasFigureOnSquare(figHorizontalPosition-2, figVerticalPosition-1)) {
                pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-2, figVerticalPosition-1));
            }
        }
    }

    //Züge nach oben
    if (figVerticalPosition+2 <= 8) {
        if (figHorizontalPosition+1 <= 8) {
            if (!owner->hasFigureOnSquare(figHorizontalPosition+1, figVerticalPosition+2)) {
                pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition+2));
            }
        }
        if (figHorizontalPosition-1 >= 1) {
            if (!owner->hasFigureOnSquare(figHorizontalPosition-1, figVerticalPosition+2)) {
                pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition+2));
            }
        }
    }

    //Züge nach unten
    if (figVerticalPosition-2 >= 1) {
        if (figHorizontalPosition+1 <= 8) {
            if (!owner->hasFigureOnSquare(figHorizontalPosition+1, figVerticalPosition-2)) {
                pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition-2));
            }
        }
        if (figHorizontalPosition-1 >= 1) {
            if (!owner->hasFigureOnSquare(figHorizontalPosition-1, figVerticalPosition-2)) {
                pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition-2));
            }
        }
    }
    return pseudoLegalMoves;
}

std::vector<Move*>* MoveController::getPawnMoves(Pawn* pawn) {
    int figHorizontalPosition = pawn->getHorizontalPosition();
    int figVerticalPosition = pawn->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;

    Player* owner;
    Player* opponent;

    if (pawn->getIsWhite()) {
        owner = whitePlayer;
        opponent = blackPlayer;
    } else {
        owner = blackPlayer;
        opponent = whitePlayer;
    }

    if (pawn->getIsWhite()) {
        //normaler Zug: eins vorwärts
        if (!owner->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition+1) && !opponent->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition+1)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition+1));
        }
        //noch nicht gezogen: zwei vorwärts
        if (pawn->getMoveCounter() == 0 && !owner->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition+2) && !opponent->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition+2)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition+2));
        }
        //gegnerische Figur (diagonal links) schlagen
        if (opponent->hasFigureOnSquare(figHorizontalPosition-1, figVerticalPosition+1)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition+1));
        }
        //gegnerische Figur (diagonal rechts) schlagen
        if (opponent->hasFigureOnSquare(figHorizontalPosition+1, figVerticalPosition+1)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition+1));
        }

    } else {    //this->getIsWhite() == false
        //normaler Zug: eins vorwärts
        if (!owner->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition-1) && !opponent->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition-1)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition-1));
        }
        //noch nicht gezogen: zwei vorwärts
        if (pawn->getMoveCounter() == 0 && !owner->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition-2) && !opponent->hasFigureOnSquare(figHorizontalPosition, figVerticalPosition-2)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, figVerticalPosition-2));
        }
        //gegnerische Figur (diagonal links) schlagen
        if (opponent->hasFigureOnSquare(figHorizontalPosition-1, figVerticalPosition-1)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition-1, figVerticalPosition-1));
        }
        //gegnerische Figur (diagonal rechts) schlagen
        if (opponent->hasFigureOnSquare(figHorizontalPosition+1, figVerticalPosition-1)) {
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition+1, figVerticalPosition-1));
        }
    }
    return pseudoLegalMoves;
}

std::vector<Move*>* MoveController::getQueenMoves(Queen* queen) {
    int figHorizontalPosition = queen->getHorizontalPosition();
    int figVerticalPosition = queen->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;
    Player* owner;
    Player* opponent;

    if (queen->getIsWhite()) {
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

    //Züge nach rechts
    calcHorizontalPosition = figHorizontalPosition;
    breakPoint = false;
    while ((calcHorizontalPosition+1) <= 8 && !breakPoint) {
        calcHorizontalPosition++;
        if (!owner->hasFigureOnSquare(calcHorizontalPosition, figVerticalPosition)) {
            if (opponent->hasFigureOnSquare(calcHorizontalPosition, figVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, figVerticalPosition));
        } else {
            breakPoint = true;
        }
    }

    //Züge nach links
    calcHorizontalPosition = figHorizontalPosition;
    breakPoint = false;
    while ((calcHorizontalPosition-1) >= 1 && !breakPoint) {
        calcHorizontalPosition--;
        if (!owner->hasFigureOnSquare(calcHorizontalPosition, figVerticalPosition)) {
            if (opponent->hasFigureOnSquare(calcHorizontalPosition, figVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, figVerticalPosition));
        } else {
            breakPoint = true;
        }
    }

    //Züge nach oben
    calcVerticalPosition = figVerticalPosition;
    breakPoint = false;
    while ((calcVerticalPosition+1) <= 8 && !breakPoint) {
        calcVerticalPosition++;
        if (!owner->hasFigureOnSquare(figHorizontalPosition, calcVerticalPosition)) {
            if (opponent->hasFigureOnSquare(figHorizontalPosition, calcVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, calcVerticalPosition));
        } else {
            breakPoint = true;
        }
    }

     //Züge nach unten
    calcVerticalPosition = figVerticalPosition;
    breakPoint = false;
    while ((calcVerticalPosition-1) >= 1 && !breakPoint) {
        calcVerticalPosition--;
        if (!owner->hasFigureOnSquare(figHorizontalPosition, calcVerticalPosition)) {
            if (opponent->hasFigureOnSquare(figHorizontalPosition, calcVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, calcVerticalPosition));
        } else {
            breakPoint = true;
        }
    }
    return pseudoLegalMoves;
}

std::vector<Move*>* MoveController::getRookMoves(Rook* rook) {
    int figHorizontalPosition = rook->getHorizontalPosition();
    int figVerticalPosition = rook->getVerticalPosition();
    std::vector<Move*>* pseudoLegalMoves = new std::vector<Move*>;
    Player* owner;
    Player* opponent;

    if (rook->getIsWhite()) {
        owner = whitePlayer;
        opponent = blackPlayer;
    } else {
        owner = blackPlayer;
        opponent = whitePlayer;
    }
    
    //Züge nach rechts
    int calcHorizontalPosition = figHorizontalPosition;
    bool breakPoint = false;
    while ((calcHorizontalPosition+1) <= 8 && !breakPoint) {
        calcHorizontalPosition++;
        if (!owner->hasFigureOnSquare(calcHorizontalPosition, figVerticalPosition)) {
            if (opponent->hasFigureOnSquare(calcHorizontalPosition, figVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, figVerticalPosition));
        } else {
            breakPoint = true;
        }
    }

    //Züge nach links
    calcHorizontalPosition = figHorizontalPosition;
    breakPoint = false;
    while ((calcHorizontalPosition-1) >= 1 && !breakPoint) {
        calcHorizontalPosition--;
        if (!owner->hasFigureOnSquare(calcHorizontalPosition, figVerticalPosition)) {
            if (opponent->hasFigureOnSquare(calcHorizontalPosition, figVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, calcHorizontalPosition, figVerticalPosition));
        } else {
            breakPoint = true;
        }
    }

    //Züge nach oben
    int calcVerticalPosition = figVerticalPosition;
    breakPoint = false;
    while ((calcVerticalPosition+1) <= 8 && !breakPoint) {
        calcVerticalPosition++;
        if (!owner->hasFigureOnSquare(figHorizontalPosition, calcVerticalPosition)) {
            if (opponent->hasFigureOnSquare(figHorizontalPosition, calcVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, calcVerticalPosition));
        } else {
            breakPoint = true;
        }
    }

     //Züge nach unten
    calcVerticalPosition = figVerticalPosition;
    breakPoint = false;
    while ((calcVerticalPosition-1) >= 1 && !breakPoint) {
        calcVerticalPosition--;
        if (!owner->hasFigureOnSquare(figHorizontalPosition, calcVerticalPosition)) {
            if (opponent->hasFigureOnSquare(figHorizontalPosition, calcVerticalPosition)) {
                breakPoint = true;
            }
            pseudoLegalMoves->push_back(new Move(figHorizontalPosition, figVerticalPosition, figHorizontalPosition, calcVerticalPosition));
        } else {
            breakPoint = true;
        }
    }
    return pseudoLegalMoves;
}