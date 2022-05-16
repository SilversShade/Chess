#include "Rook.h"

Rook::Rook(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::ROOK;
}

bool Rook::isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) {
    PieceColor colorAtDest = checkColorAt(xEnd, yEnd, pieces);
    if (colorAtDest == this->getColor())
        return false;
    int currRookPosX = this->getPosX();
    int currRookPosY = this->getPosY();
    if (this->getPosX() == xEnd && this->getPosY()>yEnd) {
        currRookPosY--;
        while (currRookPosY>yEnd) {
            colorAtDest = checkColorAt(currRookPosX, currRookPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currRookPosY--;
        }
        this->moved = true;
        return true;
    }
    if (this->getPosX() == xEnd && this->getPosY()<yEnd) {
        currRookPosY++;
        while (currRookPosY<yEnd) {
            colorAtDest = checkColorAt(currRookPosX, currRookPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currRookPosY++;
        }
        this->moved = true;
        return true;
    }
    if (this->getPosY() == yEnd && this->getPosX()<xEnd) {
        currRookPosX++;
        while (currRookPosX<xEnd) {
            colorAtDest = checkColorAt(currRookPosX, currRookPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currRookPosX++;
        }
        this->moved = true;
        return true;
    }
    if (this->getPosY() == yEnd && this->getPosX()>xEnd) {
        currRookPosX--;
        while (currRookPosX>xEnd) {
            colorAtDest = checkColorAt(currRookPosX, currRookPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currRookPosX--;
        }
        this->moved = true;
        return true;
    }
    return false;
}

bool Rook::hasMoved() const{
    return this->moved;
}
