#include "Rook.h"

Rook::Rook(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::ROOK;
}
