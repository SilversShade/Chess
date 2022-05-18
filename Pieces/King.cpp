#include "King.h"
#include "Rook.h"
#include <iostream>

King::King(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::KING;
}

bool King::isSafeAt(int x, int y, std::vector<Piece*> &pieces) {
    // check for the intersection with the enemy king
    std::vector<std::pair<int, int> > areaToCheck = {{x+1, y+1},{x+1, y-1}, {x-1, y+1}, {x-1, y-1},
                                                     {x, y+1},{x, y-1},{x+1, y},{x-1, y}};
    for (const auto& i:areaToCheck) {
        if (i.first<0 || i.first>7 || i.second<0 || i.second>7)
            continue;
        if (checkColorAt(i.first, i.second, pieces) != this->getColor() && checkTypeAt(i.first, i.second,pieces) == PieceType::KING)
            return false;
    }
    //check for the intersection with the enemy pawns
    areaToCheck = {{x+1,y+1}, {x-1,y+1}, {x-1,y-1}, {x+1,y-1}};
    for (const auto& i:areaToCheck)
        if ((i.second == y+1 ? this->getColor() == PieceColor::BLACK : this->getColor() == PieceColor::WHITE) && checkColorAt(i.first, i.second, pieces) != this->getColor() && checkTypeAt(i.first, i.second, pieces) == PieceType::PAWN)
            return false;
    //check for intersection with other pieces and "peaceful" pawn movements
    for (const auto& piece:pieces) {
        if (piece->getType() != PieceType::KING && piece->getColor() != this->getColor() && piece->isMoveValid(x, y, pieces)) {
            if (piece->getType() == PieceType::PAWN && piece->getPosX() == x)
                continue;
            return false;
        }
    }
    return true;
}

bool King::isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) {
    if (checkColorAt(xEnd, yEnd, pieces) == this->getColor())
        return false;
    // if moving farther than neighbouring cell and no castling then not valid
    if ((std::abs(xEnd-this->getPosX())>1 || std::abs(yEnd-this->getPosY())>1) && (this->getPosY() != yEnd || (std::abs(this->getPosX()-xEnd)!=2)))
        return false;
    // now need to check if destination cell is safe from check
    if (!isSafeAt(xEnd, yEnd, pieces))
        return false;
    //check if a default move was made
    if ((std::abs(xEnd-this->getPosX())<2 && std::abs(yEnd-this->getPosY())<2)) {
        this->moved = true;
        return true;
    }
    //check for short castling
    if (this->getPosY() == yEnd && !this->hasMoved() && xEnd==6) {
        for (const auto& piece:pieces) {
            if (piece->getPosX()-3 == this->getPosX() && piece->getPosY() == this->getPosY()) {
                if (Rook* r = dynamic_cast<Rook*>(piece)) {
                    if (!r->hasMoved()) {
                        if (isCellFreeAt(xEnd-1, yEnd, pieces) && isSafeAt(xEnd-1, yEnd, pieces) && isCellFreeAt(xEnd, yEnd, pieces) && isSafeAt(xEnd,yEnd,pieces) &&
                                isSafeAt(xEnd-2, yEnd, pieces)) {
                            r->setPosX(r->getPosX()-2);
                            r->getSprite()->setPosition(this->getSprite()->getPosition().x-Piece::pieceSize, this->getSprite()->getPosition().y);
                            this->moved = true;
                            return true;
                        }
                    }
                }
            }
        }
    }
    //check for long castling
    if (this->getPosY() == yEnd && !this->hasMoved() && xEnd==2) {
        for (const auto& piece:pieces) {
            if (piece->getPosX()+4 == this->getPosX() && piece->getPosY() == this->getPosY()) {
                if (Rook* r = dynamic_cast<Rook*>(piece)) {
                    if (!r->hasMoved()) {
                        if (isCellFreeAt(xEnd, yEnd, pieces) && isSafeAt(xEnd, yEnd, pieces) && isCellFreeAt(xEnd+1, yEnd, pieces) && isSafeAt(xEnd+1, yEnd, pieces) && isSafeAt(xEnd+2, yEnd, pieces)) {
                            r->setPosX(r->getPosX()+3);
                            r->getSprite()->setPosition(this->getSprite()->getPosition().x+Piece::pieceSize, this->getSprite()->getPosition().y);
                            this->moved = true;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool King::hasMoved() const{
    return this->moved;
}
