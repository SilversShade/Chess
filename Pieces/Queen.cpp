#include "Queen.h"

Queen::Queen(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::QUEEN;
}
