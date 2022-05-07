#include "King.h"

King::King(PieceColor color, int x, int y) : Piece(color, x, y){
    this->type = PieceType::KING;
}
