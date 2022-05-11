#include "Bishop.h"

Bishop::Bishop(PieceColor color, int x, int y) : Piece(color, x, y) {
    this->type = PieceType::BISHOP;
}

bool Bishop::isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) {
    return true;
}