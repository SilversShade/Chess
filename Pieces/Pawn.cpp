#include "Pawn.h"

Pawn::Pawn(PieceColor color, int x, int y): Piece(color, x, y) {
    this->type = PieceType::PAWN;
}