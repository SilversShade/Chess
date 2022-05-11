#include "Pawn.h"
#include <iostream>

Pawn::Pawn(PieceColor color, int x, int y): Piece(color, x, y) {
    this->atStartingPos = true;
    this->type = PieceType::PAWN;
}

bool Pawn::isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) {
    // from initial position (2 or 1) forward
    if (this->atStartingPos && xEnd == this->getPosX() && (this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==1 || this->getPosY()-yEnd==2 : yEnd-this->getPosY()==1 || yEnd-this->getPosY()==2)) {
        if (!isCellFreeAt(xEnd, yEnd, pieces))
            return false;
        if ((this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==2 : yEnd-this->getPosY()==2) && !isCellFreeAt(xEnd,this->getColor()==PieceColor::WHITE ? yEnd+1 : yEnd-1,pieces))
            return false;
        this->atStartingPos = false;
        return true;
    }
    //common move (1 forward)
    if (this->getPosX() == xEnd && (this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==1 : yEnd-this->getPosY()==1)) {
        if (!isCellFreeAt(xEnd, yEnd, pieces))
            return false;
        return true;
    }
    //en passant

    // diagonal capture
    PieceColor colorAtDest = checkColorAt(xEnd, yEnd, pieces);
    if (colorAtDest == PieceColor::EMPTY)
        return false;
    if ((this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==1 : this->getPosY()-yEnd==-1) && (this->getPosX()-xEnd==1 || xEnd-this->getPosX()==1) && colorAtDest!=this->getColor())
        return true;
    return false;
}