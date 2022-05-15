#include "Queen.h"

Queen::Queen(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::QUEEN;
}

bool Queen::isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) {
    PieceColor colorAtDest = checkColorAt(xEnd, yEnd, pieces);
    if (colorAtDest == this->getColor())
        return false;
    int currQueenPosX = this->getPosX();
    int currQueenPosY = this->getPosY();
    if (this->getPosX()<xEnd && this->getPosY()<yEnd && this->getPosX()-xEnd == this->getPosY()-yEnd) {
        currQueenPosX++;
        currQueenPosY++;
        while(currQueenPosX < xEnd) {
            colorAtDest = checkColorAt(currQueenPosX, currQueenPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currQueenPosX++;
            currQueenPosY++;
        }
        return true;
    }

    if (this->getPosX()>xEnd && this->getPosY()>yEnd && this->getPosX()-xEnd == this->getPosY()-yEnd) {
        currQueenPosX--;
        currQueenPosY--;
        while(currQueenPosX > xEnd) {
            colorAtDest = checkColorAt(currQueenPosX, currQueenPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currQueenPosX--;
            currQueenPosY--;
        }
        return true;
    }

    if (this->getPosX()<xEnd && this->getPosY()>yEnd && xEnd-this->getPosX() == this->getPosY()-yEnd) {
        currQueenPosX++;
        currQueenPosY--;
        while(currQueenPosX < xEnd) {
            colorAtDest = checkColorAt(currQueenPosX, currQueenPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currQueenPosX++;
            currQueenPosY--;
        }
        return true;
    }

    if (this->getPosX()>xEnd && this->getPosY()<yEnd && this->getPosX()-xEnd == yEnd-this->getPosY()) {
        currQueenPosX--;
        currQueenPosY++;
        while(currQueenPosX > xEnd) {
            colorAtDest = checkColorAt(currQueenPosX, currQueenPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currQueenPosX--;
            currQueenPosY++;
        }
        return true;
    }

    if (this->getPosX() == xEnd && this->getPosY()>yEnd) {
        currQueenPosY--;
        while (currQueenPosY>yEnd) {
            colorAtDest = checkColorAt(currQueenPosX, currQueenPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currQueenPosY--;
        }
        return true;
    }
    if (this->getPosX() == xEnd && this->getPosY()<yEnd) {
        currQueenPosY++;
        while (currQueenPosY<yEnd) {
            colorAtDest = checkColorAt(currQueenPosX, currQueenPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currQueenPosY++;
        }
        return true;
    }
    if (this->getPosY() == yEnd && this->getPosX()<xEnd) {
        currQueenPosX++;
        while (currQueenPosX<xEnd) {
            colorAtDest = checkColorAt(currQueenPosX, currQueenPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currQueenPosX++;
        }
        return true;
    }
    if (this->getPosY() == yEnd && this->getPosX()>xEnd) {
        currQueenPosX--;
        while (currQueenPosX>xEnd) {
            colorAtDest = checkColorAt(currQueenPosX, currQueenPosY, pieces);
            if (colorAtDest != PieceColor::EMPTY)
                return false;
            currQueenPosX--;
        }
        return true;
    }
    return false;
}