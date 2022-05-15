#include "Bishop.h"

Bishop::Bishop(PieceColor color, int x, int y) : Piece(color, x, y) {
    this->type = PieceType::BISHOP;
}

bool Bishop::isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) {
    PieceColor colorAtDest = checkColorAt(xEnd, yEnd, pieces);
    if (colorAtDest == this->getColor())
        return false;
    int currBishopPosX = this->getPosX();
    int currBishopPosY = this->getPosY();
    if (this->getPosX()<xEnd && this->getPosY()<yEnd && this->getPosX()-xEnd == this->getPosY()-yEnd) {
        currBishopPosX++;
        currBishopPosY++;
        while(currBishopPosX<xEnd) {
            colorAtDest = checkColorAt(currBishopPosX, currBishopPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currBishopPosX++;
            currBishopPosY++;
        }
        return true;
    }

    if (this->getPosX()>xEnd && this->getPosY()>yEnd && this->getPosX()-xEnd == this->getPosY()-yEnd) {
        currBishopPosX--;
        currBishopPosY--;
        while(currBishopPosX>xEnd) {
            colorAtDest = checkColorAt(currBishopPosX, currBishopPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currBishopPosX--;
            currBishopPosY--;
        }
        return true;
    }

    if (this->getPosX()<xEnd && this->getPosY()>yEnd && xEnd-this->getPosX() == this->getPosY()-yEnd) {
        currBishopPosX++;
        currBishopPosY--;
        while(currBishopPosX<xEnd) {
            colorAtDest = checkColorAt(currBishopPosX, currBishopPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currBishopPosX++;
            currBishopPosY--;
        }
        return true;
    }

    if (this->getPosX()>xEnd && this->getPosY()<yEnd && this->getPosX()-xEnd == yEnd-this->getPosY()) {
        currBishopPosX--;
        currBishopPosY++;
        while(currBishopPosX>xEnd) {
            colorAtDest = checkColorAt(currBishopPosX, currBishopPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currBishopPosX--;
            currBishopPosY++;
        }
        return true;
    }

    return false;
}