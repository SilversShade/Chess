#include "Rook.h"

Rook::Rook(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::ROOK;
}

bool Rook::isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) {
    return true;
}
