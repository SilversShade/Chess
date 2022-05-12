#include "Pawn.h"

Pawn::Pawn(PieceColor color, int x, int y): Piece(color, x, y) {
    this->atStartingPos = true;
    this->type = PieceType::PAWN;
}

bool Pawn::enPassantConditionAt(int x, int y, std::vector<Piece*> &pieces) {
    for (const auto &piece:pieces) {
        if (piece->getPosX() == x && piece->getPosY() == y && piece->getColor() != this->getColor()) {
            if (Pawn* p = dynamic_cast<Pawn*>(piece)) {
                if (p->enPassantCondition) {
                    piece->getSprite()->setPosition(-100,-100);
                    piece->setPosX(-1);
                    piece->setPosY(-1);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Pawn::isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) {
    // from initial position (2 or 1) forward
    if (this->atStartingPos && xEnd == this->getPosX() && (this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==1 || this->getPosY()-yEnd==2 : yEnd-this->getPosY()==1 || yEnd-this->getPosY()==2)) {
        if (!isCellFreeAt(xEnd, yEnd, pieces))
            return false;
        if ((this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==2 : yEnd-this->getPosY()==2) && !isCellFreeAt(xEnd,this->getColor()==PieceColor::WHITE ? yEnd+1 : yEnd-1,pieces))
            return false;
        if (this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==2 : yEnd-this->getPosY()==2)
            this->enPassantCondition = true;
        this->atStartingPos = false;
        return true;
    }
    //common move (1 forward)
    if (this->getPosX() == xEnd && (this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==1 : yEnd-this->getPosY()==1)) {
        if (!isCellFreeAt(xEnd, yEnd, pieces))
            return false;
        this->enPassantCondition = false;
        return true;
    }
    //en passant
    if ((this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==1 : yEnd-this->getPosY()==1) && (this->getPosX()-xEnd==1 || xEnd-this->getPosX()==1)
        && enPassantConditionAt(xEnd, this->getColor() == PieceColor::WHITE ? yEnd+1 : yEnd-1, pieces))
            return true;
    // diagonal capture
    PieceColor colorAtDest = checkColorAt(xEnd, yEnd, pieces);
    if (colorAtDest == PieceColor::EMPTY)
        return false;
    if ((this->getColor() == PieceColor::WHITE ? this->getPosY()-yEnd==1 : this->getPosY()-yEnd==-1) && (this->getPosX()-xEnd==1 || xEnd-this->getPosX()==1) && colorAtDest!=this->getColor()) {
        this->enPassantCondition = false;
        return true;
    }
    return false;
}