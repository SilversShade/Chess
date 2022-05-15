#include "Knight.h"

Knight::Knight(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::KNIGHT;
}

bool Knight::isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) {
    PieceColor colorAtDest = checkColorAt(xEnd, yEnd, pieces);
    if (((std::abs(this->getPosX()-xEnd)==1 && std::abs(this->getPosY()-yEnd)==2) || (std::abs(this->getPosX()-xEnd)==2 && std::abs(this->getPosY()-yEnd)==1)) && colorAtDest != this->getColor())
        return true;
    return false;
}