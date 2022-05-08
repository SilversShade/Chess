#include "Knight.h"

Knight::Knight(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::KNIGHT;
}

bool Knight::isMoveValid(int xEnd, int yEnd) {
    return true;
}
