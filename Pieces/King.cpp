#include "King.h"
#include <iostream>

King::King(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::KING;
}

//bool King::isSafeFromPawn(int x, int y, std::vector<Piece *> &pieces) {
//
//    return false;
//}
//
//bool King::isSafeFromKnight(int x, int y, std::vector<Piece *> &pieces) {
//    return false;
//}
//
//bool King::isSafeFromRook(int x, int y, std::vector<Piece *> &pieces) {
//    return false;
//}
//
//bool King::isSafeFromBishop(int x, int y, std::vector<Piece *> &pieces) {
//    return false;
//}
//
//bool King::isSafeFromKing(int x, int y, std::vector<Piece *> &pieces) {
//    return false;
//}
//
//bool King::isSafeFromQueen(int x, int y, std::vector<Piece *> &pieces) {
//    return false;
//}

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
    return true;
}
