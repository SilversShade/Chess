#include "Queen.h"

Queen::Queen(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::QUEEN;
}

bool Queen::isMoveValid(int xEnd, int yEnd) {
    return true;
}